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
#define int long long

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
const ll inf=1e18+10;

///---program start---///

int n,m,k;
vi reb[arr];

void bfs(int start,vi& dist)
{
    dist[start]=0;
    queue<int> q;
    q.push(start);
    while (!q.empty()){
        int now=q.front();
        q.pop();
        for (auto wh:reb[now]){
            if (dist[wh]>dist[now]+1){
                dist[wh]=dist[now]+1;
                q.push(wh);
            }
        }
    }
}

vi in_order_of_dec_dist1;
vi in_order_of_inc_distn;
vi dist1;
vi distn;

pair<pii,pii> max_on_suf[arr];

void update(pair<pii,pii>& a,pii b)
{
    if (a.fir<b){
        a=mp(b,a.fir);
    }
    else if (a.sec<b){
        a.sec=b;
    }
}

bool check(int x)
{
    // cout<<"check :: "<<x<<"\n";
    max_on_suf[k]=mp(mp(-inf,-1),mp(-inf,-1));
    for (int i=k-1;i>=0;i--){
        // cout<<in_order_of_inc_distn[i]<<" ";
        max_on_suf[i]=max_on_suf[i+1];
        update(max_on_suf[i],mp(dist1[in_order_of_inc_distn[i]],in_order_of_inc_distn[i]));
    }
    // cout<<"\n";
    
    int p=0;
    for (int i=0;i<k;i++){
        while (p<k&&dist1[in_order_of_dec_dist1[i]]+distn[in_order_of_inc_distn[p]]<x){
            p++;
        }
        pair<pii,pii> best=max_on_suf[p];
        // cout<<"best :: "<<best.fir.fir<<" "<<best.fir.sec<<" "<<best.sec.fir<<" "<<best.sec.sec<<"\n";
        int val=(best.fir.sec!=in_order_of_dec_dist1[i] ? best.fir.fir : best.sec.fir);
        
        if (val+distn[in_order_of_dec_dist1[i]]>=x){
            // cout<<"val :: "<<val<<"\n";
            // cout<<"res :: "<<in_order_of_dec_dist1[i]<<" "<<p<<"\n";
            return 1;
        }
    }
    
    return 0;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    fast;
    
    cin>>n>>m>>k;
    vi a(k);
    for (auto& i:a){
        cin>>i;
    }
    while (m--){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    dist1.assign(n+1,inf);
    bfs(1,dist1);
    distn.assign(n+1,inf);
    bfs(n,distn);
    
    for (auto i:a){
        in_order_of_dec_dist1.pb(i);
        in_order_of_inc_distn.pb(i);
    }
    sort(all(in_order_of_dec_dist1), [&](int a,int b){
        return dist1[a]>dist1[b];
    });
    sort(all(in_order_of_inc_distn), [&](int a,int b){
        return distn[a]<distn[b];
    });
    
    // for (int i=1;i<=n;i++){
    //     cout<<dist1[i]<<" ";
    // }
    // cout<<"\n";
    // for (int i=1;i<=n;i++){
    //     cout<<distn[i]<<" ";
    // }
    // cout<<"\n";
    
    int ans = dist1[n];
    
    int l=0,r=n;
    while (r-l>0){
        int m=(l+r+1)/2;
        // cout<<"l r :: "<<l<<" "<<r<<"\n";
        if (check(m)){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    
    
    // cout<<"l+1 :: "<<l+1<<"\n";
    cout<<min(ans,l+1)<<"\n";
}