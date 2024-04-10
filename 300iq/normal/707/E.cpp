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

const int MAXN = (int) 2e3 + 7;
ll t[MAXN][MAXN];
ll rl[MAXN][MAXN];
const int MAXK = 7;
char c[MAXK];
vector <pair <pair <int, int>, int> > p[MAXN];
ll sum[MAXN][MAXN];
bool on[MAXN];

void inc(int i, int j, int cnt) {
    for (int x = i; x < MAXN; x = (x | (x + 1))) {
        for (int y = j; y < MAXN; y = (y | (y + 1))) {
            t[x][y] += cnt;
        }
    }
}

ll get(int i, int j) {
    ll sum = 0;
    for (int x = i; x >= 0; x = (x & (x + 1)) - 1) {
        for (int y = j; y >= 0; y = (y & (y + 1)) - 1) {
            sum += t[x][y]; 
        }
    }
    return sum;
}

ll get(int x1, int y1, int x2, int y2) {
    return get(x2, y2) - get(x2, y1 - 1) - get(x1 - 1, y2) + get(x1 - 1, y1 - 1);
}

struct q {
    int t, x1, y1, x2, y2;
    q() {}
    q(int a, int b, int c, int d, int e) {
        t = a;
        x1 = b;
        y1 = c;
        x2 = d;
        y2 = e;
    }
};

string next() {
    scanf("%s", c);
    return string(c);
}

int main() {
    int n, m, k, x, y, w;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int len;
        scanf("%d", &len);
        for (int j = 0; j < len; j++) {
            scanf("%d%d%d", &x, &y, &w);
            x--, y--;
            p[i].pb({{x, y}, w});
        }
    }
    int l;
    scanf("%d", &l);
    vector <q> e;
    int x1, y1, x2, y2;
    vector <q> t;
    for (int i = 0; i < l; i++) {
        string s = next(); 
        if (s == "SWITCH") {
            scanf("%d", &x1);
            x1--;
            e.pb({1, x1, -1, -1, -1});
        } else {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2) {
                swap(x1, x2);
            }
            if (y1 > y2) {
                swap(y1, y2);
            }
            x1--, y1--, x2--, y2--;
            e.pb({2, x1, y1, x2, y2});
            t.pb({2, x1, y1, x2, y2});
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < (int) t.size(); j++) {
            sum[j][i] = -get(t[j].x1, t[j].y1, t[j].x2, t[j].y2);
        }
        for (auto g : p[i]) {
            inc(g.fc.fc, g.fc.sc, g.sc);
        }
        for (int j = 0; j < (int) t.size(); j++) {
            sum[j][i] += get(t[j].x1, t[j].y1, t[j].x2, t[j].y2);
        }
    }
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        if (e[i].t == 1) {
            on[e[i].x1] ^= 1;
        } else {
            ll res = 0;
            for (int i = 0; i < k; i++) {
                if (!on[i]) {
                    res += sum[cnt][i];
                }
            }
            printf("%lld\n", res);
            cnt++;
        }
    }
}