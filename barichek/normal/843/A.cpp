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

vector<pii> a;
vector<vi> ans;

int to[arr];
bool use[arr];

void dfs(int now)
{
    use[now]=1;
    ans.back().pb(now+1);
    if (!use[to[now]]){
        dfs(to[now]);
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

    fast;
    int n;
    cin>>n;
    a.resize(n);
    int num=0;
    for (auto& i:a){
        cin>>i.fir;
        i.sec=num++;
    }
    sort(all(a));
    for (int i=0;i<len(a);i++){
        to[a[i].sec]=i;
    }
    for (int i=0;i<n;i++){
        if (!use[i]){
            ans.pb({});
            dfs(i);
        }
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<len(i)<<" ";
        for (auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}