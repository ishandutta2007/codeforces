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
///#define int long long

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

#define left left_____
#define right right_____
#define up up_____
#define down down_____

set<int> open_x[arr];
set<int> open_y[arr];
char a[ar][ar];
int left[ar][ar];
int right[ar][ar];
int up[ar][ar];
int down[ar][ar];
vector<pii> current;
int dist[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            if (a[i][j]=='.'){
                open_x[j].insert(i);
                open_y[i].insert(j);
            }
        }
    }

    /// left
    for (int i=1;i<=n;i++){
        left[i][0]=-1e9;
        for (int j=1;j<=m;j++){
            if (a[i][j]=='#'){
                left[i][j]=j;
            }
            else{
                left[i][j]=left[i][j-1];
            }
        }
    }

    /// right
    for (int i=1;i<=n;i++){
        right[i][m+1]=1e9;
        for (int j=m;j>=1;j--){
            if (a[i][j]=='#'){
                right[i][j]=j;
            }
            else{
                right[i][j]=right[i][j+1];
            }
        }
    }

    /// up
    for (int j=1;j<=m;j++){
        up[0][j]=-1e9;
        for (int i=1;i<=n;i++){
            if (a[i][j]=='#'){
                up[i][j]=i;
            }
            else{
                up[i][j]=up[i-1][j];
            }
        }
    }

    /// down
    for (int j=1;j<=m;j++){
        down[n+1][j]=1e9;
        for (int i=n;i>=1;i--){
            if (a[i][j]=='#'){
                down[i][j]=i;
            }
            else{
                down[i][j]=down[i+1][j];
            }
        }
    }

    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;

    queue<pii> q;
    q.push({x1,y1});
    dist[x1][y1]=1;
    while (!q.empty()){
        int x=q.front().fir;
        int y=q.front().sec;
        open_x[y].erase(x);
        open_y[x].erase(y);
        q.pop();
        current.clear();

        {
            /// go up and down
            auto it=open_x[y].lower_bound(max(up[x][y],x-k));
            while (it!=open_x[y].end()&&*it<=min(down[x][y],x+k)){
                current.pb({*it,y});
                it++;
            }
        }

        {
            /// go left and right
            auto it=open_y[x].lower_bound(max(left[x][y],y-k));
            while (it!=open_y[x].end()&&*it<=min(right[x][y],y+k)){
                current.pb({x,*it});
                it++;
            }
        }

        for (auto i:current){
            dist[i.fir][i.sec]=dist[x][y]+1;
            open_x[i.sec].erase(i.fir);
            open_y[i.fir].erase(i.sec);
            q.push(i);
        }
    }

    cout<<(dist[x2][y2]==0?-1:dist[x2][y2]-1)<<"\n";
}