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
ostream& operator << (ostream &s, const pair<U, V> &x) {
    s << "(" << x.fst << ", " << x.snd << ")";
    return s;
}

template<typename U>
ostream& operator << (ostream &s, const vector<U> &x) {
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

struct node {
    map<int, node*> nxt;
    int len;
    node *lnk;

    int occ;
    int used;
    ll cnt;
    node *gLnk;


    node() {
        len = 0;
        lnk = nullptr;
        used = 0;
        occ = 0;
        cnt = 0;
        gLnk = nullptr;
    }

    bool has(int x) {
        return nxt.count(x);
    }
};

node *root = new node();
node *ls = root;

void extend(int x) {
    node *v = new node();
    ls->nxt[x] = v;
    v->len = ls->len + 1;

    node *s = ls->lnk;
    while (s) {
        if (!s->has(x)) {
            s->nxt[x] = v;
            s = s->lnk;
        } else {
            node *u = s->nxt[x];

            if (u->len == s->len + 1) {
                v->lnk = u;
                break;
            } else {
                node *c = new node();
                c->nxt = u->nxt;
                c->len = s->len + 1;
                c->lnk = u->lnk;
                u->lnk = c;

                node *p = s;
                while (p && p->has(x) && p->nxt[x] == u) {
                    p->nxt[x] = c;
                    p = p->lnk;
                }

                v->lnk = c;
                break;
            }
        }
    }

    if (!v->lnk) {
        v->lnk = root;
    }

    ls = v;
}

const int maxn = 1e5 + 5;
string a[maxn];
char tmp[maxn];

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

    cout.sync_with_stdio(false);
    cout.tie(0);

    int n, k;
    scanf("%d %d\n", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%s\n", tmp);
        a[i] = tmp;
    }

    int sep = 100;

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            for (char &x : a[i]) {
                if (!j) {
                    x -= 'a';
                }
                extend(x);
            }

            extend(sep++);
        }
    }


    int currUsed = 1;

    for (int i = 0; i < n; i++) {
        vector<node*> was;
        priority_queue<pair<int,node*>> q;
        currUsed++;

        node *v = root;

        for (char x : a[i]) {
            v = v->nxt[x];
            was.pb(v);
        }

        reverse(was.begin(), was.end());
        for (auto c : was) {
            q.push(mp(c->len, c));
            c->used = currUsed;
        }

        while (!q.empty()) {
            auto c = q.top().snd;
            q.pop();

            c->occ++;

            if (c->lnk) {
                if (c->lnk->used != currUsed) {
                    c->lnk->used = currUsed;
                    q.push(mp(c->lnk->len, c->lnk));
                }
            }
        }
    }

    currUsed++;

    queue<node*> q;
    q.push(root);
    root->used = currUsed;

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        if (v->occ >= k) {
            v->gLnk = v;
        } else {
            v->gLnk = v->lnk ? v->lnk->gLnk : nullptr;
        }

        for (auto kv : v->nxt) {
            if (kv.snd->used != currUsed) {
                kv.snd->used = currUsed;
                q.push(kv.snd);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }

        node *v = root;
        ll ans = 0;

        for (char x : a[i]) {
            v = v->nxt[x];
            if (v->gLnk) {
                ans += v->gLnk->len;
            }
        }

        cout << ans;
    }

    return 0;
}