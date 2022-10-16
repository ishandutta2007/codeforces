#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define lint long long int
using namespace std;

const int NMAX = 500005;
const int RAD = 1000;

int n;
lint v[NMAX];

int which_bucket[NMAX];
int _left[NMAX / RAD + 5];
int _right[NMAX / RAD + 5];
lint lazy[NMAX / RAD + 5];

vector <pair <lint, int> > Sets[NMAX];

inline void precalc_buckets () {
    for (int i = 1; i <= n; ++ i) {
        which_bucket[i] = (i - 1) / RAD + 1;
        _right[which_bucket[i]] = i;
    }

    for (int i = 1; i <= n; i += RAD)
        _left[which_bucket[i]] = i;
}

inline void recompute (int bucket) {
    Sets[bucket].reserve(RAD);
    Sets[bucket].clear();

    for (int i = _left[bucket]; i <= _right[bucket]; ++ i) {
        v[i] += lazy[bucket];
        Sets[bucket].push_back(make_pair(v[i], i));
    }

    lazy[bucket] = 0;

    sort(Sets[bucket].begin(), Sets[bucket].end());
}

int query (lint val) {
    int a = 0, b = 0;

    vector <pair <lint, int> > :: iterator it;
    for (int i = 1; i <= (n - 1) / RAD + 1; ++ i) {
        it = lower_bound(Sets[i].begin(), Sets[i].end(), make_pair(val - lazy[i], 0));

        if (it != Sets[i].end() && it -> first + lazy[i] == val) {
            if (!a)
                a = it -> second;

            it = lower_bound(Sets[i].begin(), Sets[i].end(), make_pair(val + 1 - lazy[i], 0));
            -- it;
            b = it -> second;
        }
    }

    if (!a)
        return -1;
    return b - a;
}

inline void update (int st, int dr, int val) {
    int st_b = which_bucket[st];
    int dr_b = which_bucket[dr];

    if (st_b == dr_b) {
        for (int i = st; i <= dr; ++ i)
            v[i] += val;
        recompute(st_b);

        return ;
    }

    for (int i = st_b + 1; i < dr_b; ++ i)
        lazy[i] += val;

    for (int i = st; i <= _right[st_b]; ++ i)
        v[i] += val;
    recompute(st_b);

    for (int i = _left[dr_b]; i <= dr; ++ i)
        v[i] += val;
    recompute(dr_b);
}

int main()
{
    ios_base :: sync_with_stdio(false);

    int q = 0;

    cin >> n >> q;
    for (int i = 1; i <= n; ++ i)
        cin >> v[i];

    precalc_buckets();
    for (int i = 1; i <= (n - 1) / RAD + 1; ++ i)
        recompute(i);

    int type;
    int l, r, x;
    while (q --) {
        cin >> type;

        if (type == 1) {
            cin >> l >> r >> x;
            update(l, r, x);
        }
        else {
            cin >> x;
            cout << query(x) << '\n';
        }
    }

    return 0;
}