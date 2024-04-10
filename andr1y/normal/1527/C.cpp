// -- //
#include <bits/stdc++.h>
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
map<ll, vector<ll>> poses;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;cin>>q;
    while(q--){
        ll n;
        cin>>n;
        for(ll i = 0;i<n;i++){
            cin>>a[i];poses[a[i]].push_back(i);
        }
        ll res=0;
        for(auto &i : poses){
            ll decsum=0, dec2=0, last=-1;
            for(ll jj = 0;jj<i.y.size();jj++){
                ll j = i.y[jj];
                ll j2 = (jj==i.y.size()-1?n:i.y[jj+1]);
                res+=decsum*(n-j);
                decsum+=j+1;
            }
        }
        cout<<res<<'\n';
        poses.clear();
    }
}