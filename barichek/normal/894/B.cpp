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

int ans(int n,int m)
{
    int res=0;
    for (int mask=0;mask<(1ll<<(n*m));mask++){
        bool ok=1;
        for (int i=0;i<n;i++){
            int cnt=0;
            for (int j=0;j<m;j++){
                if (mask&(1ll<<(i*m+j))){
                    cnt++;
                }
            }
            ok&=(cnt%2==1);
        }
        for (int j=0;j<m;j++){
            int cnt=0;
            for (int i=0;i<n;i++){
                if (mask&(1ll<<(i*m+j))){
                    cnt++;
                }
            }
            ok&=(cnt%2==1);
        }
        if (ok){
            res++;
        }
    }
    return res;
}

int bpow(int a,int n)
{
    if (n==0){
        return 1;
    }
    if (n&1){
        return a*bpow(a,n-1)%md;
    }
    else{
        return bpow(a*a%md,n/2);
    }
}

int sum(int n)
{
    return ((n%(md-1))*(n%(md-1)))%(md-1);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,k;
    cin>>n>>m>>k;
    if (k==1){
        int lol=(min(n,m)==1?0:((n-1)%(md-1))*((m-1)%(md-1))%(md-1));
        cout<<bpow(2,lol)<<"\n";
    }
    else{
        if ((n+m)%2==1){
            cout<<0<<"\n";
        }
        else{
            int kek=(n+m)/2;
            int lol=sum(kek-1);
            int kek1=(n-m)/2;
            lol-=sum(kek1);
            lol%=md-1;
            lol+=md-1;
            lol%=md-1;
            cout<<bpow(2,lol)<<"\n";
        }
    }

//    int n,m;
//    for (int n=1;n<=6;n++){
//        for (int m=1;m<=n;m++){
//            cerr<<((n+m)%2==1?-1:log2(ans(n,m)))<<" ";
//        }
//        cerr<<"\n";
//    }
}