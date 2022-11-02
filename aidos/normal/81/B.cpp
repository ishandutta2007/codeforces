#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
string s, ans;
void solve() {
    getline(cin, s);
    for(int i = 0; i < s.size(); ) {
        if(s[i] == ' ') {
            if(ans.size() > 0 && ans.back() != ' ') ans += ' ';
            i++;
            continue;
        }
        if(s[i] == ',') {
            while(ans.size() > 0 && ans.back() == ' ') ans.pop_back();
            if(ans.size() > 0 && ans.back() == ',') ans += ' ';
            ans += ", ";
            i++;
            continue;
        }
        if(s[i] == '.') {
            if(ans.size() > 0 && ans.back() != ' ') {
                ans += ' ';
            }
            ans += '.';
            ans += '.';
            ans += '.';
            i += 3;
            while(i < s.size() && s[i] == ' ') i++;
            continue;
        }
        
        ans += s[i];
        i++;
    }
    while(ans.size() > 0 && ans.back() == ' ') ans.pop_back();
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}