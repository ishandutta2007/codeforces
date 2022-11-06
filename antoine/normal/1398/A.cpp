#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; ++i) {
        v[i].second = i;
        cin >> v[i].first;
    }
    sort(v.begin(), v.end());
    if(v[0].first + v[1].first <= v[n-1].first)
        cout << v[0].second + 1 << ' ' << v[1].second + 1 << ' ' << v[n-1].second + 1 << '\n';
    else
        cout << "-1\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
int t;
cin >> t;
for(int i = 0; i < t; ++i)
    f();
    return 0;
}