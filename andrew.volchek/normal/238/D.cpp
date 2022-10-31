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

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

const int maxn = 1e5 * 15 + 5;

char s[maxn];
int cnt[maxn][10];
vector<int> was[maxn];
int nx[maxn], pr[maxn];

vector<int> t[int(1e5 * 4 + 100)];


void build(int v, int l, int r) {
    if (l == r) {
        t[v] = was[l];
        return;
    }

    int c = (l + r) >> 1;

    build(2 * v, l, c);
    build(2 * v + 1, c + 1, r);

    t[v].resize(t[2 * v].size() + t[2 * v + 1].size());

    merge(t[2 * v].begin(), t[2 * v].end(), t[2 * v + 1].begin(), t[2 * v + 1].end(), t[v].begin());
}

int get(int v, int l, int r, int i, int j, int x) {
    if (i <= l && r <= j) {
        int it = lower_bound(t[v].begin(), t[v].end(), x) - t[v].begin();
        if (it == t[v].size()) {
            return 1e9;
        } else {
            return t[v][it];
        }
    }

    int res = 1e9;
    int c = (l + r) >> 1;

    if (i <= c) {
        res = min(res, get(2 * v, l, c, i, j, x));
    }

    if (c < j) {
        res = min(res, get(2 * v + 1, c + 1, r, i, j, x));
    }

    return res;
}


int main() {
    srand(time(NULL));

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    for (int i = 0; i < maxn; i++) {
        nx[i] = i + 1;
        pr[i] = i - 1;
    }

    int n, q;
    scanf("%d %d\n", &n, &q);
    scanf("%s\n", s + 1);

    int l = 1;
    int t = 1;
    while (l <= n) {
        int r = 0;

        int pos = l, dir = 0;

        bool prD = false;
        int prPos;

        while (true) {
            for (int i = 0; i < 10; i++) {
                cnt[t][i] = cnt[t - 1][i];
            }

            if (pos > n || pos < l) {
                was[pos].pb(t);
                break;
            }

            was[pos].pb(t);
            chmax(r, pos);

            if (isdigit(s[pos])) {
                cnt[t][s[pos] - '0']++;

                prD = false;
                prPos = pos;

                if (s[pos] == '0') {
                    if (pr[pos] != -1) {
                        nx[pr[pos]] = nx[pos];
                    }

                    pr[nx[pos]] = pr[pos];
                } else {
                    s[pos]--;
                }
            } else {
                if (prD) {
                    if (pr[prPos] != -1) {
                        nx[pr[prPos]] = nx[prPos];
                    }

                    pr[nx[prPos]] = pr[prPos];
                }

                prD = true;
                prPos = pos;

                if (s[pos] == '>') {
                    dir = 0;
                } else {
                    dir = 1;
                }
            }

            if (dir) {
                pos = pr[pos];
            } else {
                pos = nx[pos];
            }

            t++;
        }

        l = r + 1;
        t += 3;
    }

    build(1, 0, n + 1);



    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        int t = was[l][0];
        int t2 = min(get(1, 0, n + 1, 0, l - 1, t), get(1, 0, n + 1, r + 1, n + 1, t));

        for (int j = 0; j < 10; j++) {
            if (j) {
                printf(" ");
            }
            printf("%d", cnt[t2 - 1][j] - cnt[t - 1][j]);
        }

        printf("\n");
    }

    return 0;
}