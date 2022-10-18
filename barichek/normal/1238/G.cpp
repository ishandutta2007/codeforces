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

#define arr (int)(5e5+10)
#define arr1 (int)(2e6+10)

int t[arr1];
int a[arr1];
int b[arr];
vi vh[arr];
int tt[arr];

int tree[4*arr];
int push[4*arr];

void clear(int v,int l,int r)
{
    if (v>=4*arr){
        while (1){

        }
    }
    t[v]=0;
    push[v]=0;
    if (l==r){
        return;
    }
    int m=(l+r)/2;
    clear(v*2,l,m);
    clear(v*2+1,m+1,r);
}

void make_push(int v)
{
    if (v*2+1>=4*arr){
        while (1){

        }
    }
    t[v*2]+=push[v];
    t[v*2+1]+=push[v];

    push[v*2]+=push[v];
    push[v*2+1]+=push[v];

    push[v]=0;
}

void upd1(int v,int l,int r,int pos,int val)
{
    if (v>=4*arr){
        while (1){

        }
    }
    if (l==r){
        t[v]=val;
        return;
    }
    int m=(l+r)/2;
    make_push(v);
    if (pos<=m){
        upd1(v*2,l,m,pos,val);
    }
    else{
        upd1(v*2+1,m+1,r,pos,val);
    }
    t[v]=max(t[v*2],t[v*2+1]);
}

void upd2(int v,int l,int r,int tl,int tr,int val)
{
    if (v>=4*arr){
        while (1){

        }
    }
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        t[v]+=val;
        push[v]+=val;
        return;
    }
    int m=(l+r)/2;
    make_push(v);
    upd2(v*2,l,m,tl,tr,val);
    upd2(v*2+1,m+1,r,tl,tr,val);
    t[v]=max(t[v*2],t[v*2+1]);
}

int get(int v,int l,int r,int tl,int tr)
{
    if (v>=4*arr){
        while (1){

        }
    }
    if (l>tr||r<tl){
        return 0;
    }
    if (l>=tl&&r<=tr){
        return t[v];
    }
    int m=(l+r)/2;
    make_push(v);
    return max(
               get(v*2,l,m,tl,tr),
               get(v*2+1,m+1,r,tl,tr)
               );
}

void solve()
{
//    cout<<"solve :)"<<"\n";
    int n,m,C,c0;
    cin>>n>>m>>C>>c0;
    vi T(0);
    for (int i=1;i<=n;i++){
        cin>>t[i]>>a[i]>>b[i];
        T.pb(t[i]);
    }
    T.pb(0);
    T.pb(m);
    sort(all(T));
//    T.resize(unique(all(T))-T.begin());
    if (len(T)>=arr-3){
        while (1){

        }
    }
    for (int i=0;i<len(T);i++){
        vh[i].clear();
    }
    for (int i=1;i<=n;i++){
        tt[i]=lower_bound(all(T),t[i])-T.begin();
        vh[tt[i]].pb(i);
    }
    int cur=c0;
    set<pair<pii,int>> setik;
    ll ans=0;
    clear(1,0,len(T)-1);
    for (int i=0;i+1<len(T);i++){
        upd1(1,0,len(T)-1,i,cur);
        int L=T[i+1]-T[i];
        if (L>C){
            cout<<-1<<"\n";
            return;
        }
//        cout<<"seg :: "<<T[i]<<" "<<T[i+1]<<"\n";
//        cout<<"cur :: "<<cur<<"\n";
        for (auto j:vh[i]){
            setik.insert(mp(mp(b[j],tt[j]),j));
        }
        while (cur<L&&!setik.empty()){
            int best=setik.begin()->sec;
//            cout<<"this :: "<<get(1,0,len(T)-1,tt[best],i)<<"\n";
            int can=min({L-cur,a[best],C-get(1,0,len(T)-1,tt[best],i)});
            if (can<0){
                while (1){

                }
            }
            if (!can){
                setik.erase(setik.begin());
            }
            else{
//                cout<<"before use cur :: "<<cur<<"\n";
//                cout<<"use :: "<<best<<" "<<can<<"\n";
                ans+=1ll*can*b[best];

                cur+=can;
                a[best]-=can;
                upd2(1,0,len(T)-1,tt[best],i,can);
            }
        }
        if (cur<L){
            cout<<-1<<"\n";
            return;
        }
        cur-=L;
    }

    cout<<ans<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int q;
    cin>>q;
    while (q--){
        solve();
    }
}