#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a = {0};
    for(char c : s)
        a.push_back(a.back() + c - '0' - 1);
    map<int, ll> occ;
    for(int x : a)
        ++occ[x];

    ll ans = 0;
    for(auto e : occ)
        ans += e.second * (e.second - 1) / 2;
    cout << ans << endl;

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