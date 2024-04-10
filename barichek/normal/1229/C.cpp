//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
 
using namespace std;
///#define int long long
 
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
 
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;
 
///---program start---///
 
#define arr (int)(1e5+10)
 
const int B=80;
/**
 
m*(n/B)+q*B*log
N*N/B==N*B*log
N/B=B*log
B*B=N/log
 
*/
 
vi reb[arr];
int req[arr];
int l[arr];
int e[arr];
int cur_pos[arr];
 
ll ans=0;
 
set<pii> edges;
 
main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
 
    fast;
 
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edges.insert(mp(u,v));
        edges.insert(mp(v,u));
 
        if (u>v){
            swap(u,v);
        }
 
        e[v]++;
 
        reb[u].pb(v);
        reb[v].pb(u);
 
        l[u]++;
        l[v]++;
 
        cur_pos[i]=i;
    }
    auto upd=[&](int pos,int kf)
    {
        if (kf==+1){
//            cout<<"upd :: "<<pos<<" "<<l[pos]<<" "<<e[pos]<<"\n";
            ans+=1ll*l[pos]*e[pos]-1ll*e[pos]*e[pos];
        }
        else{ /// -1
            ans-=1ll*l[pos]*e[pos]-1ll*e[pos]*e[pos];
        }
    };
    for (int i=1;i<=n;i++){
        upd(i,+1);
    }
 
    int q;
    cin>>q;
    set<int> cur;
    cout<<ans<<"\n";
    for (int i=1;i<=q;i++){
//        cout<<"req :: "<<i<<"\n";
        if (len(cur)%B==0){
            cur.clear();
        }
        int now;
        cin>>now;
        if (cur.count(now)){
            for (auto wh:cur){
                if (edges.count(mp(now,wh))){
                    if (cur_pos[wh]<cur_pos[now]){
                        upd(now,-1);
                        e[now]--;
                        upd(now,+1);
                    }
                    else{
                        upd(wh,-1);
                        e[wh]--;
                        upd(wh,+1);
                    }
                }
            }
            upd(now,-1);
            e[now]=l[now];
            upd(now,+1);
        }
        else{
            for (auto wh:reb[now]){
                if (cur_pos[wh]<cur_pos[now]){
                    upd(now,-1);
                    e[now]--;
                    upd(now,+1);
                }
                else{
                    upd(wh,-1);
                    e[wh]--;
                    upd(wh,+1);
                }
            }
            upd(now,-1);
            e[now]=l[now];
            upd(now,+1);
            cur.insert(now);
        }
        cur_pos[now]=n+i;
        cout<<ans<<"\n";
    }
}