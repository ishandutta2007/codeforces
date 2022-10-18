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

#define arr (int)(1e6+10)

struct mebius
{
    vi dp;

    mebius()
    {
        dp.assign((1ll<<20),0);
    }

    void build()
    {
        for (int i=0;i<20;i++){
            for (int mask=0;mask<(1ll<<20);mask++){
                if (mask&(1ll<<i)){
                    dp[mask]+=dp[mask^(1ll<<i)];
                }
            }
        }
    }

    int get(int a)
    {
        return dp[a];
    }
};

int p2[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    p2[0]=1;
    for (int i=1;i<arr;i++){
        p2[i]=p2[i-1]*2%md;
    }

    mebius M;

    fast;

    int n;
    cin>>n;
    while (n--){
        int a;
        cin>>a;
        a^=((1ll<<20)-1);
        M.dp[a]++;
    }
    M.build();
    int mask=0;
    int ans=0;
    for (int mask=0;mask<(1ll<<20);mask++){
        int cur=p2[M.get(mask^((1ll<<20)-1))]-1;
        if (__builtin_popcountll(mask)&1){
            ans-=cur;

            ans%=md;
            ans+=md;
            ans%=md;
        }
        else{
            ans+=cur;
            ans%=md;
            ans+=md;
            ans%=md;
        }
    }
    cout<<ans<<"\n";
}