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

///---program start---///

int a[ar][ar];

#define set set____

void set(int x,int y,int value)
{
    if (a[x][y]!=-1){
        if (a[x][y]!=value){
            cout<<0<<"\n";
            exit(0);
        }
    }
    a[x][y]=value;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=-1;
        }
    }
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        for (int j=1;j<=a;j++){
            set(i,j,1);
        }
        if (a!=m){
            set(i,a+1,0);
        }
    }
    for (int j=1;j<=m;j++){
        int a;
        cin>>a;
        for (int i=1;i<=a;i++){
            set(i,j,1);
        }
        if (a!=n){
            set(a+1,j,0);
        }
    }
    int ans=1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]==-1){
                ans=(2*ans)%md;
            }
        }
    }
    cout<<ans<<"\n";
}