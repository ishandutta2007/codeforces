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

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &x) {
    s << "[";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "]";
    return s;
}

//-----------------------------------------------------------------------------

vector<string> split(char *s) {
    int n = strlen(s);

    vector<string> res;
    for (int i = 0; i < n; i++) {
        if (isspace(s[i])) {
            continue;
        }

        string c;
        int j = i;
        while (j < n && !isspace(s[j])) {
            c += s[j];
            j++;
        }

        res.pb(c);
        i = j - 1;
    }

    return res;
}

const int maxn = 1e6 + 5;

char tmp[maxn];

int dp[1 << 15][15 * 14 / 2 + 2];
int nxt[maxn][15];

int above[1 << 15][15];

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    for (int i = 0; i < (1 << 15); i++) {
        int was = 0;
        for (int j = 14; j >= 0; j--) {
            was += bool(i & (1 << j));
            above[i][j] = was;
        }
    }

    int n;
    scanf("%d\n", &n);

    fgets(tmp, maxn - 1, stdin);
    tmp[strlen(tmp)] = 0;

    auto rr = split(tmp);
    unordered_map<string, int> s;
    for (int i = 0; i < rr.size(); i++) {
        s[rr[i]] = i;
    }


    int m;
    scanf("%d\n", &m);

    const int inf = 1e9;
    pair<int, int> ans(inf, -1);

    for (int it = 0; it < m; it++) {
        int k;
        scanf("%d ", &k);
        fgets(tmp, maxn - 1, stdin);
        tmp[strlen(tmp)] = 0;
        auto r = split(tmp);
        /*vector<string> r;
        for (int j = 0; j < 50000; j++) {
            r.pb(rr[rand() % (n - 1)]);
        }*/



        vector<int> a;
        for (auto x : r) {
            if (s.count(x)) {
                a.pb(s[x]);
            }
        }

        if (a.empty()) {
            continue;
        }

        //cout << a << endl;

        for (int i = 0; i < n; i++) {
            nxt[a.size()][i] = a.size();
            for (int j = a.size() - 1; j >= 0; j--) {
                nxt[j][i] = nxt[j + 1][i];
                if (a[j] == i) {
                    nxt[j][i] = j;
                }
            }
        }



        int minv = n * (n - 1) / 2;

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j <= minv; j++) {
                dp[i][j] = inf;
            }
        }

        dp[0][0] = 0;

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j <= minv; j++) {
                if (dp[i][j] >= a.size()) {
                    continue;
                }

                int v = dp[i][j];

                for (int h = 0; h < 15; h++) {
                    if (i & (1 << h)) {
                        continue;
                    }

                    if (nxt[v][h] != a.size()) {
                        chmin(dp[i | (1 << h)][j + above[i][h]], nxt[v][h] + 1);
                    }
                }
            }
        }


        int b = -1;
        for (int i = 0; i <= minv; i++) {
            if (dp[(1 << n) - 1][i] != inf) {
                b = i;
                break;
            }
        }

        if (b != -1) {
            ans = min(ans, mp(b, it + 1));
        }
    }


    if (ans.snd == -1) {
        cout << "Brand new problem!" << endl;
    } else {
        cout << ans.snd << endl;
        //cerr << ans.fst << endl;
        cout << "[:";
        for (int i = 0; i < n * (n - 1) / 2 - ans.fst + 1; i++) {
            cout << "|";
        }
        cout << ":]";
    }



    return 0;
}