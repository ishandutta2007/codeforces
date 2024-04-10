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

#define md (int)(1e9+9)

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

int inv(int a,int m=md)
{
    return a==1?1:(1-inv(m%a,a)*m)/a+m;
}

int get_sum(int b1,int q,int n)
{
    if (q==1){
        return b1*n%md;
    }
    int res=b1*(bpow(q,n)-1)%md*inv(q-1)%md;
    res%=md;
    res+=md;
    res%=md;
    return res;
}

int A[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,a,b,k;
    cin>>n>>a>>b>>k;
    int sum=0;
    for (int i=0;i<k;i++){
        char c;
        cin>>c;
        A[i]=1-2*(c=='-');
        sum+=A[i]*bpow(a,n-i)*bpow(b,i)%md;
        sum%=md;
        sum+=md;
        sum%=md;
    }

    int kek=(n+1)/k;

    int skok=bpow(b,k)*inv(bpow(a,k))%md;
    skok%=md;
    skok+=md;
    skok%=md;

    cout<<get_sum(sum,skok,kek)<<"\n";
}