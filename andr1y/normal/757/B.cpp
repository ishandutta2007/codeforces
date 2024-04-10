// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], cnt[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;cin>>n;
    for(ll i = 0;i<n;i++){
        cin >> a[i];
        ll oa=a[i];
        for(ll j = 2;j*j<=oa;j++){
            ll c=0;
            while(a[i]%j==0){
                a[i]/=j;
                c++;
            }
            if(c) cnt[j]++;
        }
        if(a[i]>1) cnt[a[i]]++;
    }
    ll res=1;
    for(ll i = 2;i<N;i++) res=max(res, cnt[i]);
    cout<<res;
}