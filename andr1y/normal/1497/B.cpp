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
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<m;i++) b[i]=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            a[i]%=m;
            b[a[i]]++;
        }
        ll res=(b[0]?1:0);
        for(ll i = 1;i<=m-i;i++){
            if(i==m-i){
                if(b[i]) res++;
            }else{
                ll ca = b[i], cb = b[m-i];
                if(ca>cb) swap(ca, cb);
                if(cb) res+=max(0ll, cb-ca-1)+1;
            }
        }
        cout<<res<<'\n';
    }
}