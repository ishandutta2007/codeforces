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

int sum(int a,int b)
{
    a+=b;
    while (a>=md){
        a-=md;
    }
    while (a<0){
        a+=md;
    }
    return a;
}

void add(int& a,int b)
{
    a=sum(a,b);
}

#define arr (int)(3e5+10)

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

int cnt[arr];

int d[arr];
int f[arr];
int rf[arr];

int u[arr];

int C(int n,int k)
{
    if (n<k){
        return 0;
    }
    return f[n]*rf[k]%md*rf[n-k]%md;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }

    rf[arr-1]=bpow(f[arr-1],md-2);
    for (int i=arr-2;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%md;
    }

    u[1]=1;
    for (int i=2;i<arr;i++){
        if (!d[i]){
            d[i]=i;
            for (int j=2*i;j<arr;j+=i){
                if (!d[j]){
                    d[j]=i;
                }
            }
        }
    }

    for (int i=2;i<arr;i++){
        u[i]=1;
        int cur=i;
        while (cur!=1){
            int dd=d[cur];
            while (cur%dd==0){
                cur/=dd;
                u[i]*=-1;
            }
        }
    }
    for (int i=2;i*i<arr;i++){
        for (int j=i*i;j<arr;j+=i*i){
            u[j]=0;
        }
    }

    int n;
    cin>>n;
    int g=0;
    while (n--){
        int a;
        cin>>a;
        g=__gcd(g,a);
        cnt[a]++;
    }
    if (g!=1){
        cout<<-1<<"\n";
        return 0;
    }
    for (int i=1;i<arr;i++){
        for (int j=2*i;j<arr;j+=i){
            cnt[i]+=cnt[j];
        }
    }

    for (int i=1;i<=7;i++){
        int ans=0;
        for (int j=1;j<arr;j++){
//            if (C(cnt[j],i)){
//                cout<<j<<" "<<u[j]<<" "<<cnt[j]<<" "<<C(cnt[j],i)<<"\n";
//            }
            add(ans,u[j]*C(cnt[j],i));
        }
        if (ans){
            cout<<i<<"\n";
            return 0;
        }
    }
}