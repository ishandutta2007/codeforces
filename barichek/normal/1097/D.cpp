#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
///#define int long long

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

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=1ll*res*a%md;
        }
        n/=2;
        a=1ll*a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

const int M=52;
const int K=1e4+10;

int dp[K][M][M];
int pref[arr];

int invs[ar];

void calc_magic_dp()
{
    for (int a=1;a<M;a++){
        dp[0][a][a]=1;
    }
//    for (int i=0;i+1<K;i++){
//        for (int a=1;a<M;a++){
//            for (int b=0;b<=a;b++){
//                for (int c=0;c<=b;c++){
//                    dp[i+1][a][c]=(dp[i+1][a][c]+1ll*dp[i][a][b]*inv(b+1)%md)%md;
//                }
//            }
//        }
//    }

    for (int i=0;i+1<K;i++){
        for (int a=1;a<M;a++){
            pref[a]=1ll*dp[i][a][a]*invs[a+1]%md;
            for (int j=a-1;j>=0;j--){
                pref[j]=(pref[j+1]+1ll*dp[i][a][j]*invs[j+1]%md);
                if (pref[j]>=md){
                    pref[j]-=md;
                }
            }
            for (int c=0;c<=a;c++){
                dp[i+1][a][c]=pref[c];
            }
        }
    }
}

ll ans;
vector<pair<ll,int>> a;
ll n,k;

void rec(int id,ll val,int kf)
{
//    cout<<"rec :: "<<id<<" "<<val<<" "<<kf<<"\n";
    if (id==len(a)){
        ans=(ans+val%md*kf%md)%md;
        return;
    }
    ll kek=1;
    for (int j=0;j<=a[id].sec;j++){
        rec(id+1,val*kek,1ll*kf*dp[k][a[id].sec][j]%md);
        kek=kek*a[id].fir;
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=1;i<ar;i++){
        invs[i]=inv(i);
    }

    calc_magic_dp();

    cin>>n>>k;
    if (n==1){
        cout<<1<<"\n";
        return 0;
    }
    map<ll,int> m;
    for (ll i=2;i*i<=n;i++){
        while (n%i==0){
            m[i]++;
            n/=i;
        }
    }
    if (n!=1){
        m[n]++;
    }
    a.assign(all(m));
    rec(0,1,1);
    cout<<ans<<"\n";
}