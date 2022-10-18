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

#define md (ll)(998244353)

#define arr (int)(1e6+10)

//int get(int n)
//{
//    int p[n];
//    for (int i=1;i<=n;i++){
//        p[i-1]=i;
//    }
//    vi a(0);
//    do{
//        for (int i=0;i<n;i++){
//            a.pb(p[i]);
//        }
//    }
//    while (next_permutation(p,p+n));
//    int res=0;
//    int res2=0;
//    for (int i=n-1;i<len(a);i++){
//        int sum=0;
//        for (int j=i-n+1;j<=i;j++){
//            sum+=a[j];
//        }
//        set<int> kek;
//        for (int j=i-n+1;j<=i;j++){
//            kek.insert(a[j]);
//        }
//        res+=(sum==n*(n+1)/2);
//        res2+=(sum==n*(n+1)/2&&len(kek)!=n);
//    }
//    cout<<n/10<<n%10<<" "<<res<<" "<<res2<<"\n";
//}

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%md;
        }
        n/=2;
        a=a*a%md;
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
    return f[n]*rf[k]%md*rf[n-k]%md;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    f[0]=1;

    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }

    rf[arr-1]=inv(f[arr-1]);
    for (int i=arr-2;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%md;
    }

    int n;
    cin>>n;
    int ans=f[n];
    for (int k=1;k<=n-1;k++){
        int cur=0;
        cur+=(f[k]-1)*f[n-k]%md*C(n,k)%md;
        ans+=cur;
        ans%=md;
    }

    cout<<ans<<"\n";

//    for (int i=1;i<=9;i++){
//        get(i);
//    }
//    for (int i=2;i<=9;i++){
//        diff1[i]=ans[i]-ans[i-1];
//        cout<<"diff1 :: "<<i/10<<i%10<<" :: "<<diff1[i]<<"\n";
//    }
//    for (int i=2;i<=9;i++){
//        diff2[i]=diff1[i]-diff1[i-1];
//        cout<<"diff2 :: "<<i/10<<i%10<<" :: "<<diff2[i]<<"\n";
//    }
//    for (int i=2;i<=9;i++){
//        diff3[i]=diff2[i]-diff2[i-1];
//        cout<<"diff3 :: "<<i/10<<i%10<<" :: "<<diff3[i]<<"\n";
//    }
//    for (int i=2;i<=9;i++){
//        diff4[i]=diff3[i]-diff3[i-1];
//        cout<<"diff4 :: "<<i/10<<i%10<<" :: "<<diff4[i]<<"\n";
//    }
//    for (int i=2;i<=9;i++){
//        diff5[i]=diff4[i]-diff4[i-1];
//        cout<<"diff4 :: "<<i/10<<i%10<<" :: "<<diff5[i]<<"\n";
//    }
}