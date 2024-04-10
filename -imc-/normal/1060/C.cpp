#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;

using li = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()

void solve(bool);

int main() {
#ifdef YA
    auto s = clock();
    assert(freopen("input.txt", "r", stdin));
#else
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    cout << fixed << setprecision(20);

    solve(true);

#ifdef YA1
    while (true) solve(false);
#endif

#ifdef YA
    cerr << endl << endl << (clock() - s) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

//#define int li
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
    read = true;

    int n, m;
    if (read) {
        cin >> n >> m;
    } else {
        n = m = 2000;
    }

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        if (read) {
            cin >> a[i];
        } else {
            a[i] = rand() % 2000;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (read) {
            cin >> b[i];
        } else {
            b[i] = rand() % 2000;
        }
    }

    li x;
    if (read) {
        cin >> x;
    } else {
        x = 2e9;
    }

    auto get = [&](vector<int> v) {
        vector<pair<int, int>> sMax;
        for (int i = 0; i < v.size(); ++i) {
            int s = 0;
            for (int j = i; j < v.size(); ++j) {
                s += v[j];
                sMax.emplace_back(s, j - i + 1);
            }
        }

        sort(all(sMax));
        vector<pair<int, int>> ans;
        for (auto it : sMax) {
            if (ans.empty() || it.first > ans.back().first) {
                ans.push_back(it);
            }

            if (it.first == ans.back().first) {
                ans.back().second = it.second;
            }
        }
        return ans;
    };

    auto ax = get(a);
    auto bx = get(b);

    //if (ax[0].first * (li)bx[0].first > )

    int pos = bx.size() - 1;

    for (int i = 1; i < bx.size(); ++i) {
        bx[i].second = max(bx[i].second, bx[i - 1].second);
    }

    li ans = 0;
    for (int i = 0; i < ax.size(); ++i) {
        while (pos >= 0 && ax[i].first * (li)bx[pos].first > x) {
            --pos;
        }
        if (pos < 0) {
            break;
        }
        //cout << "prod " << ax[i].second << " " << bx[pos].second << "\n";
        ans = max(ans, ax[i].second * (li)bx[pos].second);
    }

    cout << ans << "\n";
}