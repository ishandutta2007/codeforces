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

int n,k;
int a[arr];

int get(int ind)
{
    int l=max(ind-k,1ll);
    int r=min(ind+k,n);
    return r-l+1;
}

int dp[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        if (a[i]==0){
            dp[i]=get(i);
        }
        else{
            if (i-k>a[i]+k){
                dp[i]=dp[a[i]]+get(i);
            }
            else{
                dp[i]=dp[a[i]]+min(n,i+k)-min(n,a[i]+k);
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<"\n";
}