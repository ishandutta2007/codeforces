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

const int N=12;
int pos_of_bit[1ll<<N];

int dp[1ll<<N];
int dp1[1ll<<N];

int a[ar][ar];
int sums[1ll<<N];

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pii> vec(0);
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for (int j=0;j<m;j++){
        int m=-1e9;
        for (int i=0;i<n;i++){
            m=max(m,a[i][j]);
        }
        vec.pb(mp(m,j));
    }
    sort(all(vec));
    reverse(all(vec));
    while (len(vec)>n){
        vec.pop_back();
    }
    for (int i=0;i<(1ll<<N);i++){
        dp[i]=-1e9;
    }
    dp[0]=0;
    for (int j_=0;j_<len(vec);j_++){
        int j=vec[j_].sec;
        if (1){
            int last=0;
            int sum=0;
            for (int pos=1;pos<(1ll<<n);pos++){
                int cur=pos^(pos>>1);
                int bit=pos_of_bit[cur^last];
                if (cur&(1ll<<bit)){
                    sum+=a[bit][j];
                }
                else{
                    sum-=a[bit][j];
                }
                sums[cur]=sum;
                last=cur;
            }
        }
        for (int i=0;i<(1ll<<n);i++){
            for (int j=0;j<n;j++){
                int new_mask=0;
                for (int k=0;k<n;k++){
                    if (i&(1ll<<k)){
                        new_mask|=(1ll<<((k+j)%n));
                    }
                }
                sums[new_mask]=max(sums[new_mask],sums[i]);
            }
        }
        for (int i=0;i<(1ll<<n);i++){
            dp1[i]=-1e9;
        }
        for (int mask=0;mask<(1ll<<n);mask++){
            int rev=((1ll<<n)-1)^mask;
            for (int sub=rev;sub>0;sub=(sub-1)&rev){
                dp1[mask|sub]=max(dp1[mask|sub],dp[mask]+sums[sub]);
            }
        }
        for (int i=0;i<(1ll<<n);i++){
            dp[i]=max(dp1[i],dp[i]);
        }
    }
    cout<<dp[(1ll<<n)-1]<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<N;i++){
        pos_of_bit[1ll<<i]=i;
    }

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}