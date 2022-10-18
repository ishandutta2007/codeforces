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

char a[ar][ar];
bool use1[ar][ar];
bool use2[ar][ar];
int n,m,q;
int ans[ar][ar];
const vector<pii> moves={{-1,0},{+1,0},{0,-1},{0,+1}};

bool ok(int x,int y)
{
    return min(x,y)>=1&&x<=n&&y<=m;
}

int dfs1(int x,int y)
{
    use1[x][y]=1;
    int res=0;
    for (auto wh:moves){
        int xx=x+wh.fir;
        int yy=y+wh.sec;
        if (ok(xx,yy)){
            if (a[xx][yy]=='*'){
                res++;
            }
            elif (!use1[xx][yy]){
                res+=dfs1(xx,yy);
            }
        }
    }
    return res;
}

void dfs2(int x,int y,int val)
{
    ans[x][y]=val;
    use2[x][y]=1;
    for (auto wh:moves){
        int xx=x+wh.fir;
        int yy=y+wh.sec;
        if (ok(xx,yy)){
            if (!use2[xx][yy]&&a[xx][yy]=='.'){
                dfs2(xx,yy,val);
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

    cin>>n>>m>>q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]=='.'&&!use1[i][j]){
                int val=dfs1(i,j);
                dfs2(i,j,val);
            }
        }
    }
    while (q--){
        int x,y;
        cin>>x>>y;
        cout<<ans[x][y]<<"\n";
    }
}