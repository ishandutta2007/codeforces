// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], b[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        ll l = 0, r=n-1, k=0;
        for(ll i = 0;i<n;i++){
            if(i&1) b[k++]=a[r--];
            else b[k++]=a[l++];
        }
        for(ll i = 0;i<n;i++) cout<<b[i]<<' ';
        cout<<'\n';
    }
}