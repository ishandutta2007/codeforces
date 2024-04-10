#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

struct sat2
{
    int n;
    vector<bool> use;
    vi order;
    vector<vi> reb;
    vector<vi> rreb;
    vi comp;

    sat2() {}
    sat2(int n)
    {
        this->n=n;
        use.assign(n,0);
        reb.resize(n);
        rreb.resize(n);
        comp.assign(n,0);
    }

    void add_edge(int from,int to)
    {
        reb[from].pb(to);
        rreb[to].pb(from);
    }
    void dfs1(int now)
    {
        use[now]=1;
        for (auto wh:reb[now]){
            if (!use[wh]){
                dfs1(wh);
            }
        }
        order.pb(now);
    }
    void dfs2(int now,int num)
    {
        comp[now]=num;
        for (auto wh:rreb[now]){
            if (!comp[wh]){
                dfs2(wh,num);
            }
        }
    }
    void build()
    {
        for (int i=0;i<n;i++){
            if (!use[i]){
                dfs1(i);
            }
        }
        reverse(all(order));
        int num=0;
        for (auto i:order){
            if (!comp[i]){
                dfs2(i,++num);
            }
        }
    }
};

int a[arr];
int b[arr];

int n,m;

bool in(int a,int b,int c)
{
    return (a<=b&&b<=c)||(a>=c&&!(c<b&&b<a));
}

bool intersect1(int a,int b,int c,int d)
{
    if ((in(a,c,b)&&(c!=a&&c!=b))&&!in(a,d,b)){
        return 1;
    }
    if ((in(a,d,b)&&(d!=a&&d!=b))&&!in(a,c,b)){
        return 1;
    }
    return 0;
}

bool intersect(int a,int b,int c,int d)
{
    return intersect1(a,b,c,d)||intersect1(c,d,a,b);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    cin>>n>>m;
    for (int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    /// in - 2*i
    /// !in - 2*i+1
    sat2 kek=*new sat2(2*m);
    for (int i=0;i<m;i++){
        for (int j=0;j<m;j++){
            if (i!=j){
                if (intersect(a[i],b[i],a[j],b[j])){
                    kek.add_edge(2*i,2*j+1);
                    kek.add_edge(2*i+1,2*j);
                }
            }
        }
    }

    kek.build();

    for (int i=0;i<m;i++){
        if (kek.comp[2*i]==kek.comp[2*i+1]){
            return cout<<"Impossible"<<"\n", 0;
        }
    }
    for (int i=0;i<m;i++){
        if (kek.comp[2*i]>kek.comp[2*i+1]){
            cout<<"i";
        }
        else{
            cout<<"o";
        }
    }
    cout<<"\n";
}