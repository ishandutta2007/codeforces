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

vi reb[arr];
int comp[arr];
bool use[arr];

void add(int u,int v)
{
    reb[u].pb(v);
    reb[v].pb(u);
}

void dfs(int now,int c)
{
    comp[now]=c;
    use[now]=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            dfs(wh,c);
        }
    }
}

void build()
{
    int c=0;
    for (int i=0;i<arr;i++){
        if (!use[i]){
            dfs(i,c++);
        }
    }
}

bool ok(string s,string t)
{
    if (len(s)!=len(t)){
        return 0;
    }
    for (int i=0;i<len(s);i++){
        if (comp[s[i]]!=comp[t[i]]){
            return 0;
        }
    }
    return 1;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i='a';i<='z';i++){
        add(i,toupper(i));
    }

    add('0','O');

    add('1','l');
    add('1','I');

    add('l','I');

    build();

    string s;
    cin>>s;
    int n;
    cin>>n;
    while (n--){
        string t;
        cin>>t;
        if (ok(s,t)){
            cout<<"No"<<"\n";
            return 0;
        }
    }
    cout<<"Yes"<<"\n";
}