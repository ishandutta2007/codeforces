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

int deep[arr];
int p[arr][20];

void add(int v,int pred)
{
    p[v][0]=pred;
    for (int i=1;i<20;i++){
        p[v][i]=p[p[v][i-1]][i-1];
    }
    deep[v]=deep[pred]+1;
}

int lca(int u,int v)
{
    if (deep[u]>deep[v]){
        swap(u,v);
    }
    for (int i=19;i>=0;i--){
        if (deep[p[v][i]]>=deep[u]){
            v=p[v][i];
        }
    }
    if (u==v){
        return u;
    }
    for (int i=19;i>=0;i--){
        if (p[u][i]!=p[v][i]){
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}

int dist(int u,int v)
{
    return deep[u]+deep[v]-2*deep[lca(u,v)];
}

int cur1=2;
int cur2=3;

void add_vertex(int v,int pred)
{
    add(v,pred);
    int d1=dist(v,cur1);
    int d2=dist(v,cur2);
    int d3=dist(cur1,cur2);
    if (d1>=max(d2,d3)){
        cur2=v;
    }
    elif (d2>=max(d1,d3)){
        cur1=v;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int q;
    cin>>q;
    add(2,1);
    add(3,1);
    add(4,1);
    int n=4;
    while (q--){
        int v;
        cin>>v;
        add_vertex(++n,v);
        add_vertex(++n,v);
        cout<<dist(cur1,cur2)<<"\n";
    }
}