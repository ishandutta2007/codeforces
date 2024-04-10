#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 2e6 + 7;
char c[MAXN];

struct hash_str {
    vector <int> h, p;
    int B, M;
    hash_str(string s, int b, int m) {
        B = b;
        M = m;
        int n = s.size();
        h.resize(n + 1);
        p.resize(n + 1);
        h[0] = 0;
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            h[i] = ((h[i - 1] * (ll) B) + s[i - 1]) % M;
            p[i] = ((p[i - 1] * (ll) B)) % M;
        }
    }
    int get(int l, int r) {
        int res = h[r] - (h[l] * (ll) p[r - l]) % M;
        if (res < 0) res += M;
        return res;
    }
};

map <pair <int, int>, int> hsh;
set <int> go[MAXN];
vector <int> fer[MAXN];

string next() {
    scanf(" %s", c);
    return string(c);
}


int main() {
    srand(time(NULL));
    #ifdef ONPC
        freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);
    #else
        //
        //
    #endif
    int n, k;
    scanf("%d%d", &n, &k);
    string s = next();
    int w = (int) s.size();
    for (int i = 0; i < k; i++) {
        s.pb(s[i]);
    }
    int b1 = rand(), b2 = rand(), m1 = (int) 1e9 + 7, m2 = (int) 1e9 + 7;
    int g;
    scanf("%d", &g);
    for (int i = 1; i <= g; i++) {
        string t = next();
        hash_str h(t, b1, m1), h1(t, b2, m2);
        hsh[{h.get(0, k), h1.get(0, k)}] = i;
    }
    hash_str h(s, b1, m1), h1(s, b2, m2);
    vector <int> cnt(g + 1);
    for (int i = 0; i < w; i++) {
        int g1 = h.get(i, i + k), g2 = h1.get(i, i + k);
        int f = hsh[{g1, g2}];
        if (!f) {
            continue;
        } else {
            go[i % k].insert(f);
            fer[i % k].pb(f);
        }
    }
    for (int i = 0; i < k; i++) {
        if ((int) go[i].size() == n) {
            puts("YES");
            for (auto c : fer[i]) {
                printf("%d ", c);
            }
            puts("");
            return 0;
        }
    }
    puts("NO");
}