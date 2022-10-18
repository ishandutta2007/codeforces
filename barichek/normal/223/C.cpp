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

int inver[arr];

int CK[arr];

int C(int n,int k)
{
    if (k>n){
        return 0;
    }
    int res=1;
    for (int i=n;i>n-k;i--){
        res=res*i%md;
    }
    for (int i=1;i<=k;i++){
        res=res*inver[i]%md;
    }
    return res;
}

int CC[ar][ar];
int ways[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=0;i<ar;i++){
        CC[i][0]=1;
        for (int j=1;j<=i;j++){
            CC[i][j]=CC[i-1][j-1]+CC[i-1][j];
            if (CC[i][j]>=md){
                CC[i][j]-=md;
            }
        }
    }

    for (int i=1;i<arr;i++){
        inver[i]=inv(i);
    }

    int n,K;
    cin>>n>>K;

    for (int i=1;i<=n;i++){
        CK[i]=C(K,i);
    }

    for (int l=1;l<=n;l++){
        for (int k=1;k<=n;k++){
            ways[l]+=CC[l-1][k-1]*CK[k]%md;
            if (ways[l]>=md){
                ways[l]-=md;
            }
        }
    }

    vi a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    vi ans=a;
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
//            cout<<i<<" "<<j<<" "<<ways[i-j]<<"\n";
            ans[i]+=a[j]*ways[i-j]%md;
            if (ans[i]>=md){
                ans[i]-=md;
            }
        }
    }

    for (int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}