#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 1e6 + 1;
int ans[maxn];
int a[maxn];
int get_ans[4 * maxn];
int max_ans[4 * maxn];
int inf = 1e18;

void update(int i, int l, int r, int lq, int rq, int dx) {
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        get_ans[i] += dx;
        return;
    }
    int m = (r + l) / 2;
    update(2 * i + 1, l, m, lq, rq, dx);
    update(2 * i + 2, m, r, lq, rq, dx);
}

int sum(int i, int l, int r, int lq) {
    if (r - l == 1) return get_ans[i];
    int m = (r + l) / 2;
    if (lq < m) return sum(2 * i + 1, l, m, lq) + get_ans[i];
    return sum(2 * i + 2, m, r, lq) + get_ans[i];
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, w, t;
    cin >> n >> w;
    for (int i = 1; i <= n; ++i) {
        //cout << i << endl;
        cin >> t;
        for (int j = 1; j <= t; ++j) cin >> a[j];
        if (3 * t >= w) {
            multiset < int > Q;
            multiset < pair < int, int > > close;
            for (int j = 1; j <= w; ++j) {
                if (j <= t) Q.insert(a[j]);
                max_ans[j] = (*Q.rbegin());
                if (j <= t) close.insert({w - t + j, a[j]});
                while ((int)close.size() > 0) {
                    auto p = (*close.begin());
                    if (p.first <= j) {
                        Q.erase(Q.find(p.second));
                        close.erase(p);
                    }
                    else break;
                }
            }
            for (int j = t + 1; j <= w; ++j) max_ans[j] = max(max_ans[j], 0ll);
            for (int j = 1; j <= w - t; ++j) max_ans[j] = max(max_ans[j], 0ll);
            /*for (int j = 1; j <= w; ++j) cout << max_ans[j] << " ";
            cout << '\n';*/
            for (int j = 1; j <= w; ++j) {
                update(0, 1, w + 1, j, j + 1, max_ans[j]);
            }
        }
        else {
            multiset < int > Q;
            multiset < pair < int, int > > close;
            for (int j = 1; j <= t; ++j) {
                Q.insert(a[j]);
                max_ans[j] = max((*Q.rbegin()), 0ll);
                update(0, 1, w + 1, j, j + 1, max_ans[j]);
                close.insert({w - t + j, a[j]});
            }
            update(0, 1, w + 1, t + 1, w - t + 1, max(0ll, (*Q.rbegin())));
            for (int j = w - t + 1; j <= w; ++j) {
                max_ans[j] = max((*Q.rbegin()), 0ll);
                update(0, 1, w + 1, j, j + 1, max_ans[j]);
                while ((int)close.size() > 0) {
                    auto p = (*close.begin());
                    if (p.first <= j) {
                        Q.erase(Q.find(p.second));
                        close.erase(p);
                    }
                    else break;
                }
            }
        }
    }
    for (int i = 1; i <= w; ++i) cout << sum(0, 1, w + 1, i) << " ";
    return 0;
}