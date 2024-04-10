// keep calm and eat pizza.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 15;
ll prm[N], prc=0;
ll mid[N];
vector<ll> cnt[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll q;
	cin >> q;
	while(q--){
        for(ll i = 0;i<N;i++) cnt[i].clear();
        ll n;
        cin >> n;
        map<ll, ll> ds;
        set<ll> dils2;
        ll on=n, sk=0;
        prc=0;
        for(ll i = 1;i*i<=n;i++){
            if(i!=1)
            while(on%i==0){
                on/=i;
                ds[i]++;
                ++sk;
            }
            if(n%i==0){
                if(i^1) dils2.insert(i);
                dils2.insert(n/i);
            }
        }
        if(on-1) ds[on]++, sk++;
        if(ds.size()==1){
            for(auto i : dils2) cout<<i<<' ';
            cout<<"\n0\n";
            continue;
        }
        for(auto i : ds){
            prm[prc++]=i.first;
            cnt[prc-1].push_back(i.first);
            dils2.erase(i.first);
        }
        if(sk==2&&ds.size()==2){
            cout<<prm[0]<<' ' <<prm[1]<<' '<<n<<'\n'<<1<<'\n';
            continue;
        }
        for(ll i = 0;i<prc;i++){
            ll k = prm[i]*prm[(i+1)%prc];
            dils2.erase(k);
            mid[i]=k;
            if(i==prc-1&&ds.size()==2){
                if(ds[prm[0]]>1){
                    dils2.erase(k*prm[0]);
                    mid[i]=k*prm[0];
                }else if(ds[prm[1]]>1){
                    dils2.erase(k*prm[1]);
                    mid[i]=k*prm[1];
                }
            }
        }
        for(auto i : dils2){
            for(ll j = 0;j<prc;j++) {
                if(i%prm[j]==0){
                    cnt[j].push_back(i);
                    break;
                }
            }
        }
        for(ll i = 0;i<prc;i++){
            for(auto j : cnt[i]) cout<<j<<' ';
            cout<<mid[i]<<' ';
        }
        cout<<"\n0\n";
	}
}