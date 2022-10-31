// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
ll tn[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        ll tc=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            if(a[i]==1){
                tn[tc++]=1;
            }else{
                for(ll j = tc-1;j>=0;j--){
                    if(tn[j]==a[i]-1){
                        tn[j]=a[i];
                        break;
                    }else tc--;
                }
            }
            cout<<tn[0];
            for(ll j = 1;j<tc;j++) cout<<'.'<<tn[j];
            cout<<'\n';
        }
    }
}