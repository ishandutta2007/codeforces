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

int a[arr];

int dp[50][50*50];

void upd(int& a,int b)
{
    if (a<b){
        a=b;
    }
}

int pref[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    for (int i=0;i<50;i++){
        for (int j=0;j<50*50;j++){
            dp[i][j]=-1e18;
        }
    }
    int n,k,M;
    cin>>n>>k>>M;
    for (int i=1;i<=k;i++){
        cin>>a[i];
    }
    sort(a+1,a+k+1);
    for (int i=1;i<=k;i++){
        pref[i]+=pref[i-1]+a[i];
    }
    dp[0][0]=M;
    for (int i=0;i<n;i++){
        for (int j=0;j<50*50;j++){
            if (dp[i][j]!=-1e18){
                for (int l=0;l<=k;l++){
                    upd(dp[i+1][j+l+(l==k)],dp[i][j]-pref[l]);
                }
                upd(dp[i+1][j],dp[i][j]);
            }
        }
    }
    int ans=0;
    for (int i=0;i<50*50;i++){
        if (dp[n][i]>=0){
            ans=max(ans,i);
        }
    }
    cout<<ans<<"\n";
}