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

ll l, r;

int main() {
	cin >> l >> r;
	cout << "YES" << endl;
	for(ll i = l; i <= r; i += 2) {
		printf("%I64d %I64d\n", i, i + 1);
	}
	return 0;
}