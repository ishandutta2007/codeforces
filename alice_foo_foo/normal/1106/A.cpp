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

const int N = 505;

char c[N][N];
int n, ans;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c[i] + 1);
    }
    for(register int i = 2; i < n; i++) {
        for(register int j = 2; j < n; j++) {
            if(c[i][j] == 'X' && c[i - 1][j - 1] == 'X' && c[i - 1][j + 1] == 'X' && c[i + 1][j - 1] == 'X' && c[i + 1][j + 1] == 'X') ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}