// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N], b[N], c[N], p[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i =0;i<n;i++){
            cin >> a[i];
            p[i] = a[i];
        }
        for(ll i = 0;i<n;i++){
            cin >> b[i];
        }
        for(ll i = 0;i<n;i++){
            cin >> c[i];
        }
        for(ll i = 1;i<n;i++){
            if(p[i]==p[i-1]) p[i]=b[i];
        }
        if(p[n-1]==p[0]){
            p[n-1]=(p[n-2]==b[n-1]||p[0]==b[n-1]?c[n-1]:b[n-1]);
        }
        for(ll i = 0;i<n;i++) cout<<p[i]<<' ';
        cout<<'\n';
    }
}