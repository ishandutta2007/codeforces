// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
ll b[N], bc, c[N], cc;
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
        deque<ll> tr;
        sort(a, a+n);
        bc=0, cc=0;
        for(ll i = 0;i<n;i++){
            if(i&&a[i]==a[i-1]){
                c[cc++]=a[i];
            }else b[bc++]=a[i];
        }
        for(ll i = 0;i<cc;i++) b[bc++]=c[i];
        for(ll i= 0;i<n;i++)cout<<b[i]<<' ';
        cout<<'\n';
    }
}