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
#include <tuple>
#include <complex>

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
    node *to[2];
    node *lnk;
    int len;
    int pos;
    node() {
        fill(to, to + 2, nullptr);
        lnk = nullptr;
        len = 0;
        pos = 0;
    }
};

node *root = new node();
node *lst = root;
vector<node*> was({root});

void extend(int ch, int pos) {
    node *nw = new node();
    was.pb(nw);
    nw->pos = pos;
    nw->len = lst->len + 1;
    node *v = lst;
    while (v) {
        if (v->to[ch] == nullptr) {
            v->to[ch] = nw;
            v = v->lnk;
        } else {
            if (v->to[ch]->len == v->len + 1) {
                nw->lnk = v->to[ch];
                break;
            } else {
                node *q = v->to[ch];
                node *clone = new node();
                was.pb(clone);
                *clone = *q;
                clone->len = v->len + 1;
                q->lnk = clone;
                nw->lnk = clone;
                for (node* u = v; u && u->to[ch] == q; u = u->lnk) {
                    u->to[ch] = clone;
                }
                break;
            }
        }
    }

    if (!nw->lnk) {
        nw->lnk = root;
    }

    lst = nw;
}


const int maxn = 5e5 + 5;
int rmq[20][maxn];
int bal[maxn];
int ln[maxn];

int get(int l, int r) {
    int d = ln[r - l + 1];
    return min(rmq[d][l], rmq[d][r - (1 << d) + 1]);
}

bool check(int l, int r) {
    bool good = true;
    if (!l) {
        good &= bal[r] == 0;
    } else {
        good &= bal[r] == bal[l - 1];
    }

    return good && get(l, r) >= bal[r];
}

char s[maxn];

bool good(string s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') {
            bal++;
        } else {
            bal--;
            if (bal < 0) {
                return false;
            }
        }
    }

    return !bal;
}

int brute(string s) {
    set<string> res;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j <= s.size(); j++) {
            auto x = s.substr(i, j);
            if (good(x)) {
                res.insert(x);
            }
        }
    }
    return res.size();
}

int main() {
    srand(time(NULL));

    retry:

#ifdef LOCAL
    //gen();
    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif

    int n;
    scanf("%d\n", &n);
    scanf("%s", s);
    //n = 5e5;
    for (int i = 0; i < n; i++) {
    //    s[i] = (rand() & 1) ? '(' : ')';
    }

    for (int i = 0; i < n; i++) {
        bal[i] = s[i] == '(' ? 1 : -1;
        if (i) {
            bal[i] += bal[i - 1];
        }
        extend(s[i] == '(' ? 0 : 1, i);
    }


    for (int i = 1; i < maxn; i++) {
        while ((1 << ln[i]) <= i) {
            ln[i]++;
        }
        ln[i]--;
    }


    map<int, vector<int>> pos;
    pos[0].pb(-1);

    for (int i = 0; i < n; i++) {
        rmq[0][i] = bal[i];
        pos[bal[i]].pb(i);
    }


    for (int i = 1; i < 20; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
        }
    }


    ll ans = 0;


    for (auto v : was) {
        if (!v->len) {
            continue;
        }

        int lb = v->lnk ? (v->lnk->len + 1) : 1;
        int rb = v->len;

        int l_pos = v->pos - rb;
        int r_pos = v->pos - lb;

        int need = bal[v->pos];

        auto &x = pos[need];

        int i = lower_bound(x.begin(), x.end(), l_pos) - x.begin();
        int j = upper_bound(x.begin(), x.end(), r_pos) - x.begin();

        if (i < j) {
            int lo = i - 1, hi = j;
            while (hi - lo > 1) {
                int mid = (lo + hi) >> 1;

                if (check(x[mid] + 1, v->pos)) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }

            ans += j - hi;
        }
    }

    cout << ans << endl;
   // assert(ans == brute(s));

    return 0;
}