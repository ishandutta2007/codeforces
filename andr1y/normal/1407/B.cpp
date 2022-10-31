// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e3+228;
ll cnt[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        memset(cnt, 0, sizeof(cnt));
        ll n;
        cin >> n;
        for(ll a, i=0;i<n;i++){
            cin >> a;
            cnt[a]++;
        }
        ll gcdn = 0;
        for(ll i = 0;i<n;i++){
            ll mv=0, mp=-1;
            for(ll j = 1000;j;j--){
                if(cnt[j]){
                    ll e = __gcd(gcdn, j);
                    if(e>mv){
                        mv=e, mp=j;
                    }
                }
            }
            cnt[mp]--;
            gcdn=mv;
            cout<<mp<<' ';
        }
        cout<<'\n';
	}
}