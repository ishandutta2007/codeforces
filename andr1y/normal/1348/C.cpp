//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll cnt[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        string s;
        cin >> n >> k >> s;
        for(ll i= 0;i<26;i++) cnt[i]=0;
        sort(begin(s), end(s));
        for(ll i = 0;i<n;i++) cnt[s[i]-'a']++;
        ll fb = s[0]-'a';
        if(cnt[fb]<k) cout << s[k-1] << '\n';
        else{
            if(cnt[fb] > k&&cnt[fb]!=n) cout << s[0] << s.substr(k) << '\n';
            else{
                if(s[k] == s[n-1]){
                    if(cnt[fb]!=n) cout << s[0];
                    ll u = cnt[s[k]-'a']/k+(cnt[s[k]-'a']%k?1:0);
                    for(ll j = 0;j<u;j++) cout << s[k];
                    cout << '\n';
                }else{
                    cout << s[0] << s.substr(k) << '\n';
                }
            }
        }
    }
}