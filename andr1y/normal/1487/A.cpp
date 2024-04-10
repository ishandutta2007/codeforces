// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 128;
ll a[N];
bool ban[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q=1;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        ll res=0;
        while(res<n&&a[res]==a[0]) res++;
        cout<<n-res<<'\n';
    }
}