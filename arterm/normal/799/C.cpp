#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;
const int inf = 1e9;

int n, C, D;
vector<pair<int, int>> c, d;

void read() {
    cin >> n >> C >> D;
    for (int i = 0; i < n; ++i) {
        int b, cost;
        char type;
        cin >> b >> cost >> type;
        if (type == 'C')
            c.emplace_back(cost, b);
        else
            d.emplace_back(cost, b);
    }
}

int best(int last, int x, vector<pair<int, int>> &a) {
    auto id = lower_bound(a.begin(), a.begin() + last, make_pair(x + 1, -inf)) - a.begin();
    --id;
    if (id < 0)
        return -inf;
    return a[id].second;
}

vector<pair<int, int>> work(vector<pair<int, int>> c) {
    int cur = 0;
    for (auto &e : c) {
        cur = max(cur, e.second);
        e.second = cur;
    }
    return c;
}

void kill() {
    sort(all(c));
    sort(all(d));

    auto cm = work(c);
    auto dm = work(d);

    int ans = 0;
    ans = max(ans, best(c.size(), C, cm) + best(d.size(), D, dm));

    for (int i = 0; i < (int) c.size(); ++i) {
        if (c[i].first <= C) {
            ans = max(ans, c[i].second + best(i, C - c[i].first, cm));
        }
    }

    for (int i = 0; i < (int) d.size(); ++i) {
        if (d[i].first <= D) {
            ans = max(ans, d[i].second + best(i, D - d[i].first, dm));
        }
    }

    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}