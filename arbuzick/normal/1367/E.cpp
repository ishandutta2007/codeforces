#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(26);
        for(int i = 0; i < n; ++i)
            cnt[s[i]-'a']++;
        for(int ans = n; ans > 0; --ans){
            int k1 = 0;
            vector<bool> used(ans);
            for(int j = 0; !used[j]; j = (j+k)%ans){
                k1++;
                used[j] = 1;
            }
            int k2 = ans/k1;
            for(int i = 0; i < 26; ++i)
                k2 -= cnt[i]/k1;
            if(k2 <= 0){
                cout << ans << '\n';
                break;
            }
        }
    }
	return 0;
}