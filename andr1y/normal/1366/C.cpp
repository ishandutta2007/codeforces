//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 31;
ll a[N][N];
ll cnt[N+N+5][2];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i = 0;i<n+m-1;i++) cnt[i][0]=cnt[i][1]=0;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> a[i][j];
                if(a[i][j]) cnt[i+j][1]++;
                else cnt[i+j][0]++;
            }
        }
        ll ch=0;
        for(ll dg=0;dg<n+m-1;dg++){
            ll d2 = n+m-2-dg;
            if(dg>=d2) break;
            ll c0 = cnt[dg][0]+cnt[d2][0];
            ll c1 = cnt[dg][1]+cnt[d2][1];
            ch+=min(c0, c1);
        }
        cout<<ch<<'\n';
    }
}