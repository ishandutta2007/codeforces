#include <bits/stdc++.h>
using namespace std;

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    long long n, k;
    cin >> n >> k;
    vector < pair <long long, long long> > p(n);
    for ( int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end());
    vector <long long> c(n);
    for ( int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector <long long> ans(n);
    multiset <long long> cost;
    for ( int i = 0; i < n; i++) {
        ans[p[i].second] = c[p[i].second];
        long long now = 0;
        long long d = 0;
        for ( auto it = cost.rbegin(); d < k && d < cost.size(); it++) {
            now += *it;
            d++;
        }
        ans[p[i].second] += now;
        cost.insert(c[p[i].second]);
    }
    for ( auto c : ans) {
        cout << c << " ";
    }


    return 0;
}