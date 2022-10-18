#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn], out[maxn], ok[maxn], sum[(1 << 19)], cur;
pair < int, int > b[maxn];
vector < pair < int, int > > ask[maxn];

void update(int i, int l, int r, int lq) {
    if (r - l == 1) {
        sum[i]++;
        return;
    }
    int m = (r + l) / 2;
    if (lq < m) update(2 * i + 1, l, m, lq);
    else update(2 * i + 2, m, r, lq);
    sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
}

int get_pos(int i, int l, int r) {
    if (r - l == 1) return l;
    int m = (r + l) / 2;
    if (sum[2 * i + 1] >= cur) return get_pos(2 * i + 1, l, m);
    cur -= sum[2 * i + 1];
    return get_pos(2 * i + 2, m, r);
}

int get_nxt(int i, int l, int r, int lq, int rq) {
    if (l >= rq || lq >= r) return -1;
    if (lq <= l && r <= rq) {
        if (sum[i] == 0) return -1;
        if (r - l == 1) return l;
    }
    int m = (r + l) / 2;
    int res1 = get_nxt(2 * i + 1, l, m, lq, rq);
    if (res1 != -1) return res1;
    return get_nxt(2 * i + 2, m, r, lq, rq);
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, pos, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) b[i] = {a[i], i};
    sort(b + 1, b + n + 1, [](pair < int, int > s1, pair < int, int > s2) {
        if (s1.first != s2.first) return s1.first > s2.first;
        return s1.second < s2.second;
    });
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> k >> pos;
        ask[k].push_back({i, pos});
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i].first != b[i + 1].first) {
            for (int j = i; j >= 1 && b[j].first == b[i].first; --j) {
                if (ok[j] == 0) {
                    ok[j] = 1;
                    cnt++;
                    update(0, 1, n + 1, b[j].second);
                    for (auto key : ask[cnt]) {
                        cur = key.second;
                        out[key.first] = a[get_pos(0, 1, n + 1)];
                    }
                }
            }
        }
        else {
            int s = get_nxt(0, 1, n + 1, b[i].second, n + 1);
            if (s != -1 && b[i].first < a[s]) {
                cnt++;
                ok[i] = 1;
                update(0, 1, n + 1, b[i].second);
                for (auto key : ask[cnt]) {
                    cur = key.second;
                    out[key.first] = a[get_pos(0, 1, n + 1)];
                }
            }
        }
    }
    for (int i = 1; i <= m; ++i) cout << out[i] << '\n';
    return 0;
}