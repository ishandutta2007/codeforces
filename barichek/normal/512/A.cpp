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

#ifdef I_love_Maria_Ivanova
    #define debug if (1)
#else
    #define debug if (0)
#endif

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

vi top;
bool use[arr];
set<int> reb[arr];
bool can[ar][ar];
bool use1[arr];

void dfs(int now,int pred=-1)
{
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh])
            dfs(wh,now);
    }
    top.pb(now);
}

void dfs1(int now,int start)
{
    can[start][now]=1;
    use1[now]=1;
    for (auto wh:reb[now]){
        if (!use1[wh])
            dfs1(wh,start);
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

    int n;
    cin>>n;
    vector<string> a(n);
    for (auto& i:a){
        cin>>i;
    }
    for (int i=1;i<len(a);i++)
    {
        string s1=a[i-1];
        string s2=a[i];
        if (len(s2)<len(s1)&&s1.substr(0,len(s2))==s2)
            exit(!(cout<<"Impossible"));
        for (int i=0;i<min(len(s1),len(s2));i++)
            if (s1[i]!=s2[i]){
                reb[s1[i]].insert(s2[i]);
                break;
            }
    }
    for (int i='a';i<='z';i++){
        memset(use1,0,sizeof(use1));
        dfs1(i,i);
    }
    for (int i='a';i<='z';i++){
        for (int j='a';j<='z';j++){
            if (i!=j&&can[i][j]&&can[j][i]){
                exit(!(cout<<"Impossible"));
            }
        }
    }
    for (int i='a';i<='z';i++)
        if (!use[i])
            dfs(i);
    reverse(all(top));
    for (auto i:top)
        cout<<char(i);
}