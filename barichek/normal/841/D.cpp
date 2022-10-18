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

#define arr (int)(3e5+10)

#define pb emplace_back

int d[arr];
bool use[arr];
vector<pii> reb[arr];
vector<pii> reb1[arr];
int any_1=-1;
vi bad;
int push[arr];

void dfs(int now=0)
{
//    cout<<"dfs :: "<<now<<"\n";
    if (d[now]==-1){
        any_1=now;
//        cout<<"kek"<<"\n";
    }
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh.fir]){
            dfs(wh.fir);
            reb1[now].pb(wh);
            reb1[wh.fir].pb(mp(now,wh.sec));
        }
    }
}

vi ans(0);

void dfs1(int now=0,int pred=-1)
{
    for (auto wh:reb1[now]){
        if (wh.fir!=pred){
            dfs1(wh.fir,now);
            push[now]+=push[wh.fir];
            if (push[wh.fir]%2==0){
                ans.pb(wh.sec);
            }
        }
    }
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

    int n,m;
    cin>>n>>m;
    int sum_1=0;
    for (int i=0;i<n;i++){
        cin>>d[i];
        sum_1+=(d[i]==1);
    }
    int num=0;
    while (m--){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        num++;
        reb[u].pb(mp(v,num));
        reb[v].pb(mp(u,num));
    }
    dfs();
    for (int i=0;i<n;i++){
        if (d[i]!=-1){
            if (d[i]!=reb1[i].size()%2){
                bad.pb(i);
            }
        }
    }
//    cout<<"any_1 :: "<<any_1<<"\n";
    if (any_1==-1){
//        cout<<"kek2"<<"\n";
        if (sum_1%2!=0){
            return cout<<-1<<"\n", 0;
        }
        for (int i=0;i<len(bad);i+=2){
            push[bad[i]]++;
            push[bad[i+1]]++;
        }
    }
    else{
//        cout<<"kek1"<<"\n";
        for (int i=0;i<len(bad);i++){
            push[bad[i]]++;
            push[any_1]++;
        }
    }
    dfs1();

    sort(all(ans));
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}