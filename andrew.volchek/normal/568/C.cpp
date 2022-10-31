#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

const int maxn = 405 * 4;

char isV[maxn];
vector<int> g[maxn];
vector<int> gt[maxn];

int enc(int v, int vo, int neg) {
    return v * 4 + vo * 2 + neg;
}

void add(int u, int v) {
    g[u].pb(v);
    gt[v].pb(u);
}

void remove(int u, int v) {
    g[u].pop_back();
    gt[v].pop_back();
}

vector<int> order;
int used[maxn];

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    order.pb(v);
}

int comp[maxn];
int cc = 0;

void dfs2(int v) {
    comp[v] = cc;
    for (int to : gt[v]) {
        if (comp[to] == -1) {
            dfs2(to);
        }
    }
}

bool check() {
    fill(comp, comp + maxn, -1);
    fill(used, used + maxn, 0);
    cc = 0;

    order.clear();
    for (int i = 0; i < maxn; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());

    for (int v : order) {
        if (comp[v] == -1) {
            cc++;
            dfs2(v);
        }
    }

    for (int i = 0; i < maxn; i++) {
        if (comp[i] == comp[i ^ 1]) {
            return false;
        }
    }

    return true;
}

char alp[26];
int asz;

char s[maxn];

int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    scanf("%s\n", alp);
    asz = strlen(alp);

    for (int i = 0; i < asz; i++) {
        isV[i] = alp[i] == 'V';
    }

    int n, m;
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        add(enc(i, 0, 0), enc(i, 1, 1));
        add(enc(i, 0, 1), enc(i, 1, 0));
        add(enc(i, 1, 0), enc(i, 0, 1));
        add(enc(i, 1, 1), enc(i, 0, 0));
    }

    for (int i = 0; i < m; i++) {
        char c1, c2;
        int u, v;
        scanf("%d %c %d %c\n", &u, &c1, &v, &c2);
        u--, v--;
        add(enc(u, c1 == 'V', 0), enc(v, c2 == 'V', 0));
        add(enc(v, c2 == 'V', 1), enc(u, c1 == 'V', 1));
    }


    scanf("%s", s);


    if (!check()) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = n; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            add(enc(j, isV[s[j] - 'a'], 1), enc(j, isV[s[j] - 'a'], 0));
        }

        bool good = false;
        int kk;

        if (i != n) {
            bool wasV = false, wasC = false;
            for (int k = s[i] - 'a' + 1; k < asz; k++) {
                if (wasV && isV[k]) {
                    continue;
                }

                if (wasC && !isV[k]) {
                    continue;
                }

                if (isV[k]) {
                    wasV = true;
                } else {
                    wasC = true;
                }

                add(enc(i, isV[k], 1), enc(i, isV[k], 0));

                if (check()) {
                    good = true;
                    kk = k;
                    break;
                }

                remove(enc(i, isV[k], 1), enc(i, isV[k], 0));
            }
        } else {
            good = check();
        }

        string ans;

        if (good) {
            for (int j = 0; j < i; j++) {
                ans += s[j];
            }

            if (i != n) {
                ans += char('a' + kk);
            }

            vector<pair<int,int>> hh;

            for (int j = i + 1; j < n; j++) {
                bool wasV = false, wasC = false;
                for (int k = 0; k < asz; k++) {
                    if (wasV && isV[k]) {
                        continue;
                    }

                    if (wasC && !isV[k]) {
                        continue;
                    }

                    if (isV[k]) {
                        wasV = true;
                    } else {
                        wasC = true;
                    }

                    add(enc(j, isV[k], 1), enc(j, isV[k], 0));
                    hh.pb(mp(enc(j, isV[k], 1), enc(j, isV[k], 0)));

                    if (check()) {
                        ans += char('a' + k);
                        break;
                    }

                    remove(enc(j, isV[k], 1), enc(j, isV[k], 0));
                    hh.pop_back();
                }
            }

            if (ans.size() != n) {
                reverse(hh.begin(), hh.end());
                for (auto x : hh) {
                    remove(x.fst, x.snd);
                }

                if (i != n) {
                    remove(enc(i, isV[kk], 1), enc(i, isV[kk], 0));
                }
            } else {
                cout << ans << endl;
                return 0;
            }


        }

        for (int j = i - 1; j >= 0; j--) {
            remove(enc(j, isV[s[j] - 'a'], 1), enc(j, isV[s[j] - 'a'], 0));
        }
    }


    cout << -1 << endl;

    return 0;
}