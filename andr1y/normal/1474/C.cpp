// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e6+228;
ll a[N];
ll cnt[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        n=n+n;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
        }
        bool ff=0;
        vector<pll> ops;
        sort(a, a+n, greater<ll>());
        for(ll i = 1;i<n&&!ff;i++){
            for(ll j = 0;j<n;j++){
                cnt[a[j]]++;
            }
            cnt[a[0]]--;
            cnt[a[i]]--;
            ll sx = a[0];
            ll ssx = a[0]+a[i];
            vector<pll> ops;
            ops.push_back({a[0],a[i]});
            bool ok = 1;
            for(ll j = 1;j<n&&ok;j++){
                if(cnt[a[j]]){
                    ll df = sx-a[j];
                    if(df>0 && ((df!=a[j] && cnt[df]) || (df==a[j]&&cnt[df]>1))){
                        cnt[df]--;
                        cnt[a[j]]--;
                        ops.push_back({a[j], df});
                        sx=max(df, a[j]);
                    }else{
                        ok=0;
                    }
                }
            }
            if(ok){
                ff=1;
                cout<<"YES\n";
                cout<<ssx<<'\n';
                for(auto i : ops) cout<<i.x << ' '<<i.y<<'\n';
            }
            for(ll j = 0;j<n;j++) cnt[a[j]]=0;
        }
        if(!ff) cout<<"NO\n";
        //
    }
}