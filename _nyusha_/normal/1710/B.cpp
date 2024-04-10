#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 2e5 + 5;
int x[maxn], p[maxn];
ll inf = 1e18;
ll addk[3 * maxn], addy[maxn * 3], need[3 * maxn], mx[3][12 * maxn];
vector < int > good;

void build(int i, int l, int r) {
    if (r - l == 1) {
        for (int s = -1; s <= 1; s++) {
            mx[s + 1][i] = need[l] + s * good[l];
        }
    } else {
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        for (int j = 0; j < 3; j++) mx[j][i] = max(mx[j][2 * i + 1], mx[j][2 * i + 2]);
    }
}

ll get(int j, int i, int l, int r, int lq, int rq) {
    if (lq >= r || l >= rq) return -inf;
    if (lq <= l && r <= rq) return mx[j][i];
    int m = (r + l) / 2;
    return max(get(j, 2 * i + 1, l, m, lq, rq), get(j, 2 * i + 2, m, r, lq, rq));
}

inline void add(int l, int r, int mid, int x) {
    addy[l] += (x - good[mid]);
    addy[mid] -= (x - good[mid]);
    addk[l]++;
    addk[mid]--;

    addy[mid] += (x + good[mid]);
    addy[r + 1] -= (x + good[mid]);
    addk[mid]--;
    addk[r + 1]++;
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> x[i] >> p[i];
        good = {};
        for (int i = 1; i <= n; i++) good.push_back(x[i]), good.push_back(x[i] - p[i]), good.push_back(x[i] + p[i]);
        sort(good.begin(), good.end());
        for (int i = 0; i <= (int)good.size(); i++) {
            addk[i] = 0, addy[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int lef = lower_bound(good.begin(), good.end(), x[i] - p[i]) - good.begin();
            int righ = upper_bound(good.begin(), good.end(), x[i] + p[i]) - good.begin() - 1;
            int mid = lower_bound(good.begin(), good.end(), x[i]) - good.begin();
            add(lef, righ, mid, p[i]);
        }
        ll sk = 0, sy = 0;
        for (int i = 0; i < (int)good.size(); i++) {
            sk += addk[i], sy += addy[i];
            need[i] = (ll)sk * (ll)good[i] + sy;
        }
        string answer = "";
        build(0, 0, good.size());
        for (int i = 1; i <= n; i++) {
            int lef = lower_bound(good.begin(), good.end(), x[i] - p[i]) - good.begin();
            int righ = upper_bound(good.begin(), good.end(), x[i] + p[i]) - good.begin() - 1;
            int mid = lower_bound(good.begin(), good.end(), x[i]) - good.begin();
            if (get(1, 0, 0, good.size(), 0, lef) <= m && get(0, 0, 0, good.size(), lef, mid) - (p[i] - good[mid]) <= m && get(2, 0, 0, good.size(), mid, righ + 1) - (p[i] + good[mid]) <= m && get(1, 0, 0, good.size(), righ + 1, good.size()) <= m) {
                answer += "1";
            } else answer += "0";
        }
        cout << answer << '\n';
    }
    return 0;
}