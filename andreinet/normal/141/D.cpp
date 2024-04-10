#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 100005;
const i64 Inf = 1LL << 60;

struct Ramp {
    int x, d, t, p, pos;
    bool operator<(const Ramp& other) const {
        return x < other.x;
    }
};

Ramp ramps[Nmax];

vector<i64> allValues;
map<i64, int> smallValue;

void normalize() {
    sort(allValues.begin(), allValues.end());
    allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());
    for (int i = 0; i < int(allValues.size()); ++i)
        smallValue[allValues[i]] = i;
}

void update(vector<pair<i64, int>>& aib, int pos, pair<i64, int> val) {
    for (; pos < int(aib.size()); pos += pos & -pos)
        aib[pos] = min(aib[pos], val);
}

pair<i64, int> query(const vector<pair<i64, int>>& aib, int pos) {
    auto ret = make_pair(Inf, -1);
    for (; pos > 0; pos -= pos & -pos)
        ret = min(ret, aib[pos]);
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    allValues.push_back(0);
    allValues.push_back(L);

    for (int i = 1; i <= N; ++i) {
        cin >> ramps[i].x >> ramps[i].d >> ramps[i].t >> ramps[i].p;
        allValues.push_back(ramps[i].x);
        if (ramps[i].x - ramps[i].p >= 0)
            allValues.push_back(ramps[i].x - ramps[i].p);
        if (ramps[i].x + ramps[i].d <= L)
            allValues.push_back(ramps[i].x + ramps[i].d);
        ramps[i].pos = i;
    }
    normalize();

    vector<vector<int>> rramps(allValues.size() + 3);
    for (int i = 1; i <= N; ++i) {
        if (ramps[i].x - ramps[i].p >= 0)
            rramps[smallValue[ramps[i].x - ramps[i].p]].push_back(i);
    }

    int M = allValues.size() - 1;
    vector<i64> dp(M + 1, Inf);
    vector<pair<i64, int>> from(M + 2), aib(M + 2, {Inf, -1});

    for (int i = 0; i <= M; ++i) {
        if (i > 0) {
            i64 val = dp[i - 1] + allValues[i] - allValues[i - 1];
            if (dp[i] > val) {
                dp[i] = val;
                from[i] = {i - 1, -1};
            }
        }
        else {
            dp[i] = 0;
            from[i] = {-1, -1};
        }

        pair<i64, int> aux = query(aib, M - i + 1);
        i64 val = aux.first - allValues[i];
        if (dp[i] > val) {
            dp[i] = val;
            from[i] = {aux.second, -1};
        }
        for (int r: rramps[i]) {
            i64 time = ramps[r].p + ramps[r].t, dest = ramps[r].x + ramps[r].d;
            int pos = smallValue[dest];
            if (dp[pos] > dp[i] + time) {
                dp[pos] = dp[i] + time;
                from[pos] = {i, ramps[r].pos};
                update(aib, M - pos + 1, make_pair(dp[pos] + allValues[pos], pos));
            }
        }
        //cerr << allValues[i] << ' ' << dp[i] << '\n';
    }

    cout << dp[M] << '\n';
    vector<int> ans;
    for (int i = M; i != -1; i = from[i].first)
        if (from[i].second != -1)
            ans.push_back(from[i].second);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int p: ans) cout << p << ' ';
    cout << '\n';
}