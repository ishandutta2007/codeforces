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

///---program start---///

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

int dp[ar][ar];

vi lols[arr];

string s[arr];

int val[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<ar;i++){
        for (int j=0;j<ar;j++){
            dp[i][j]=1e9;
            val[i][j]=1e9;
        }
    }
    for (int i=1;i<=n;i++){
        cin>>s[i];
        for (int j=0;j<m;j++){
            if (s[i][j]=='1'){
                lols[i].pb(j);
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<len(lols[i]);j++){
            for (int k=j;k<len(lols[i]);k++){
                minimize(val[i][j+(len(lols[i])-k-1)],lols[i][k]-lols[i][j]+1);
            }
        }
    }
    dp[0][0]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=k;j++){
            for (int cur=0;cur<=min(k-j,len(lols[i+1]));cur++){
//                cout<<i<<" "<<j<<" "<<k<<" !!\n";
//                cout<<"dp["<<i<<"]["<<j<<"] :: "<<dp[i][j]<<"\n";
                if (cur==len(lols[i+1])){
                    minimize(dp[i+1][j+cur],dp[i][j]);
                }
                else{
                    minimize(dp[i+1][j+cur],dp[i][j]+val[i+1][cur]);
                }
            }
        }
    }
    int ans=1e18;
    for (int i=0;i<=k;i++){
        minimize(ans,dp[n][i]);
    }
    cout<<ans<<"\n";
}