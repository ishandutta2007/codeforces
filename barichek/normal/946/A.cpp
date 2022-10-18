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

int dp[200][200*200];

int kek=200*200/2;

int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0][kek]=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<200*200;j++){
            if (dp[i][j]){
                dp[i+1][j+a[i+1]]=1;
                dp[i+1][j-a[i+1]]=1;
            }
        }
    }
    int ans=0;
    for (int i=0;i<200*200;i++){
        if (dp[n][i]){
            ans=i;
        }
    }
    cout<<ans-kek<<"\n";
}