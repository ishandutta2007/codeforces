#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 5e5 + 123;
const int mod = 1e9 + 7;
string s;
void solve() {
    cin >> s;
    vector<int> v;
    v.push_back(0);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') v.back()++;
        else v.push_back(0);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < v.size(); i+=2) ans += v[i];
    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}