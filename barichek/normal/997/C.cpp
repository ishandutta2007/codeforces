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

#define md (int)(998244353)

#define arr (int)(2e6+10)

int bpow(int a,ll n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*1ll*a%md;
        }
        n/=2;
        a=a*1ll*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

int f[arr];
int rf[arr];

int C(int n,int k)
{
    if (n<0||n<k){
        return 0;
    }
    return f[n]*1ll*rf[k]%md*rf[n-k]%md;
}

inline void add(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
    if (a<0){
        a+=md;
    }
}

int at_least[arr];
int pow2[arr];
int pow3[arr];
int inver[arr];

int wolfram_magic(int m)
{
    int res=1;

    res*=pow3[m];

    res=res*1ll*inver[m]%md;

    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*1ll*i%md;
    }
    rf[arr-1]=bpow(f[arr-1],md-2);
    for (int i=arr-2;i>=0;i--){
        rf[i]=rf[i+1]*1ll*(i+1)%md;
    }

    pow2[0]=1;
    pow3[0]=1;
    for (int i=1;i<arr;i++){
        pow2[i]=pow2[i-1]+pow2[i-1];
        if (pow2[i]>=md){
            pow2[i]-=md;
        }
        pow3[i]=pow3[i-1]*1ll*3%md;
    }

    inver[arr-1]=inv(pow2[arr-1]);
    for (int i=arr-2;i>=0;i--){
        inver[i]=inver[i+1]+inver[i+1];
        if (inver[i]>=md){
            inver[i]-=md;
        }
    }

    int n;
    cin>>n;
    int ans=0;
    for (int i=1;i<=n;i++){
        int cur=1;

        cur*=bpow(3,n*1ll*(n-i));

        int val=pow3[n]-3;
        if (val<0){
            val+=md;
        }

        cur=cur*1ll*bpow(val,i-1)%md;

        cur=cur*1ll*3%md;

        add(ans,cur);
    }

//    cout<<"ans1 :: "<<ans<<"\n";

    /// now harrrrrrrrrrrrrrd

    for (int i=1;i<=n;i++){
        int cur=C(n,i);

        cur=cur*1ll*bpow(3,n*1ll*n-n*1ll*i)%md;

//        int val=(bpow(3,n)-3+md)%md;
//        cur*=bpow(val,i);

        int keeek=pow3[i]-3;
        if (keeek<0){
            keeek+=md;
        }

        cur=cur*1ll*keeek%md;

        add(at_least[i],cur);
    }

    for (int i=1;i<=n;i++){
        int cur=C(n,i)*1ll*3ll%md;

        int m=n-i;

        int lol=wolfram_magic(m)-inver[m];
        if (lol<0){
            lol+=md;
        }
        lol=lol*1ll*pow2[n-i]%md;

        lol=bpow(lol,n);

        cur=cur*1ll*lol%md;

        add(at_least[i],cur);
    }

    /// end of harrrrrrrrrrrrrrd

//    for (int i=1;i<=n;i++){
//        cout<<"at_least["<<i<<"] :: "<<at_least[i]<<"\n";
//    }

    for (int i=1;i<=n;i++){
        if (i&1){
            add(ans,at_least[i]);
        }
        else{
            add(ans,-at_least[i]);
        }
    }
    cout<<ans<<"\n";
}