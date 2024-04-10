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

#define ar (int)(5000+10)

int val[ar][ar];
bool use[ar];
int a[ar];
int f1[ar];
int f2[ar];
vector<pii> seg;
bool edge[ar][ar];
int L,R;
int dp[ar];
vi vh[ar];
vi vhh[arr];

void dfs(int v)
{
    use[v]=1;
    L=min(L,seg[v].fir);
    R=max(R,seg[v].sec);
    for (int i=0;i<ar;i++){
        if (edge[v][i]&&!use[i]){
            dfs(i);
        }
    }
}

int count(vi& a,int l,int r)
{
    return upper_bound(all(a),r)-lower_bound(all(a),l);
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
    for (int i=0;i<ar;i++){
        f1[i]=999999;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
        vhh[a[i]].pb(i);
        f1[a[i]]=min(f1[a[i]],i);
        f2[a[i]]=i;
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<ar;j++){
            use[j]=0;
        }
        for (int j=i;j<=n;j++){
            val[i][j]=val[i][j-1]^((!use[a[j]])*a[j]);
            use[a[j]]=1;
        }
    }
    for (int i=0;i<ar;i++){
        if (f2[i]){
            seg.pb(mp(f1[i],f2[i]));
            //cout<<"seg :: "<<f1[i]<<" "<<f2[i]<<"\n";
        }
    }
    sort(all(seg));
    for (int i=0;i<len(seg);i++){
        for (int j=0;j<len(seg);j++){
            edge[i][j]=(count(vhh[a[seg[i].fir]],seg[j].fir,seg[j].sec)>0);
        }
    }
    vector<pii> seg1(0);
    for (int j=0;j<ar;j++){
        use[j]=0;
    }
    for (int i=0;i<len(seg);i++){
        if (!use[i]){
            L=1e9;
            R=-1e9;
            dfs(i);
            seg1.pb(mp(L,R));
            //cout<<"seg 1 :: "<<L<<" "<<R<<" && val :: "<<val[L][R]<<"\n";
            vh[R].pb(L);
        }
    }
    for (int i=1;i<ar;i++){
        dp[i]=dp[i-1];
        for (auto j:vh[i]){
            dp[i]=max(dp[i],dp[j-1]+val[j][i]);
        }
    }
    cout<<dp[ar-1]<<"\n";
}