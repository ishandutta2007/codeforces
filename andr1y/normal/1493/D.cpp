// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+5;
const ll NP = 18000;
const ll M = 1e9+7;
ll prm[N], pc=0, lp[N];
ll prc[N];
priority_queue<pll, vector<pll>, greater<pll>> pq[NP];
ll act[NP];
map<ll, ll> innow[N];
ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return (a*bpm(a*a, b>>1))%M;
    else return bpm(a*a, b>>1);
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(ll i = 2;i<N;i++){
        if(!lp[i]){
            lp[i]=i;
            prm[pc++]=i;
            prc[i]=pc-1;
        }
        for(ll j = 0;j<pc&&prm[j]<=lp[i]&&prm[j]*i<N;j++) lp[prm[j]*i]=prm[j];
    }
    ll n, q;
    cin >> n >> q;
    for(ll a, i = 0;i<n;i++){
        cin >> a;
        for(ll j = 2;j*j<=a;j++){
            ll c=0;
            while(a%j==0){
                a/=j, c++;
            }
            if(c){
                innow[i][prc[j]]=c;
                pq[prc[j]].push({c, i});
                act[prc[j]]++;
            }
        }
        if(a>1){
            innow[i][prc[a]]=1;
            pq[prc[a]].push({1, i});
            act[prc[a]]++;
        }
    }
    ll res=1;
    for(ll i  =0;i<pc;i++){
        if(act[i]==n){
            res*=bpm(prm[i], pq[i].top().x);
            res%=M;
        }
    }
    for(ll qq=0;qq<q;qq++){
        ll p, a;
        cin >> p >> a;
        --p;
        for(ll j = 2;j*j<=a;j++){
            ll c=0;
            while(a%j==0){
                a/=j, c++;
            }
            if(c){
                if(act[prc[j]]==n) res=(res*bpm(bpm(j, pq[prc[j]].top().x), M-2))%M;
                ll nold=innow[p][prc[j]];
                ll nup = nold+c;
                innow[p][prc[j]]=nup;
                pq[prc[j]].push({nup, p});
                while(innow[pq[prc[j]].top().y][prc[j]]>pq[prc[j]].top().x) pq[prc[j]].pop();
                if(nold==0){
                    act[prc[j]]++;
                }
                if(act[prc[j]]==n) res=(res*bpm(j, pq[prc[j]].top().x))%M;
            }
        }
        if(a>1){
            ll j=a;
            if(act[prc[j]]==n) res=(res*bpm(bpm(j, pq[prc[j]].top().x), M-2))%M;
            ll nold=innow[p][prc[j]];
            ll nup = nold+1;
            innow[p][prc[j]]=nup;
            pq[prc[j]].push({nup, p});
            while(innow[pq[prc[j]].top().y][prc[j]]>pq[prc[j]].top().x) pq[prc[j]].pop();
            if(nold==0){
                act[prc[j]]++;
            }
            if(act[prc[j]]==n) res=(res*bpm(j, pq[prc[j]].top().x))%M;
        }
        cout<<res<<'\n';
    }
}