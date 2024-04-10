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

pii best[11][11][3][11*11];

int a[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    vector<pii> moves1;
    moves1.pb(mp(-2,-1));
    moves1.pb(mp(-2,+1));
    moves1.pb(mp(-1,-2));
    moves1.pb(mp(-1,+2));
    moves1.pb(mp(+2,-1));
    moves1.pb(mp(+2,+1));
    moves1.pb(mp(+1,-2));
    moves1.pb(mp(+1,+2));
    vector<pii> moves2;
    for (int i=1;i<=10;i++){
        moves2.pb(mp(-i,-i));
        moves2.pb(mp(-i,+i));
        moves2.pb(mp(+i,-i));
        moves2.pb(mp(+i,+i));
    }

    for (int i=0;i<11;i++){
        for (int j=0;j<11;j++){
            for (int k=0;k<3;k++){
                for (int l=0;l<11*11;l++){
                    best[i][j][k][l]=mp(md,md);
                }
            }
        }
    }

    int n;
    cin>>n;
    int xx=-1;
    int yy=-1;

    int lolx=-1;
    int loly=-1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            if (a[i][j]==1){
                xx=i;
                yy=j;
            }
            if (a[i][j]==n*n){
                lolx=i;
                loly=j;
            }
        }
    }
    best[xx][yy][0][1]=mp(0,0);
    best[xx][yy][1][1]=mp(0,0);
    best[xx][yy][2][1]=mp(0,0);

    queue<pair<pii,pii>> q;
    q.push(mp(mp(xx,yy),mp(0,1)));
    q.push(mp(mp(xx,yy),mp(1,1)));
    q.push(mp(mp(xx,yy),mp(2,1)));

    while (!q.empty()){
        auto now=q.front();
        q.pop();
        int x=now.fir.fir;
        int y=now.fir.sec;
        int t=now.sec.fir;
        int max_use=now.sec.sec;

        for (int k=0;k<3;k++){
            if (best[x][y][k][max_use]>best[x][y][t][max_use]+mp(1,1)){
                best[x][y][k][max_use]=best[x][y][t][max_use]+mp(1,1);
                q.push(mp(mp(x,y),mp(k,max_use)));
            }
        }

        if (t==0){
            for (int i=1;i<=n;i++){
                if (best[i][y][t][max_use+(a[i][y]==max_use+1)]>best[x][y][t][max_use]+mp(1,0)){
                    best[i][y][t][max_use+(a[i][y]==max_use+1)]=best[x][y][t][max_use]+mp(1,0);
                    q.push(mp(mp(i,y),mp(t,max_use+(a[i][y]==max_use+1))));
                }
            }
            for (int j=1;j<=n;j++){
//                if (x==2&&y==3&&t==0&&max_use==7){
//                    cout<<"lol :: "<<j<<"\n";
//                }
                if (best[x][j][t][max_use+(a[x][j]==max_use+1)]>best[x][y][t][max_use]+mp(1,0)){
                    best[x][j][t][max_use+(a[x][j]==max_use+1)]=best[x][y][t][max_use]+mp(1,0);
                    q.push(mp(mp(x,j),mp(t,max_use+(a[x][j]==max_use+1))));
                }
            }
        }

        if (t==1){
            for (auto i:moves1){
                int xx=x+i.fir;
                int yy=y+i.sec;
                if (min(xx,yy)>=1&&max(xx,yy)<=n){
                    if (best[xx][yy][t][max_use+(a[xx][yy]==max_use+1)]>best[x][y][t][max_use]+mp(1,0)){
                        best[xx][yy][t][max_use+(a[xx][yy]==max_use+1)]=best[x][y][t][max_use]+mp(1,0);
                        q.push(mp(mp(xx,yy),mp(t,max_use+(a[xx][yy]==max_use+1))));
                    }
                }
            }
        }

        if (t==2){
            for (auto i:moves2){
                int xx=x+i.fir;
                int yy=y+i.sec;
                if (min(xx,yy)>=1&&max(xx,yy)<=n){
                    if (best[xx][yy][t][max_use+(a[xx][yy]==max_use+1)]>best[x][y][t][max_use]+mp(1,0)){
                        best[xx][yy][t][max_use+(a[xx][yy]==max_use+1)]=best[x][y][t][max_use]+mp(1,0);
                        q.push(mp(mp(xx,yy),mp(t,max_use+(a[xx][yy]==max_use+1))));
                    }
                }
            }
        }
    }

//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=n;j++){
//            for (int k=0;k<2;k++){
//                for (int max_use=1;max_use<=9;max_use++){
//                    cout<<"best["<<i<<"]["<<j<<"]["<<k<<"]["<<max_use<<"] :: ("<<best[i][j][k][max_use].fir<<","<<best[i][j][k][max_use].sec<<")"<<"\n";
//                }
//            }
//        }
//    }

    pii ans=mp(md,md);
    for (int k=0;k<3;k++){
        ans=min(ans,best[lolx][loly][k][n*n]);
    }
    cout<<ans.fir<<" "<<ans.sec<<"\n";
}