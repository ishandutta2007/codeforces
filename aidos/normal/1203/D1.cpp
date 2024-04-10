#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;
string s, t;
void solve() {
    cin >> s >> t;
    int pos = 0;
    vector<int> a, b;
    for(int i = 0; i < t.size(); i++) {
        while(s[pos] != t[i]) pos++;
        a.push_back(pos);
        pos++;
    }
    pos = s.size()-1;
    for(int i = t.size()-1; i >= 0; i--) {
        while(s[pos] != t[i]) pos--;
        b.push_back(pos);
        pos--;
    }
    reverse(b.begin(), b.end());
    int ans = max(b[0], (int)s.size() - a.back() - 1);
    for(int i = 1; i < a.size(); i++) {
        ans = max(ans, b[i] - a[i-1] - 1);
    }
    cout << ans << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}