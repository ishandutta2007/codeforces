#include <bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int lef[maxn];
int righ[maxn];
vector < int > pos[27];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), k = (int)t.size();
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    int my_pos = -1;
    for (int i = 0; i < (int)t.size(); ++i) {
        my_pos = upper_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), my_pos) - pos[t[i] - 'a'].begin();
        my_pos = pos[t[i] - 'a'][my_pos];
        lef[i] = my_pos;
    }
    my_pos = n + 1;
    for (int i = (int)t.size() - 1; i >= 0; --i) {
        my_pos = lower_bound(pos[t[i] - 'a'].begin(), pos[t[i] - 'a'].end(), my_pos) - pos[t[i] - 'a'].begin() - 1;
        my_pos = pos[t[i] - 'a'][my_pos];
        righ[i] = my_pos;
    }
    //cout << lef[k - 1] << '\n';
    int ans = max(righ[0], n - lef[k - 1] - 1);
    for (int i = 0; i < (int)t.size() - 1; ++i) {
        ans = max(ans, righ[i + 1] - lef[i] - 1);
    }
    cout << ans << '\n';
    return 0;
}