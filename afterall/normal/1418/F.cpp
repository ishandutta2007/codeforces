#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
/// ajab giri kardim
vector <int> p[N];
pair <pii,int> ans[N];
set <int> s;
ll cnt[N];
ll last[N];
void add(ll x){
    for (auto u : p[x]){
        cnt[u]++;

        if (cnt[u]==1)
            s.insert(u);
        last[u]=x;
    }
}
void del(ll x){
    for (auto u : p[x]){
            cnt[u]--;
        if (cnt[u]==0)
            s.erase(u);
    }
}
int Main(){
    ll n,m,l,r;
    cin >> n >> m >> l >> r;
    for (int i=1;i<N;i++){
        for (int j=i;j<N;j+=i){
            p[j].pb(i);
        }
    }
    vector <pair <pii,pii> > baze;
    for (int i=1;i<=n;i++){
        for (auto u : p[i]){
            ll ly=(l+i-1)/(ll)i,ry=r/(ll)i;
            ry=min(ry,m);
            if (ly>ry) continue;
            baze.pb({{ly,ry},{u,i}});
        }
    }
    reverse(baze.begin(),baze.end());
    ll pl=1,pr=0;
    for (int i=0;i<baze.size();i++){
        int l=baze[i].F.F,r=baze[i].F.S;
        while(pr<r){
            pr++;
            add(pr);
        }
        while(pl<l){
            del(pl);
            pl++;
        }
        int x=baze[i].S.F;
        auto it=s.lower_bound(x+1);
        if (it!=s.end()){
            int b=*it;
            int id=baze[i].S.S;
            if (id/x>n/b) continue;
            if (id/x*b<=n){
                ans[id]={{x,b},last[*it]};
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (ans[i].F.F==0) cout << -1 << endl;
        else{
cout << i << " " << ans[i].S << " " << i/ans[i].F.F*ans[i].F.S << " " << ans[i].S/ans[i].F.S*ans[i].F.F << endl;

        }
    }

}
int32_t main(){
    sync;
    ll t;
    t=1;
    while(t--)Main();
}