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

int dp[arr][4];
int a[arr];

void maximize(int& a,int b)
{
    if (a<b){
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

    int k[3];
    int n;
    cin>>n>>k[0]>>k[1]>>k[2];
    for (int i=0;i<arr;i++){
        for (int j=0;j<4;j++){
            dp[i][j]=-5e18;
        }
    }
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    dp[1][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=3;j++){
            if (j!=3){
                maximize(dp[i][j+1],dp[i][j]+k[j]*a[i]);
            }
            maximize(dp[i+1][j],dp[i][j]);
        }
    }
    cout<<dp[n][3]<<"\n";
}