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

#define arr (int)(2e6+10)

vi dil[arr];
vi reb[arr];
unordered_map<int,int> vh;
int cnt_vh;
int a[arr];
int ans[arr];
int current[arr];
int deep[arr];
stack<int> lol[arr/10];
bool is_prime[arr];

void reset(int i)
{
    dil[i].clear();
    for (int j=1;j*j<=a[i];j++){
        if (a[i]%j==0){
            if (j!=1){
                if (is_prime[j]){
                    dil[i].pb(j);
                }
            }
            if (a[i]/j!=1&&j*j!=a[i]){
                if (is_prime[a[i]/j]){
                    dil[i].pb(a[i]/j);
                }
            }
        }
    }
    for (auto w:dil[i]){
        if (!vh.count(w)){
            vh[w]=cnt_vh++;
        }
    }
    for (auto& w:dil[i]){
        w=vh[w];
    }
//    cout<<"after reset("<<i<<") dil["<<i<<"] :: ";
//    for (auto w:dil[i]){
//        cout<<w<<" ";
//    }
//    cout<<"\n";
}

void dfs(int now,int pred)
{
//    cout<<"dfs("<<now<<") :: \n";
    for (auto d:dil[now]){
//        cout<<"i am interested in d :: "<<d<<"\n";
        if (!lol[d].empty()){
            ans[now]=max(ans[now],lol[d].top());
        }
    }
//    cout<<"ans["<<now<<"] :: "<<ans[now]<<"\n";
    if (ans[now]!=-1){
        ans[now]=current[ans[now]];
    }
    current[deep[now]]=now;
    for (auto d:dil[now]){
//        cout<<"insert to "<<d<<" :: "<<deep[now]<<"\n";
        lol[d].push(deep[now]);
    }
    for (auto wh:reb[now]){
        if (wh!=pred){
            deep[wh]=deep[now]+1;
            dfs(wh,now);
        }
    }
    for (auto d:dil[now]){
//        cout<<"erase from "<<d<<" :: "<<deep[now]<<"\n";
        lol[d].pop();
    }
}

void recalc()
{
    for (int i=0;i<arr;i++){
        ans[i]=-1;
    }
    dfs(1,-1);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fill(is_prime,is_prime+arr,1);
    is_prime[1]=0;
    for (int i=2;i<arr;i++){
        if (is_prime[i]){
            for (int j=i+i;j<arr;j+=i){
                is_prime[j]=0;
            }
        }
    }

    fast;
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        reset(i);
    }
    for (int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        reb[u].pb(v);
        reb[v].pb(u);
    }
    recalc();
    while (q--){
        int type;
        cin>>type;
        if (type==1){
            int v;
            cin>>v;
            cout<<ans[v]<<"\n";
        }
        else{
            int v,w;
            cin>>v>>w;
            a[v]=w;
            reset(v);
            recalc();
        }
    }
}