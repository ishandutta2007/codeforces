#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> v;
    long long time1, time2;
    for (long long i = 0; i < n; ++i) {
        cin >> time1 >> time2;
        v.push_back({time1, 0});
        v.push_back({time2, 2});
    }
    long long m;
    cin >> m;
    for (long long i = 0; i < m; ++i) {
        cin >> time1 >> time2;
        v.push_back({time1, 1});
        v.push_back({time2, 3});
    }
    sort(v.begin(), v.end());
    long long first_1 = 2e9;
    long long first_2 = 2e9;
    long long ans = 0;
    for (long long i = 0; i < v.size(); ++i) {
        if (v[i].second == 2 && first_1 == 2e9)
            first_1 = v[i].first;
        if (v[i].second == 3 && first_2 == 2e9)
            first_2 = v[i].first;
        if (v[i].second == 0)
            ans = max(ans, v[i].first - first_2);
        if (v[i].second == 1)
            ans = max(ans, v[i].first - first_1);
    }
    cout << ans;
}