// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 228;
ll cnt[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for(ll a, i = 0;i<n;i++){
            cin >> a;
            cnt[a]++;
        }
        ll r=0, r2=0;
        for(ll i = 0;i<=100;i++){
            if(cnt[i]>1){
                if(r==i) ++r;
                if(r2==i) ++r2;
            }
            if(cnt[i]==1){
                if(r==i) ++r;
            }
        }
        cout<<r+r2<<'\n';
    }
}