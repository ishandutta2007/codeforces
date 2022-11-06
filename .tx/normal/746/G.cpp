#include <bits/stdc++.h>

using namespace std;

template<typename T>
void sci(T &t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T &t, Ts &... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int a[222222];

vector<int> lvl[222222];
vector<pair<int, int> > ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    scid(n, t, k);
    for (int i = 0; i < t; i++) {
        sci(a[i]);
    }
    int wb = a[t - 1];
    int mb = a[t - 1];
    for (int i = 0; i + 1 < t; i++) {
        wb += max(0, a[i] - a[i + 1]);
        mb += a[i] - 1;
    }
    if (wb > k || mb < k) {
        cout << -1;
        return 0;
    }

    int nd = k - wb;
    lvl[0].push_back(1);
    int ll = 1;
    for (int i = 0; i < a[0]; i++) {
        ans.push_back({0, ll});
        lvl[1].push_back(ll);
        ++ll;
    }
    for (int i = 1; i < t; i++) {
        int x = min(nd, min(a[i - 1], a[i]) - 1);
        nd -= x;
        int aa = 0;
        int fs = min(a[i - 1], a[i]) - x;
        for (int j = 0; j < fs; j++) {
            ans.push_back({lvl[i][j % a[i - 1]], ll});
            lvl[i + 1].push_back(ll);
            ++ll;
            aa++;
        }

        while (aa < a[i]) {
            ans.push_back({lvl[i][0], ll});
            lvl[i + 1].push_back(ll);
            ++ll;
            ++aa;
        }
    }

    cout << n << "\n";
    for (auto i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

    return 0;
}