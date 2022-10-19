#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

int n, ans;
vector<int> vec[4];

signed main () {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    while (n --) {
        string s; int a; cin >> s >> a;
        int type = 0;
        if (s[0] == '1') type += 2;
        if (s[1] == '1') type += 1;
        vec[type].pb(a);
    }

    for (int i = 0; i < 4; ++i) sort(vec[i].begin(), vec[i].end() ), reverse(vec[i].begin(), vec[i].end() );

    for (int _ : vec[3]) ans += _;
    for (int i = 0; i < min(vec[1].size(), vec[2].size() ); ++i) ans += vec[1][i] + vec[2][i];

    for (int i = min(vec[1].size(), vec[2].size() ); i < vec[1].size(); ++i) vec[0].pb(vec[1][i]);
    for (int i = min(vec[1].size(), vec[2].size() ); i < vec[2].size(); ++i) vec[0].pb(vec[2][i]);

    sort(vec[0].begin(), vec[0].end() );
    reverse(vec[0].begin(), vec[0].end() );

    for (int i = 0; i < min(vec[0].size(), vec[3].size() ); ++i) ans += vec[0][i];

    cout << ans;

    return 0;
}