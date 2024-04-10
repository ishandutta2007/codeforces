#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <queue>
#include <assert.h>
#include <fstream>

using namespace std;

#define ll unsigned long long
#define ull unsigned long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 100005;

bool isLucky(int x) {
    while (x) {
        int d = x % 10;
        if (d != 4 && d != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}


vector<pair<int,int>> a;
vector<int> b;
int nxt[maxn];
ll dp[maxn];
int g[maxn];

void gen() {
    srand(time(NULL));
    int n = 100;
    ofstream out("a.in");
    out << n << endl;
    for (int i = 0; i < n; i++) {
        out << rand() % 100 + 1 << " ";
    }
    out.close();
}

ll brute(int n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        set<int> s1;
        for (int j = i; j < n; j++) {
            if (isLucky(g[j])) {
                s1.insert(g[j]);
            }

            for (int l = j + 1; l < n; l++) {
                for (int r = l; r < n; r++) {

                    if (s1.count(g[r])) {
                        break;
                    }
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main() {
    //gen();
    //freopen("a.in", "r", stdin);

    dp[1] = 1;
    for (ll i = 2; i < maxn; i++) {
        dp[i] = dp[i - 1] + (i) * (i + 1) / 2;
    }

    int n;
    scanf("%d", &n);

    ll ans = 0;

    ll c = 0;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        g[i] = x;
        if (isLucky(x)) {
            a.pb(mp(x, c));
            b.pb(i);

            for (ll j = 1; j <= c; j++) {
                ans += j * (n - i + c - j) * (n - i + c - j + 1) / 2;
            }

            c = 0;
        } else {
            c++;
        }
    }

    for (ll j = 1; j < c; j++) {
        ans += j * (c - j) * (c - j + 1) / 2;
    }

    //cerr << ans << endl;

    map<int, int> nx;
    for (int i = a.size() - 1; i >= 0; i--) {
        nxt[i] = nx.count(a[i].fst) ? nx[a[i].fst] : -1;
        nx[a[i].fst] = i;
    }

    for (int i = 0; i < a.size(); i++) {
        set<int> was;
        set<int> r;
        set<int, greater<int>> l;
        l.insert(b[i]);
        r.insert(n);

        ll fr = (i + 1 < a.size() ? a[i + 1].snd : n - b[i] - 1);
        ll z = 0;

        for (int j = i; j >= 0; j--) {
            if (!was.count(a[j].fst)) {
                was.insert(a[j].fst);

                int v = nxt[j];
                while (v != -1) {
                    int x = b[v];
                    ll lb = *l.lower_bound(x);
                    ll rb = *r.lower_bound(x);

                    if (lb != b[i]) {
                        z -= (rb - lb - 1) * (rb - lb) / 2;
                        z += (rb - x - 1) * (rb - x) / 2;
                        z += (x - lb - 1) * (x - lb) / 2;
                    } else {
                        z += (rb - x - 1) * (rb - x) / 2;
                    }


                    l.insert(x);
                    r.insert(x);

                    v = nxt[v];
                }
            }

            int y = *r.begin() - b[i] - 1;

            ans += (dp[y] - dp[max(0ULL, y - fr - 1)]) * (a[j].snd + 1);
            ans += z * (a[j].snd + 1) * (fr + 1);
        }
    }

    //cerr << ans << " " << brute(n) << endl;
    cout << ans << endl;

    return 0;
}