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

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=(res*a)%md;
        }
        n/=2;
        a=(a*a)%md;
    }
    return res;
}

void inc(int& a,int b)
{
    a+=b;
    a%=md;
    a+=md;
    a%=md;
}

#define arr (int)(2e6+10)

int cnt[arr];

void add(int l,int r,int val)
{
    inc(cnt[l],val);
    inc(cnt[r+1],-val);
}

int mebius[arr];
int d[arr];
int lol[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    mebius[1]=1;
    for (int i=1;i<arr;i++){
        for (int j=2*i;j<arr;j+=i){
            mebius[j]-=mebius[i];
        }
    }

    int n,k;
    cin>>n>>k;

    for (int i=0;i<arr;i++){
        lol[i]=bpow(i,n);
    }

    /// do magic

    for (int j=1;j<=k;j++){
        if (mebius[j]){
            for (int i=j;i<=k;i+=j){
                int l=i,r=min(k,l+j-1);
                add(l,r,mebius[j]*lol[l/j]);
            }
        }
    }

    for (int i=1;i<arr;i++){
        inc(cnt[i],cnt[i-1]);
    }

    /// magic created

    /// now do easy
    int ans=0;
    for (int i=1;i<=k;i++){
        ans+=(cnt[i]^i);
        ans%=md;
    }
    cout<<ans<<"\n";
}