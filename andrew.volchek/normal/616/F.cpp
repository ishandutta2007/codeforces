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
#include <complex>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld double
#define pb push_back
#define left _left
#define right _right

const ld pi = acos(-1.0l);

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

struct node {
    map<int, node*> nxt;
    node *lnk;
    ll sum;
    int len;
    int pos;

    node* go(int c) {
        auto it = nxt.find(c);
        return (it == nxt.end()) ? nullptr : it->snd;
    }

    void replace(int c, node *to) {
        nxt[c] = to;
    }

    node() {
        lnk = nullptr;
        sum = 0;
        len = 0;
    }
};

node pool[2500005];
int deg[2500005];
int poolSz = 0;

node* get() {
    return &pool[poolSz++];
}

node *root = get();
node *lst = root;

int str[2500005];
int prv[2500005];

int strPos = 1;

void extend(int c) {
    node *nw = get();
    node *q = lst;
    nw->len = q->len + 1;

    str[strPos] = c;
    nw->pos = strPos;
    strPos++;

    while (q) {
        if (!q->go(c)) {
            q->nxt[c] = nw;
        } else {
            auto p = q->go(c);
            if (p->len == q->len + 1) {
                nw->lnk = p;
                break;
            } else {
                node *cl = get();
                *cl = *p;
                cl->len = q->len + 1;
                p->lnk = cl;
                nw->lnk = cl;

                for (; q && q->go(c) == p; q = q->lnk) {
                    q->replace(c, cl);
                }
            }

            break;
        }

        q = q->lnk;
    }

    if (!nw->lnk) {
        nw->lnk = root;
    }

    lst = nw;
}

const int maxn = 5e5 + 5;
char s[maxn];

void gen() {
    ofstream out("a.in");
    int n = 100000;
    out << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            out << char((rand() % 1) + 'a');
        }
        out << endl;
    }
    for (int i = 0; i < n; i++) {
        out << 1 << endl;
    }
    out.close();
   // exit(0);
}

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

    vector<string> a;

    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s\n", s);
        a.pb(s);
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    int delim = 'z' + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1; j++) {
            for (char c : a[i]) {
                extend(c);
            }
            extend(delim++);
        }
    }

    for (int i = 0; i < n; i++) {
        auto v = root;
        for (char ch : a[i]) {
            v = v->go(ch);
            v->sum += c[i];
        }
    }

    for (int i = 1; i < poolSz; i++) {
        deg[pool[i].lnk - pool]++;
    }

    queue<int> q;
    for (int i = 1; i < poolSz; i++) {
        if (!deg[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        pool[v].lnk->sum += pool[v].sum;

        int id = pool[v].lnk - pool;
        deg[id]--;

        if (!deg[id] && id) {
            q.push(id);
        }
    }

    for (int i = 1; i < strPos; i++) {
        if (str[i] > 'z') {
            prv[i] = i;
        } else {
            prv[i] = prv[i - 1];
        }
    }

    ll ans = 0;
    for (int i = 1; i < poolSz; i++) {
        int len = pool[i].len;
        int pos = pool[i].pos;
        if (pos - len + 1 <= prv[pos]) {
            len = pos - prv[pos];
        }

        if (len > pool[i].lnk->len) {
            chmax(ans, pool[i].sum * len);
        }
    }

    cout << ans << endl;

    cerr << "time: " << (ld)clock() / CLOCKS_PER_SEC << endl;

    return 0;
}