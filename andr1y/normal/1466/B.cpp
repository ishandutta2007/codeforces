// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll a[N];
ll cnt[N];
bool c2[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<=n+n+10;i++) cnt[i]=0, c2[i]=0;
        for(ll i =0;i<n;i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        ll res=0;
        for(ll i = 0;i<=n+n+10;i++){
            if(!cnt[i]) continue;
            if(cnt[i]>1) c2[i]=1, c2[i+1]=1;
            if(c2[i]&&cnt[i]==1) c2[i+1]=1;
            else c2[i]=1;
        }
        for(ll i = 0;i<=n+n+10;i++) res+=c2[i];
        cout<<res<<'\n';
    }
}