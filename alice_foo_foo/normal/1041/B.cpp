#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i++)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
    while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
    f *= fu;
}

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long a, b, c, d;

int main() {
	cin >> a >> b >> c >> d;
	long long t = gcd(c, d);
	c /= t; d /= t;
	cout << min(a / c, b / d) << endl;
	return 0;
}