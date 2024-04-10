#include <bits/stdc++.h>

using namespace std;

#define int long long
int const maxn = 2e5 + 5, maxc = 11;
int a[maxn];
int tree[4 * maxn];
int inf = 1e18;
int st[maxc + 2];
pair < int, int > go[maxc];
int answer;
pair < int, int > have[4 * maxn][maxc];

void build(int i, int l, int r) {
    if (r - l == 1) {
        tree[i] = inf;
        for (int j = 0; j < maxc; ++j) have[i][j] = {inf, inf};
        string s = to_string(a[l]);
        int n = (int)s.size();
        for (int j = n - 1; j >= 0; --j) {
            if (s[j] != '0') {
                int x = 0, y = 0;
                for (int z = j; z <= n - 1; ++z) {
                    x = x * 10 + s[z] - '0';
                }
                for (int z = 0; z < j; ++z) {
                    y = y * 10 + s[z] - '0';
                }
                //cout << a[l] << " " << j << " " << x << " " << y << '\n';
                have[i][n - 1 - j] = {y, x};
            }
        }
        return;
    }
    int m = (r + l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m, r);
    int ans = min(tree[2 * i + 1], tree[2 * i + 2]);
    for (int j = 0; j < maxc; ++j) {
        if (have[2 * i + 1][j].first != inf && have[2 * i + 2][j].first != inf) {
            ans = min(ans, have[2 * i + 1][j].first * st[j + 1] + have[2 * i + 1][j].second + have[2 * i + 2][j].first * st[j + 1] + have[2 * i + 2][j].second);
        }
    }
    tree[i] = ans;
    for (int j = 0; j < maxc; ++j) have[i][j] = min(have[2 * i + 1][j], have[2 * i + 2][j]);
}

void update(int i, int l, int r, int lq, int x) {
    if (r - l == 1) {
        tree[i] = inf;
        a[l] = x;
        for (int j = 0; j < maxc; ++j) have[i][j] = {inf, inf};
        string s = to_string(a[l]);
        int n = (int)s.size();
        for (int j = n - 1; j >= 0; --j) {
            if (s[j] != '0') {
                int x = 0, y = 0;
                for (int z = j; z <= n - 1; ++z) {
                    x = x * 10 + s[z] - '0';
                }
                for (int z = 0; z < j; ++z) {
                    y = y * 10 + s[z] - '0';
                }
                have[i][n - 1 - j] = {y, x};
            }
        }
        return;
    }
    int m = (r + l) / 2;
    if (lq < m) update(2 * i + 1, l, m, lq, x);
    else update(2 * i + 2, m, r, lq, x);
    int ans = min(tree[2 * i + 1], tree[2 * i + 2]);
    for (int j = 0; j < maxc; ++j) {
        if (have[2 * i + 1][j].first != inf && have[2 * i + 2][j].first != inf) {
            ans = min(ans, have[2 * i + 1][j].first * st[j + 1] + have[2 * i + 1][j].second + have[2 * i + 2][j].first * st[j + 1] + have[2 * i + 2][j].second);
        }
    }
    tree[i] = ans;
    for (int j = 0; j < maxc; ++j) have[i][j] = min(have[2 * i + 1][j], have[2 * i + 2][j]);
}

void get_ans(int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) {
        //cout << l << " " << r << '\n';
        //for (int j = 0; j < maxc; ++j) cout << go[j].first << " " << go[j].second << '\n';
        answer = min(answer, tree[i]);
        for (int j = 0; j < maxc; ++j) {
            if (go[j].first != inf && have[i][j].first != inf) {
                answer = min(answer, have[i][j].first * st[j + 1] + have[i][j].second + go[j].first * st[j + 1] + go[j].second);
            }
            go[j] = min(go[j], have[i][j]);
        }
        return;
    }
    int m = (r + l) / 2;
    get_ans(2 * i + 1, l, m, lq, rq);
    get_ans(2 * i + 2, m, r, lq, rq);
}

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t, x, l, r;
    cin >> n >> m;
    st[0] = 1;
    for (int i = 1; i <= maxc; ++i) st[i] = st[i - 1] * 10;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(0, 1, n + 1);
    //cout << tree[0] << '\n';
    for (int i = 1; i <= m; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> l >> x;
            update(0, 1, n + 1, l, x);
        }
        else {
            cin >> l >> r;
            answer = inf;
            for (int j = 0; j < maxc; ++j) go[j] = {inf, inf};
            get_ans(0, 1, n + 1, l, r + 1);
            if (answer == inf) cout << -1 << '\n';
            else cout << answer << '\n';
        }
    }
    return 0;
}