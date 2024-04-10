#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <list>
#include <time.h>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(stt) for (int i = 0; i < stt; ++i)
#define foj(stt) for (int j = 0; j < stt; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

const int inf = 1e9;

struct SegmentTree {
    int n;
    vei a;

    SegmentTree(int count) {
        n = 1;
        while (n < count) n *= 2;
        a.assign(2 * n - 1, -inf);
    }

    void set(int i, int x) {
        i += n - 1;
        a[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            a[i] = max(a[i * 2 + 1], a[i * 2 + 2]);
        }
    }

    int find(int x, int y) {
        return find(0, 0, n, x + 1, n, y);
    }

    int find(int i, int tl, int tr, int l, int r, int y) {
        if (l >= r || a[i] <= y) return inf;
        if (tl == tr - 1) return i - (n - 1);

        int m = (tr + tl) >> 1;

        if (tl == l && tr == r) {
            int a1 = a[i * 2 + 1];
            int a2 = a[i * 2 + 2];
            if (a1 > y) return find(i * 2 + 1, tl, m, l, m, y);
            return find(i * 2 + 2, m, tr, m, r, y);
        }

        return min(
            find(i * 2 + 1, tl, m, l, min(r, m), y),
            find(i * 2 + 2, m, tr, max(l, m), r, y));
    }
};

const int ADD = 0, REMOVE = 1, FIND = 2;

// File names!!!

int main() {
    // openfiles("test");
    int n;
    sci(n);
    vei type(n), ax(n), ay(n);

    foi(n) {
        string s;
        cin >> s;
        int x, y;
        scii(x, y);
        ax[i] = x;
        ay[i] = y;

        if (s == "add") {
            type[i] = ADD;
        } else if (s == "remove") {
            type[i] = REMOVE;
        } else {
            type[i] = FIND;
        }
    }

    vei sx(ax);
    sort(all(sx));
    map<int, int> biec;
    vei back(n);
    for (auto i : sx) {
        biec[i] = biec.size() - 1;
        back[sz(biec) - 1] = i;
    }

    int cx = biec.size();
    SegmentTree st(cx);
    vector< set<int> > my(cx);

    foi(n) {
        int x, y;
        x = biec[ax[i]];
        y = ay[i];
        int tp = type[i];
        if (tp == ADD) {
            my[x].insert(y);
            st.set(x, *my[x].rbegin());
        } else if (tp == REMOVE) {
            my[x].erase(y);
            st.set(x, my[x].empty() ? -inf : *my[x].rbegin());
        } else {
            x = st.find(x, y);
            if (x == inf) {
                pri(-1);
                continue;
            }
            auto ny = my[x].upper_bound(y);
            if (ny == my[x].end()) {
                pri(-1);
            } else {
                prisp(back[x]);
                pri(*ny);
            }
        }
    }

    return 0;
}//vlaksa