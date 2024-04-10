//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
const ll inf=1e18+10;

///---program start---///

int p[arr];
int c[arr];
int ans[arr];
int deep[arr];

vi reb[arr];

void dfs(int now,int pred)
{
    for (auto wh:reb[now]){
        if (wh!=pred){
            deep[wh]=deep[now]+1;
            dfs(wh,now);
        }
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    int n;
    cin>>n;
    int root=-1;
    for (int i=1;i<=n;i++){
        cin>>p[i]>>c[i];
        reb[p[i]].pb(i);
        if (p[i]==0){
            root=i;
        }
    }
    dfs(root,root);
    for (int iter=1;iter<=n;iter++){
        pii best=mp(inf,-1);
        for (int i=1;i<=n;i++){
            if (ans[i]==0&&c[i]==0){
                best=min(best,mp(deep[i],i));
            }
        }
        if (best.sec==-1){
            cout<<"NO"<<"\n";
            return 0;
        }
        ans[best.sec]=iter;
        int cur=p[best.sec];
        while (cur){
            if (ans[cur]==0){
                c[cur]--;
            }
            cur=p[cur];
        }
    }
    cout<<"YES"<<"\n";
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}