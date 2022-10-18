#include<bits/stdc++.h>

using namespace std;

#define double long double
int const maxn = 1e6 + 5;
double a[maxn];
double ans[maxn];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[i] = x;
    }
    vector < pair < double, int > > Q;
    for (int i = 1; i <= n; ++i) {
        Q.push_back({a[i], i});
        while ((int)Q.size() > 1) {
            int N = (int)Q.size();
            if (Q[N - 1].first < Q[N - 2].first) {
                double t = (Q[N - 1].first * (i - Q[N - 1].second + 1) + Q[N - 2].first * (Q[N - 1].second - Q[N - 2].second)) / (i - Q[N - 2].second + 1);
                int pos = Q[N - 2].second;
                Q.pop_back(), Q.pop_back();
                Q.push_back({t, pos});
            }
            else break;
        }
        //for (auto key : Q) cout << key.first << " " << key.second << endl;
        //cout << endl;
    }
    for (int i = 0; i < (int)Q.size() - 1; ++i) {
        for (int j = Q[i].second; j < Q[i + 1].second; ++j) ans[j] = Q[i].first;
    }
    for (int j = Q.back().second; j <= n; ++j) ans[j] = Q.back().first;
    for (int i = 1; i <= n; ++i) cout << fixed << setprecision(9) << ans[i] << '\n';
    return 0;
}