#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int ans[maxn];
void solve() {
    vector< pair<int, pair<int, int> > > a;
    for(int i = 0; i < 3; i++) {
        for(int j = i+1; j < 3; j++) {
            int d;
            cin >> d;
            a.push_back(make_pair(d, make_pair(i, j)));
        }
    }
    sort(a.begin(), a.end());
    if(a[1].first != a[2].first) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ans[a[0].second.first] = a[0].first;
    ans[a[0].second.second] = a[0].first;
    ans[3-a[0].second.first - a[0].second.second] = a[2].first;
    for(int i = 0; i < 3; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}