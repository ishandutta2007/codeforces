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

#define oryshych_jebosh main

///---program start---///

int n,m,s;
char a[ar][ar];

const vector<pii> moves={{-1,0},{+1,0},{0,-1},{0,+1}};

bool ok(int x,int y)
{
    return min(x,y)>=1&&x<=n&&y<=m;
}

int cnt[ar][ar];
int good;
bool use[ar][ar];
int lol;

void dfs(int x,int y)
{
    if (lol==good-s){
        return;
    }
    use[x][y]=1;
    lol++;
    if (lol==good-s){
        return;
    }
    for (auto wh:moves){
        int xx=x+wh.fir;
        int yy=y+wh.sec;
        if (!use[xx][yy]&&ok(xx,yy)&&a[xx][yy]=='.'){
            dfs(xx,yy);
        }
    }
}

oryshych_jebosh()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>m>>s;
    set<pair<int,pii>> q;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            good+=(a[i][j]=='.');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]=='.'){
                dfs(i,j);
                goto label1;
            }
        }
    }
    label1:;
    end_of_main:;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<(use[i][j]?'.':a[i][j]=='#'?'#':'X');
        }
        cout<<"\n";
    }
}