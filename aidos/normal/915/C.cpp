#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;



string s;
string t;
void solve() {
    cin >> s >> t;
    sort(s.begin(), s.end());
    if(s.size() < t.size()) {
        reverse(s.begin(), s.end());
        cout << s << "\n";
        return;
    }
    string ans = "";
    while(s.size() > 0) {
        int i = 0;
        while(i < s.size() && (ans + s[i] + s.substr(0, i) + s.substr(i+1)) <= t) {
            i++;
        }
        ans += s[i-1];
        s.erase(i-1, 1);
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