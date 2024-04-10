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

string foo;
int T, n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T; while(T--) {
        cin >> n >> foo;
        int ans = 1;
        if(n == 2 && foo[0] >= foo[1]) ans = 0;
        if(ans) {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << foo.substr(0, 1) << " " << foo.substr(1, n - 1) << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}