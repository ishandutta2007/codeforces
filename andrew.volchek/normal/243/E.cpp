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

const int maxn = 505;

int b[maxn];
int used[maxn];
int currUsed = 1;

struct node {
    int id;
    node *nxt;
    vector<int> v;
};

vector<int> rec(vector<int> c, vector<vector<int>> a) {

    a.resize(remove_if(a.begin(), a.end(), [&](const vector<int> &x) {
        return (x.size() == c.size() || x.empty());
    }) - a.begin());

    sort(a.begin(), a.end(), [](const vector<int> &u, const vector<int> &v) {
        return u.size() > v.size();
    });

    if (a.empty()) {
        return c;
    }

    currUsed++;
    for (int x : a[0]) {
        used[x] = currUsed;
    }

    node *t1 = new node(), *t2 = new node();
    for (int x : c) {
        if (used[x] == currUsed) {
            t1->v.pb(x);
            b[x] = 0;
        } else {
            t2->v.pb(x);
            b[x] = 1;
        }
    }

    t1->id = 0;
    t2->id = 1;
    t1->nxt = t2, t2->nxt = t1;

    node *root = t1;
    int sz = 2;

    vector<int> processed(a.size(), 0);
    processed[0] = 1;

    while (true) {

        bool any = false;

        for (int i = 0; i < a.size(); i++) {
            if (processed[i]) {
                continue;
            }

            vector<int> cnt(sz, 0);
            currUsed++;

            for (int x : a[i]) {
                used[x] = currUsed;
                cnt[b[x]]++;
            }

            int nonZero = 0;
            for (int x : cnt) {
                nonZero += bool(x);
            }

            if (nonZero <= 1) {
                continue;
            }

            processed[i] = 1;
            any = true;

            node *v = root;
            bool wasRight = false;

            int nwSz = sz;

            for (int j = 0; j < sz; j++) {
                if (cnt[v->id] && cnt[v->id] < v->v.size()) {
                    if (cnt[v->nxt->id] && !wasRight) {
                        wasRight = true;

                        t2 = new node();
                        auto cv = v->v;
                        v->v.clear();

                        nwSz++;

                        for (int x : cv) {
                            if (used[x] == currUsed) {
                                t2->v.pb(x);
                            } else {
                                v->v.pb(x);
                            }
                        }

                        t2->nxt = v->nxt;
                        v->nxt = t2;
                        v = t2;
                    } else {
                        t2 = new node();
                        auto cv = v->v;
                        v->v.clear();

                        nwSz++;

                        for (int x : cv) {
                            if (used[x] != currUsed) {
                                t2->v.pb(x);
                            } else {
                                v->v.pb(x);
                            }
                        }

                        t2->nxt = v->nxt;
                        v->nxt = t2;
                        v = t2;
                    }
                }

                v = v->nxt;
            }

            sz = nwSz;

            v = root;

            for (int j = 0; j < sz; j++) {
                v->id = j;
                for (int x : v->v) {
                    b[x] = j;
                }
                v = v->nxt;
            }
        }

        if (!any) {
            break;
        }
    }

    vector<vector<int>> cc;
    vector<vector<vector<int>>> qq(sz);

    for (auto v : a) {
        vector<int> cnt(sz, 0);
        for (int x : v) {
            cnt[b[x]]++;
        }
        cc.pb(cnt);
        int nonZero = 0;
        for (int x : cnt) {
            nonZero += bool(x);
        }
        if (nonZero == 1) {
            qq[b[v[0]]].pb(v);
        }
    }

    node *v = root;

    while (true) {
        bool bad = false;
        for (auto x : cc) {
            bad |= x[v->id] && x[v->nxt->id];
        }
        if (!bad) {
            v = v->nxt;
            break;
        }
        v = v->nxt;
        if (v == root) {
            cout << "NO" << endl;
            exit(0);
        }
    }

    vector<int> res;
    for (int i = 0; i < sz; i++) {
        auto r = rec(v->v, qq[v->id]);
        for (int x : r) {
            res.pb(x);
        }
        v = v->nxt;
    }

    return res;
}

char a[maxn][maxn];

void gen() {
    int n = 4;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    random_shuffle(p.begin(), p.end());
    vector<vector<char>> a(n, vector<char>(n, '0'));

    for (int i = 0; i < n; i++) {
        if (rand() & 1) {
            continue;
        }
        int l = rand() % n, r = rand() % n;
        if (l > r) {
            swap(l, r);
        }
        while (l <= r) {
            a[i][p[l]] = '1';
            l++;
        }
    }

    ofstream out("a.in");
    out << n << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << a[i][j];
        }
        out << endl;
    }

    out.close();
}


int main() {
    srand(time(NULL));

    /*while (true)*/ {
#ifdef LOCAL
        gen();
        //cerr << 1 << endl;
        freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

        int n;
        scanf("%d\n", &n);

        vector<int> c;
        for (int i = 0; i < n; i++) {
            c.pb(i);
        }

        vector<vector<int>> f;

        for (int i = 0; i < n; i++) {
            scanf("%s\n", a[i]);
            vector<int> cf;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '1') {
                    cf.pb(j);
                }
            }
            f.pb(cf);
        }

        auto r = rec(c, f);

        /*for (int x : r) {
            cerr << x << " ";
        }
        cerr << endl;*/

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][r[j]] == '0') {
                    continue;
                }
                int h = j;
                while (h < n && a[i][r[h]] == '1') {
                    h++;
                }
                cnt++;
                j = h - 1;
            }

            if (cnt > 1) {
                cout << "NO" << endl;
                return 0;
            }
        }

        cout << "YES" << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%c", a[i][r[j]]);
            }
            printf("\n");
        }
    }

    return 0;
}