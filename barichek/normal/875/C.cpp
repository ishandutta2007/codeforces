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
//        cout<<"add :: "<<from<<" "<<to<<"\n";
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

vi a[arr];

bool is_inverse[arr];

int num[arr];
int rnum[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    int n,m;
    cin>>n>>m;
    int number=0;
    for (int i=1;i<=m;i++){
        num[i]=number++;
//        cout<<"num["<<i<<"] :: "<<num[i]<<"\n";
    }
    for (int i=1;i<=m;i++){
        rnum[i]=number++;
//        cout<<"rnum["<<i<<"] :: "<<rnum[i]<<"\n";
    }

    int pravda=number++;
    sat2 lol=*new sat2(number);

    for (int i=1;i<=m;i++){
        lol.add_edge(num[i],pravda);
        lol.add_edge(rnum[i],pravda);
    }

    for (int i=0;i<n;i++){
        int kek;
        cin>>kek;
        a[i].resize(kek);
        for (auto& j:a[i]){
            cin>>j;
        }
    }
    for (int i=0;i+1<n;i++){
        bool is_ok_any=0;
        if (len(a[i])<=len(a[i+1])){
            is_ok_any=1;
            for (int j=0;j<len(a[i]);j++){
                is_ok_any&=(a[i][j]==a[i+1][j]);
            }
        }
        if (is_ok_any){
            continue;
        }
        bool ok1=(len(a[i])>len(a[i+1]));
        for (int j=0;j<min(len(a[i]),len(a[i+1]));j++){
            ok1&=(a[i][j]==a[i+1][j]);
        }
        if (ok1){
            return cout<<"No"<<"\n", 0;
        }
        for (int j=0;j<min(len(a[i]),len(a[i+1]));j++){
            if (a[i][j]!=a[i+1][j]){
                if (a[i][j]<a[i+1][j]){
                    lol.add_edge(num[a[i+1][j]],num[a[i][j]]);
                    lol.add_edge(rnum[a[i][j]],rnum[a[i+1][j]]);
                }
                else{
                    /// close rnum[a[i][j]]
//                    lol.add_edge(rnum[a[i][j]],num[a[i][j]]);
                    lol.add_edge(pravda,num[a[i][j]]);
                    /// close num[a[i+1][j]]
//                    lol.add_edge(num[a[i+1][j]],rnum[a[i+1][j]]);
                    lol.add_edge(pravda,rnum[a[i+1][j]]);
                }
                break;
            }
        }
    }
    lol.build();
    for (int i=1;i<=m;i++){
        if (lol.comp[num[i]]==lol.comp[rnum[i]]){
            return cout<<"No"<<"\n", 0;
        }
    }
    cout<<"Yes"<<"\n";
    vi ans(0);
    for (int i=1;i<=m;i++){
//        cout<<"comp["<<i<<"] :: "<<lol.comp[num[i]]<<" "<<lol.comp[rnum[i]]<<"\n";
        if (lol.comp[num[i]]>lol.comp[rnum[i]]){
            ans.pb(i);
        }
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}