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

int dp1[ar][ar];
int dp2[ar][ar];

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
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

    int n,m,p;
    cin>>n>>m>>p;
    vi a(n);
    for (auto& i:a){
        cin>>i;
    }
    sort(all(a));
    vi b(m);
    for (auto& i:b){
        cin>>i;
    }
    sort(all(b));
    for (int i=0;i<ar;i++){
        for (int j=0;j<ar;j++){
            dp1[i][j]=1e15;
        }
    }
    dp1[0][0]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            minimize(dp1[i][j+1],dp1[i][j]);
            minimize(dp1[i+1][j+1],max(dp1[i][j],abs(a[i]-b[j])+abs(b[j]-p)));
        }
    }
    int ans=1e15;
    for (int j=0;j<=m;j++){
        minimize(ans,dp1[n][j]);
    }
    cout<<ans<<"\n";
}