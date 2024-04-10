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
int b[ar][ar];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    vector<pii> ans(0);
    for (int i=0;i+1<n;i++){
        for (int j=0;j+1<m;j++){
            if (a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]==4){
                b[i][j]=1;
                b[i][j+1]=1;
                b[i+1][j]=1;
                b[i+1][j+1]=1;
                ans.pb(mp(i+1,j+1));
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]!=b[i][j]){
                cout<<-1<<"\n";
                return 0;
            }
        }
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec<<"\n";
    }
}