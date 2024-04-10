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

const int N=1e6+10;

int t[4*N];
int push[4*N];

void make_push(int v)
{
    t[v*2]+=push[v];
    t[v*2+1]+=push[v];
    
    push[v*2]+=push[v];
    push[v*2+1]+=push[v];
    
    push[v]=0;
}

void upd(int v,int l,int r,int tl,int tr,int val)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        t[v]+=val;
        push[v]+=val;
        return;
    }
    make_push(v);
    int m=(l+r)/2;
    
    upd(v*2,l,m,tl,tr,val);
    upd(v*2+1,m+1,r,tl,tr,val);
    
    t[v]=min(t[v*2],t[v*2+1]);
}

int get_1()
{
    return t[1];
}

int a[arr];
int ca[arr];

int x[arr];
int y[arr];
int z[arr];

int best_cb[N];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    fast;
    
    int n,m,p;
    cin>>n>>m>>p;
    
    for (int i=0;i<N;i++){
        best_cb[i]=inf;
    }
    
    for (int i=0;i<n;i++){
        cin>>a[i]>>ca[i];
    }
    for (int i=0;i<m;i++){
        int b,cb;
        cin>>b>>cb;
        best_cb[b]=min(best_cb[b],cb);
    }
    for (int i=0;i<p;i++){
        cin>>x[i]>>y[i]>>z[i];
    }
    
    for (int i=0;i<N;i++){
        upd(1,0,N-1,i,i,best_cb[i]);
    }
    
    vector<pair<pii,int>> events;
    for (int i=0;i<n;i++){
        events.pb(mp(mp(a[i],0),i));
    }
    for (int i=0;i<p;i++){
        events.pb(mp(mp(x[i],1),i));
    }
    
    int ans=inf;
    
    sort(all(events));
    for (auto q:events){
        int type=q.fir.sec;
        int id=q.sec;
        if (type==0){
            int cur_ans=ca[id]+get_1();
            ans=min(ans,cur_ans);
        }
        else{
            upd(1,0,N-1,y[id]+1,N-1,-z[id]);
        }
    }
    cout<<-ans<<"\n";
}