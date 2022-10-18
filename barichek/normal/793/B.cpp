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

#define ar (int)(1e3+10)

bool use[ar][ar][4][3];
vector<pii> moves={{+1,0},{0,-1},{-1,0},{0,+1}};
int n,m;
string A[arr];

bool ok(int a,int b)
{
    return min(a,b)>=1&&a<=n&&b<=m&&A[a][b-1]!='*';
}

void dfs(int x,int y,int from,int cnt)
{
    //cout<<"dfs :: "<<x<<" "<<y<<" "<<from<<" "<<cnt<<"\n";
    if (cnt>2||use[x][y][from][cnt]){
        return;
    }
    use[x][y][from][cnt]=1;
    for (int i=0;i<4;i++){
        if (abs(i-from)!=2){
            if (ok(x+moves[i].fir,y+moves[i].sec)){
                dfs(x+moves[i].fir,y+moves[i].sec,i,cnt+abs(from-i)%2);
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

    fast;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>A[i];
    }
    int s_x,s_y;
    int f_x,f_y;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (A[i][j-1]=='S'){
                s_x=i;
                s_y=j;
            }
            if (A[i][j-1]=='T'){
                f_x=i;
                f_y=j;
            }
        }
    }
    dfs(s_x,s_y,0,0);
    dfs(s_x,s_y,1,0);
    dfs(s_x,s_y,2,0);
    dfs(s_x,s_y,3,0);
    for (int i=0;i<4;i++){
        for (int j=0;j<3;j++){
            if (use[f_x][f_y][i][j]){
                return cout<<"YES"<<"\n", 0;
            }
        }
    }
    cout<<"NO"<<"\n";
}