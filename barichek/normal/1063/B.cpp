#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

pii operator+(pii a,pii b)
{
    return mp(a.fir+b.fir,a.sec+b.sec);
}

char a[ar][ar];

int best_x[ar][ar];

int n,m;

bool ok(int x,int y)
{
    return 1<=x&&x<=n&&1<=y&&y<=m;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    vector<pii> moves(0);

    moves.pb(mp(0,-1));
    moves.pb(mp(0,+1));
    moves.pb(mp(-1,0));
    moves.pb(mp(+1,0));

    cin>>n>>m;
    int r,c;
    cin>>r>>c;
    int x,y;
    cin>>x>>y;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            best_x[i][j]=1e18;
        }
    }
    best_x[r][c]=0;

    deque<pii> q;
    q.push_back(mp(r,c));

    int ans=0;

    while (!q.empty()){
        pii now=q.front();
        q.pop_front();
        if (best_x[now.fir][now.sec]>1e9){
            break;
        }
//        cout<<now.fir<<" "<<now.sec<<" "<<best_x[now.fir][now.sec]<<"\n";

        for (auto wh:moves){
            pii to=now+wh;
            if (ok(to.fir,to.sec)&&a[to.fir][to.sec]!='*'&&best_x[to.fir][to.sec]>best_x[now.fir][now.sec]+(wh.sec==-1)){
                best_x[to.fir][to.sec]=best_x[now.fir][now.sec]+(wh.sec==-1);
                if (wh.sec==-1){
                    q.push_back(to);
                }
                else{
                    q.push_front(to);
                }
            }
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int dx=j-c;
            pii now=mp(i,j);
            if (best_x[now.fir][now.sec]<=x&&dx+best_x[now.fir][now.sec]<=y){
                ans++;
            }
        }
    }

    cout<<ans<<"\n";
}