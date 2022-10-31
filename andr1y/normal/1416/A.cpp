// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
ll a[N], mx[N], lp[N];
pair<ll, ll> m2[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        for(ll i = 1;i<=n;i++){
            cin >> a[i];
            mx[i]=0;
            lp[i]=0;
            m2[i]={0, 0};
        }
        for(ll i = 1;i<=n;i++){
            mx[a[i]]=max(mx[a[i]], i-lp[a[i]]);
            lp[a[i]] = i;
        }
        for(ll i = 1;i<=n;i++) mx[i]=max(mx[i], n+1-lp[i]);
        for(ll i = 1;i<=n;i++) m2[i]={mx[i], i};
        sort(m2+1, m2+n+1);
        ll last_less = 0, nm = n+n;
        for(ll i = 1;i<=n;i++){
            while(last_less+1<=n&&m2[last_less+1].first<=i){
                last_less++;
                nm=min(nm, m2[last_less].second);
            }
            if(nm==n+n) cout<<"-1 ";
            else cout<<nm << ' ';
        }
        cout<<'\n';
    }
}