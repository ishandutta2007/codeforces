#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1005;

int a[N];
int n, ans1 = 1, ans2;

int calc(int t) {
	int sum = 0;
	for(register int i = 1; i <= n; i++) {
		if(a[i] == t) continue;
		if(a[i] > t) sum += a[i] - t - 1;
		if(a[i] < t) sum += t - a[i] - 1;
	}
	return sum;
}

int main() {
	read(n);
	for(register int i = 1; i <= n; i++) read(a[i]);
	ans2 = calc(1);
	for(register int i = 2; i <= 1000; i++) {
		int now = calc(i);
		if(now < ans2) {
			ans2 = now;
			ans1 = i;
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}