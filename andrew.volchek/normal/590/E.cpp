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
#include <limits>

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

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x) {
    s << "{";
    bool was = false;
    for (auto it : x) {
        if (was) {
            s << ", ";
        }
        was = true;
        s << it;
    }
    s << "}";
    return s;
}

template<int sz>
ostream operator<<(ostream &s, const bitset<sz> &x) {
    for (int i = 0; i < sz; i++) {
        s << x[i];
    }
    return s;
}


//-----------------------------------------------------------------------------

const int maxn = 805;
const int maxs = 1e7 + 5;

struct node {
    node *nxt[2];
    node *lnk;
    node *termLnk;
    int term;

    node() {
        fill(nxt, nxt + 2, nullptr);
        lnk = nullptr;
        termLnk = nullptr;
        term = 0;
    }
};

node pool[maxs];
int poolSz = 0;

node *root = new node();

void add(const string &x, int idx) {
    node *v = root;
    for (char c : x) {
        c -= 'a';

        if (!v->nxt[c]) {
            v->nxt[c] = &pool[poolSz++];
        }

        v = v->nxt[c];
    }

    v->term = idx;
}

void buildLinks() {
    root->lnk = root;
    root->termLnk = root;

    queue<node*> q;

    for (auto v : root->nxt) {
        if (v) {
            v->lnk = root;
            v->termLnk = root;
            q.push(v);
        }
    }

    while (!q.empty()) {
        node *v = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            if (!v->nxt[i]) {
                continue;
            }

            node *to = v->nxt[i];

            node *u = v->lnk;
            while (u != root) {
                if (u->nxt[i]) {
                    break;
                }
                u = u->lnk;
            }

            if (u->nxt[i]) {
                u = u->nxt[i];
            }

            to->lnk = u;

            if (to->lnk->term) {
                to->termLnk = to->lnk;
            } else {
                to->termLnk = to->lnk->termLnk;
            }

            q.push(to);
        }
    }
}

int g[maxn][maxn];

void go(const string &x, int idx) {
    node *v = root;
    for (char c : x) {
        c -= 'a';

        v = v->nxt[c];

        if (v->termLnk->term) {
            g[idx][v->termLnk->term] = 1;
        }

        if (v->term) {
            g[idx][v->term] = 1;
        }
    }
}

int mt[maxn];
int fw[maxn];
int used[maxn];

bool match(int v) {
    for (int i = 0; i < maxn; i++) {
        if (g[v][i] && mt[i] == -1) {
            mt[i] = v;
            fw[v] = i;
            return true;
        }
    }

    used[v] = 1;
    for (int i = 0; i < maxn; i++) {
        if (g[v][i] && !used[mt[i]] && match(mt[i])) {
            mt[i] = v;
            fw[v] = i;
            return true;
        }
    }

    return false;
}

int visited[2][maxn];

void dfs(int v, int side) {
    if (visited[side][v]) {
        return;
    }

    visited[side][v] = 1;

    if (!side) {
        for (int i = 0; i < maxn; i++) {
            if (g[v][i] && mt[v] != i) {
                dfs(i, 1 - side);
            }
        }
    } else {
        dfs(mt[v], 1 - side);
    }
}

char tmp[maxs];
string a[maxn];

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

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%s", tmp);
        a[i] = tmp;
        add(a[i], i);
    }

    buildLinks();

    for (int i = 1; i <= n; i++) {
        go(a[i], i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                g[j][k] |= g[j][i] && g[i][k];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }*/

    fill(mt, mt + maxn, -1);
    fill(fw, fw + maxn, -1);

    for (int i = 1; i <= n; i++) {
        fill(used, used + maxn, 0);
        match(i);
    }

    for (int i = 1; i <= n; i++) {
        if (fw[i] == -1) {
            dfs(i, 0);
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!(!visited[0][i] || visited[1][i])) {
            ans.pb(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i) {
            cout << " ";
        }

        cout << ans[i];
    }


    return 0;
}