#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

const ll mod = 998244353;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    #ifdef Local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);                                
    #endif     

    int t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0' && s[i - 1] == '0') ans += 2;
            else if (i > 1 && s[i] == '0' && s[i - 1] == '1' && s[i - 2] == '0') {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}