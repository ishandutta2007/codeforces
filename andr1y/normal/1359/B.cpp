//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1228;
ll dp[N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m, x, y, r=0;
        cin >> n >> m >> x >> y;
        y=min(y, x+x);
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++) dp[j]=0;
            char bf = '*';
            for(ll j = 0;j<m;j++){
                char c;
                cin >> c;
                if(c=='.') dp[j]=(j?dp[j-1]:0)+x;
                if(bf=='.'&&c=='.') dp[j]=(j-1?dp[j-2]:0)+y;
                if(c=='*') dp[j]=(j?dp[j-1]:0);
                bf=c;
            }
            r+=dp[m-1];
        }
        cout<<r<<'\n';
    }
}