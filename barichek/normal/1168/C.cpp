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

#define arr (int)(3e5+10)

const int M=22;
int best[arr][M];
int last[M][M];
int a[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    /// init
    for (int i=0;i<M;i++){
        for (int j=0;j<M;j++){
            last[i][j]=n+1;
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=0;j<M;j++){
            if (a[i]&(1ll<<j)){
                best[i][j]=i;
            }
            else{
                best[i][j]=n+1;
                for (int k=0;k<M;k++){
                    if (a[i]&(1ll<<k)){
                        if (last[k][j]!=-1){
                            best[i][j]=min(best[i][j],last[k][j]);
                        }
                    }
                }
            }
        }
        for (int j=0;j<M;j++){
            if (a[i]&(1ll<<j)){
                for (int k=0;k<M;k++){
                    last[j][k]=min(last[j][k],best[i][k]);
                }
            }
        }
    }

    for (int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        bool ok=0;
        for (int j=0;j<M;j++){
            if (a[y]&(1ll<<j)){
                if (best[x][j]<=y){
                    ok=1;
                    break;
                }
            }
        }
        cout<<(ok?"Shi":"Fou")<<"\n";
    }
}