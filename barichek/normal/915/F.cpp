#pragma GCC optimize("O3")
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

///---program start---///

#define arr (int)(1e6+10)

int a[arr];

int p[arr];
int size[arr];

void clear()
{
    for (int i=0;i<arr;i++){
        p[i]=i;
        size[i]=1;
    }
}

int find(int v)
{
    return p[v]==v?v:p[v]=find(p[v]);
}

vi reb[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    int n;
    cin>>n;
    vector<pii> q(0);
    for (int i=1;i<=n;i++){
        cin>>a[i];
        q.pb({a[i],i});
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }

    int ans=0;

    sort(all(q));

    clear();
    for (auto i:q){
//        cout<<"kek "<<i.fir<<" "<<i.sec<<"\n";
        for (auto j:reb[i.sec]){
            if (i<pii{a[j],j}){
                continue;
            }
            int u=i.sec;
            int v=j;
            u=find(u);
            v=find(v);
            if (u!=v){
//                cout<<i.sec<<" "<<j<<"\n";
                ans+=size[u]*size[v]*i.fir;
//                cout<<"ans+="<<size[u]<<"*"<<size[v]<<"*"<<i.fir<<"\n";
                p[u]=v;
                size[v]+=size[u];
            }
        }
    }

    reverse(all(q));
    clear();
    for (auto i:q){
//        cout<<"lol "<<i.fir<<" "<<i.sec<<"\n";
        for (auto j:reb[i.sec]){
            if (i>pii{a[j],j}){
                continue;
            }
            int u=i.sec;
            int v=j;
            u=find(u);
            v=find(v);
            if (u!=v){
//                cout<<i.sec<<" "<<j<<"\n";
                ans-=size[u]*size[v]*i.fir;
//                cout<<"ans-="<<size[u]<<"*"<<size[v]<<"*"<<i.fir<<"\n";
                p[u]=v;
                size[v]+=size[u];
            }
        }
    }

    cout<<ans<<"\n";
}