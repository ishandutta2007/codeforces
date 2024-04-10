#include <bits/stdc++.h>
typedef int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll seg[N*4];
void shift(ll nod){
    seg[nod*2]=min(seg[nod*2],seg[nod]);
    seg[nod*2+1]=min(seg[nod*2+1],seg[nod]);
}
void upd(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return;
    if (l>=L && r<=R){
        seg[nod]=0;
        return ;
    }
    shift(nod);
    ll mid=(r+l)/2;
    upd(nod*2,l,mid,L,R);
    upd(nod*2+1,mid,r,L,R);
    seg[nod]=seg[nod*2]+seg[nod*2+1];
}
ll get(ll nod,ll l,ll r,ll L,ll R){
    if (l>=R || L>=r) return 0;
    if (l>=L && r<=R) return seg[nod];
    shift(nod);
    ll mid=(r+l)/2;
    return get(nod*2,l,mid,L,R)+get(nod*2+1,mid,r,L,R);
}
void build(ll nod,ll l,ll r){
    seg[nod]=r-l;
    if (r-l==1) return ;
    ll mid=(r+l)/2;
    build(nod*2,l,mid);
    build(nod*2+1,mid,r);
}
pii ask[N];
ll le[N],re[N];
vector <int> q[N];
ll fen[N];
void add(ll idx,ll val){
    for (;idx<N;idx +=idx & (-idx)) fen[idx]+=val;
}
ll getfen(ll idx){
    ll s=0;
    for (;idx;idx-=idx & (-idx)) s+=fen[idx];
    return s;
}
int Main(){
    ll n,tq;
    cin >> n >> tq;
    vector <pair <int,pair <pii,int> > > Q;
    for (int i=0;i<tq;i++){
        ll t;
        cin >> t;
        if (t==0){
            ll l,r,x;
            cin >> l >> r >> x;
            Q.pb({t,{{l,r},x}});
            if (x==0){
                re[i]=i+1;
                le[i]=i;
            }
            else {
                re[i]=tq;
                le[i]=i;
                /// dorostesh kon
            }
        }
        else{
            ll j;
            cin >> j;
            Q.pb({t,{{j,-1},-1}});
            re[i]=0;
            le[i]=0;
        }
    } 
    for (int i=0;i<20;i++){
        build(1,1,n+1);
        for (int j=0;j<=tq;j++) q[j].clear();
        for (int j=0;j<tq;j++){
            if (Q[j].F==0){
                if (Q[j].S.S==1 && re[j]-le[j]>1){
                    ll mid=(le[j]+re[j])/2;
                    q[mid].pb(j);
                }
            }
        }
        for (int j=0;j<tq;j++){
            if (Q[j].F==0 && Q[j].S.S==0){
                upd(1,1,n+1,Q[j].S.F.F,Q[j].S.F.S+1);
            }
            for (auto u : q[j]){
               
                if (get(1,1,n+1,Q[u].S.F.F,Q[u].S.F.S+1)==1){
                    re[u]=(re[u]+le[u])/2;
                }
                else{
                    le[u]=(le[u]+re[u])/2;
                }
            }
        }
    }
    //cout << re[3] << " ejnf elfekrjnfkerng " << endl;
    build(1,1,n+1);
    for (int i=0;i<=tq;i++) q[i].clear();
    for (int i=0;i<tq;i++){
        if (Q[i].F==0 && Q[i].S.S==1) q[re[i]].pb(i);
    }
    for (int i=0;i<tq;i++){
        if (Q[i].F==0 && Q[i].S.S==0) upd(1,1,n+1,Q[i].S.F.F,Q[i].S.F.S+1);
        for (auto u : q[i]){
           // cout << i << " " << Q[u].S.F.F << " add " << Q[u].S.F.S+1 << endl;
            add(Q[u].S.F.F,1);
            add(Q[u].S.F.S+1,-1);
        }
        if (Q[i].F==1){
            ll id=Q[i].S.F.F;
            if (get(1,1,n+1,id,id+1)==0) cout << "NO" << endl;
            else if (getfen(id)>0) cout << "YES" << endl;
            else cout << "N/A" << endl;

        }
    }
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
  //  cin >> t;
    while(t--) Main();
}