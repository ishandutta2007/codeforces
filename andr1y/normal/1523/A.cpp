// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll en[N], ec=0;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin>>q;
    while(q--){
        ll n, m;cin >> n>>m;
        string s;cin>>s;
        for(ll i = 0;i<m;i++){
            ec=0;
            for(ll j = 0;j<n;j++){
                if(s[j]=='1') continue;
                ll e = (j&&s[j-1]=='1'?1:0)+(j+1<n&&s[j+1]=='1'?1:0);
                if(e==1) en[ec++]=j;
            }
            if(!ec) break;
            for(ll j=0;j<ec;j++) s[en[j]]='1';
        }
        cout<<s<<'\n';
    }
}