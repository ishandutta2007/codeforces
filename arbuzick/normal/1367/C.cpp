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
        vector<int> pr(n+1);
        for(int i = 0; i < n; ++i)
            pr[i+1] = pr[i]+s[i]-'0';
        int ans = 0;
        int pr1 = -n-1;
        for(int i = 0; i < n; ++i){
            if(pr1+k < i && pr[min(n, i+k+1)]-pr[i] == 0)
                ans++, pr1 = i;
            if(s[i] == '1')
                pr1 = i;
        }
        cout << ans << '\n';
    }
}