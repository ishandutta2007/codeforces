#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

#define arr (int)(4e5+10)

int to_root[arr];

int p[arr];
int sz[arr];

//int f(int v)
//{
//    return p[v]==v?v:p[v]=f(p[v]);
//}

vi kek[arr];

int last_num=0;

map<int,int> last_kek;

int get_num(int a)
{
    if (last_kek.count(a)){
        return last_kek[a];
    }
    else{
        return last_kek[a]=last_num++;
    }
}

int get(int u,int v)
{
    if (p[u]!=p[v]){
        return -1;
    }
    return to_root[u]^to_root[v];
}

void unite(int u,int v,int val)
{
    if (sz[p[u]]>sz[p[v]]){
        swap(u,v);
    }
    /// u -> v
    int root_u=p[u];
    int root_v=p[v];
    int way_root_u=to_root[u];
    for (auto i:kek[root_u]){
        p[i]=root_v;
        to_root[i]=(way_root_u^to_root[i])^to_root[v]^val;

        kek[root_v].pb(i);
    }
    sz[root_v]+=sz[root_u];

    sz[root_u]=0;
    kek[root_u].clear();
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<arr;i++){
        sz[i]=1;
        p[i]=i;
        kek[i].pb(i);
        to_root[i]=0;
    }

    fast;

    int q;
    cin>>q;
    int last=0;
    while (q--){
        int type,ll,rr,xx;
        cin>>type;
        if (type==1){
            cin>>ll>>rr>>xx;
            int l=ll^last;
            int r=rr^last;
            int x=xx^last;
//            cout<<"t1 :: "<<l<<" "<<r<<" :: "<<x<<"\n";
            if (l>r){
                swap(l,r);
            }
            l=get_num(l);
            r=get_num(r+1);
//            cout<<"t1 :: "<<l<<" "<<r<<" :: "<<x<<"\n";
            int prev=get(l,r);
            if (prev==-1){
                unite(l,r,x);
            }
        }
        else{
            cin>>ll>>rr;
            int l=ll^last;
            int r=rr^last;
            if (l>r){
                swap(l,r);
            }
            l=get_num(l);
            r=get_num(r+1);
//            cout<<"t2 :: "<<l<<" "<<r<<"\n";
            int prev=get(l,r);
            cout<<prev<<"\n";
            last=abs(prev);
        }
    }
}