#include <bits/stdc++.h>
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

const int N = 2e5 + 5;

ll a[N], b[N], w[N], m, ans;
int n;

int main() {
	read(n); read(m);
	for(int i = 1; i <= n; i++) read(a[i]), read(b[i]);
	for(int i = 1; i < n; i++)  w[i] = a[i + 1] - b[i];
	int j = 1;
	for(int i = 1; i <= n; i++) {
		m += w[i - 1];
		while(m > w[j] && j < n) m -= w[j], j++;
		ans = max(ans, m + b[j] - a[i]);
	}
	cout << ans << endl;
	return 0;
}