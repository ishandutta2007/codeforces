// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, x;
        cin >> n >> x;
        for(ll i = 0;i<n;i++)cin>>a[i];
        sort(a, a+n);
        vector<ll> tk;
        bool ok=1;
        for(ll i = 0;i<n;i++){
            if(a[i]==x){
                if(i+1<n){
                    tk.push_back(a[i+1]);
                    tk.push_back(a[i]);
                    x-=a[i+1];
                    x-=a[i];
                    i++;
                    continue;
                }else ok=0;
            }else{
                tk.push_back(a[i]);
                x-=a[i];
            }
        }
        if(ok){
            cout<<"YES\n";
            for(auto i : tk) cout<<i<<' ';
            cout<<'\n';
        }else cout<<"NO\n";
    }
}