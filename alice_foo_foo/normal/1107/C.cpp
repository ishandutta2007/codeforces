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

const int N = 2e5 + 5;

char c[N];
int a[N];
int n, k;
ll ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(register int i = 1; i <= n; i++) cin >> a[i];
    for(register int i = 1; i <= n; i++) cin >> c[i];
    for(register int i = 1, r; i <= n; i = r + 1) {
        int l = i; r = i;
        while(r < n && c[r] == c[r + 1]) ++r;
        if(r - l + 1 <= k) {
            for(register int j = l; j <= r; j++) ans += a[j];
        } else {
            sort(a + l, a + r + 1);
            for(register int j = r; j >= r - k + 1; j--) ans += a[j];
        }
    }
    cout << ans << endl;
    return 0;
}