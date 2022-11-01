#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define clr(x) memset(x, 0, sizeof(x))
#define pb push_back
#define mp make_pair
#define prev asdfsdf
#define fi first
#define se second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;

#define x first
#define y second

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}


void solve() {
    int n = nxt();
    int k = nxt();
    int a = nxt() - 1;
    int b = nxt() - 1;
    int c = nxt() - 1;
    int d = nxt() - 1;
    if (n == 4) {
        cout << "-1\n";
        return;
    }
    if (k < n + 1) {
        cout << "-1\n";
        return;
    }
    char u[n];
    forn(i, n) u[i] = 0;
    u[a] = 1;
    u[b] = 1;
    u[c] = 1;
    u[d] = 1;
    cout << a + 1 << " " << c + 1;
    forn(i, n) {
        if (!u[i]) cout << " " << i + 1;
    }
    cout << " " << d + 1 << " " << b + 1 << "\n";
    cout << c + 1 << " " << a + 1;
    forn(i, n) {
        if (!u[i]) cout << " " << i + 1;
    }
    cout << " " << b + 1 << " " << d + 1 << "\n";
}



int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("errput.txt", "w", stderr);
#endif
    //forn(t, 10) test(4); cerr << clock() * 1./ CLOCKS_PER_SEC << endl; return 0;
    int t = 1;
    while (t--) solve();

    return 0;
}