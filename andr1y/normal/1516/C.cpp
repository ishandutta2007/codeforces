// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200000+228;
ll a[N];
ll n;
bitset<N> bts;
bool isok(){
    bts[0]=1;
    ll sum=0;
    for(ll i = 0 ;i<n;i++){
        sum+=a[i];
        bts|=(bts<<a[i]);
    }
    if(sum&1) return 1;
    if(bts[sum/2]) return 0;
    else return 1;
}
ll solve(){
    ll odc=0, odp=-1;
    for(ll i = 0;i<n;i++){
        if(a[i]&1){
            odc++, odp=i;
        }
    }
    if(odc){
        return odp;
    }
    for(ll i= 0;i<n;i++) a[i]>>=1;
    return solve();
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> n;
    for(ll i =0;i<n;i++){
        cin >> a[i];
    }
    bool e  =isok();
    if(e){
        cout<<"0\n";
        return 0;
    }
    cout<<"1\n"<<solve()+1<<'\n';
}