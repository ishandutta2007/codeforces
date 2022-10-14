#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> a;
int n;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    a.resize(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        ans = max(ans, a[i].first + a[i].second);
    }
    cout << ans;
    return 0;
}