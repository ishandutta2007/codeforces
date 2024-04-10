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

#define md (int)(998244353)
#define arr (int)(1e4+10)

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res*=a;
            res%=md;
        }
        n/=2;
        a*=a;
        a%=md;
    }
    return res;
}

int f[arr];
int rf[arr];

void init()
{
    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }
    rf[arr-1]=bpow(f[arr-1],md-2);
    for (int i=arr-2;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%md;
    }
}

inline int C(int n,int k)
{
    return f[n]*rf[k]%md*rf[n-k]%md;
}

inline int A(int n,int k)
{
    return f[n]*rf[n-k]%md;
}

int kek2[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    init();

    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    int magic=0;
    for (int i=0;i<=min(b,c);i++){
        int cur=0;
        cur=A(b,i)*C(c,i)%md;
//        cout<<i<<" :: "<<A(b,i)<<" "<<C(c,i)<<"\n";
        magic+=cur;
        magic%=md;
    }
//    cout<<"magic :: "<<magic<<"\n";
    for (int j=0;j<=min(a,c);j++){
        kek2[j]=A(a,j)*C(c,j)%md;
    }
    for (int i=0;i<=min(a,b);i++){
        int kek1=A(a,i)*C(b,i)%md;
        for (int j=0;j<=min(a,c);j++){
            int cur=kek1*kek2[j]%md;
//            cout<<i<<" && "<<j<<" :: "<<cur<<"\n";
            ans=(ans+cur*magic%md)%md;
//            cout<<"new_ans :: "<<ans<<"\n";
        }
    }
    cout<<ans<<"\n";
}

/**

sum i
A(a1,0)*C(a2,0)+A(a1,1)*C(a2,1)+A(a1,2)*C(a2,2)

*/