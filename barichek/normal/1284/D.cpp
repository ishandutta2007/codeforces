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
const ll inf=1e18+10;

///---program start---///

#define arr (int)(4e5+10)

bool t[4*arr];
bool push[4*arr];

void make_push(int v)
{
    if (push[v]==0){
        return;
    }
    t[v*2]=1;
    t[v*2+1]=1;
    
    push[v*2]=1;
    push[v*2+1]=1;
    
    push[v]=0;
}

void upd(int v,int l,int r,int tl,int tr)
{
    if (l>tr||r<tl){
        return;
    }
    if (l>=tl&&r<=tr){
        t[v]=1;
        push[v]=1;
        return;
    }
    make_push(v);
    int m=(l+r)/2;
    upd(v*2,l,m,tl,tr);
    upd(v*2+1,m+1,r,tl,tr);
    t[v]=t[v*2]|t[v*2+1];
}

bool get(int v,int l,int r,int tl,int tr)
{
    if (l>tr||r<tl){
        return 0;
    }
    if (l>=tl&&r<=tr){
        return t[v];
    }
    make_push(v);
    int m=(l+r)/2;
    return
        get(v*2,l,m,tl,tr)|
        get(v*2+1,m+1,r,tl,tr);
}

bool get(vector<pair<pii,pii>> v)
{
    // cerr<<"get"<<"\n";
    for (int i=0;i<4*arr;i++){
        t[i]=0;
        push[i]=0;
    }
    
    vector<pii> events(0);
    for (int i=0;i<len(v);i++){
        events.pb(mp(v[i].sec.fir,i+1)); /// open
        events.pb(mp(v[i].sec.sec,-(i+1))); /// close
    }
    sort(all(events));
    for (int i=0;i<len(events);){
        // cerr<<"i :: "<<i<<"\n";
        int j=i;
        while (j+1<len(events)&&events[j+1].fir==events[i].fir){
            j++;
        }
        // cerr<<"j :: "<<j<<"\n";
        
        /// [i;j]
        for (int k=i;k<=j;k++){
            // cerr<<"k1 :: "<<k<<"\n";
            int id=abs(events[k].sec)-1;
            if (events[k].sec>0){
                if (get(1,1,4*len(v),v[id].fir.fir,v[id].fir.sec)==1){
                    return 1;
                }
            }
        }
        for (int k=i;k<=j;k++){
            // cerr<<"k2 :: "<<k<<"\n";
            int id=abs(events[k].sec)-1;
            if (events[k].sec<0){
                upd(1,1,4*len(v),v[id].fir.fir,v[id].fir.sec);
            }
        }
        
        i=j+1;
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
    
    int n;
    cin>>n;
    vector<pair<pii,pii>> v(n);
    map<int,int> vh;
    for (auto& i:v){
        cin>>i.fir.fir>>i.fir.sec>>i.sec.fir>>i.sec.sec;
        vh[i.fir.fir];
        vh[i.fir.sec];
        vh[i.sec.fir];
        vh[i.sec.sec];
    }
    int cnt_vh=0;
    for (auto& i:vh){
        i.sec=++cnt_vh;
    }
    for (auto& i:v){
        i.fir.fir=vh[i.fir.fir];
        i.fir.sec=vh[i.fir.sec];
        i.sec.fir=vh[i.sec.fir];
        i.sec.sec=vh[i.sec.sec];
    }
    
    bool ans=0;
    
    ans|=get(v);
    
    for (auto& i:v){
        swap(i.fir,i.sec);
    }
    ans|=get(v);
    
    cout<<(ans?"NO":"YES")<<"\n";
}