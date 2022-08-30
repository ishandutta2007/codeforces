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

int n, len, x, ans, l, t, r, last;

int main() {
    cin >> n >> len >> x;
    for (int i = 1; i <= n; i++) {
    	int A, B;
        read(A); read(B);
        r = A + B;
        ans += (A - last) / x;
        last = r;
    }
    cout << ans + (len - last) / x << endl;
    return 0;
}