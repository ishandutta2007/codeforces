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
const ll inf=1e18+10;

///---program start---///

#define ar (int)(100+10)

int type[ar];

int dp[ar][ar][2]; /// [pref][set_even]

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    for (int i=0;i<ar;i++){
        for (int j=0;j<ar;j++){
            dp[i][j][0]=inf;
            dp[i][j][1]=inf;
        }
    }    
    int n;
    cin>>n;
    int set_evens=0;
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        if (a!=0){
            type[i]=a%2;
            set_evens+=(a%2==0);
        }
        else{
            type[i]=-1;
        }
    }
    int evens=n/2;
    int odds=n-n/2;
    int want_set_even=evens-set_evens;
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=want_set_even;j++){
            // cout<<"dp["<<i<<"]["<<j<<"] :: "<<dp[i][j][0]<<" "<<dp[i][j][1]<<"\n";
            for (int last=0;last<2;last++){
                int l=0,r=1;
                if (type[i+1]!=-1){
                    l=type[i+1];
                    r=type[i+1];
                }
                for (int neww=l;neww<=r;neww++){
                    if (neww==0){
                        if (j!=want_set_even||type[i+1]==0){
                            minimize(dp[i+1][j+(type[i+1]==-1)][neww],dp[i][j][last]+(last!=neww));
                        }
                    }
                    if (neww==1){
                        minimize(dp[i+1][j][neww],dp[i][j][last]+(last!=neww));
                    }
                }
            }
        }
    }
    cout<<min(dp[n][want_set_even][0],dp[n][want_set_even][1])<<"\n";
}