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

int dp[2][1ll<<20];
int cnt[71];
int lol[71];
int p2[arr];

bool is_prime(int a)
{
    if (a<=1){
        return 0;
    }
    for (int i=2;i*i<=a;i++){
        if (a%i==0){
            return 0;
        }
    }
    return 1;
}

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

    int kek=0;
    for (int i=2;i<=70;i++){
        if (is_prime(i)){
            lol[i]=kek++;
        }
    }
    
    fast;

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    dp[1][0]=1;
    for (int i=1;i<=70;i++){
        if (cnt[i]){
            for (int j=0;j<(1ll<<kek);j++){
                dp[0][j]=dp[1][j];
                dp[1][j]=0;
            }
            int mask=0;
            int lool=i;
            for (int j=1;j<=70;j++){
                if (is_prime(j)){
                    while (lool%j==0){
                        mask^=(1ll<<lol[j]);
                        lool/=j;
                    }
                }
            }
            for (int j=0;j<(1ll<<kek);j++){
                dp[1][j]+=dp[0][j]*p2[cnt[i]-1]%md;
                if (dp[1][j]>=md){
                    dp[1][j]-=md;
                }
            }
            for (int j=0;j<(1ll<<kek);j++){
                dp[1][j^mask]+=dp[0][j]*((p2[cnt[i]]-p2[cnt[i]-1]+md)%md)%md;
                if (dp[1][j^mask]>=md){
                    dp[1][j^mask]-=md;
                }
            }
        }
    }
    cout<<(dp[1][0]-1+md)%md<<"\n";
}