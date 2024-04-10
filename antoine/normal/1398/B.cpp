#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
    string s;
    cin >> s;
    vector<int> v;
    for(int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '1' && (i == 0 || s[i-1] == '0')) {
            int j = i;
            while(j < (int)s.size() && s[i] == s[j])
                ++j;
            v.push_back(j-i);
        }
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for(int i = 0; i < (int)v.size(); i += 2)
        ans += v[i];
 cout << ans << '\n';
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