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

ld rem_dp[ar][ar];
int n;
ld a[ar][ar];
ld rem_down[ar][ar];

ld down(int poson,int v,int l,int r)
{
//    cerr<<"down :: "<<poson<<" "<<v<<" || "<<l<<" "<<r<<"\n";
    if (poson==v-(1ll<<n)+1){
        return 1;
    }
    if (rem_down[poson][v]>-1e9){
        return rem_down[poson][v];
    }
    ld& res=rem_down[poson][v];
    int m=(l+r)/2;
    if (poson+(1ll<<n)-1<=m){
//        cerr<<"i go kek1"<<"\n";
        ld kek=0;
        for (int i=m+1;i<=r;i++){
            kek+=down(i-(1ll<<n)+1,v*2+1,m+1,r)*a[poson][i-(1ll<<n)+1];
        }
        return res=kek*down(poson,v*2,l,m);
    }
    else{
//        cerr<<"i go kek2"<<"\n";
        ld kek=0;
        for (int i=l;i<=m;i++){
            kek+=down(i-(1ll<<n)+1,v*2,l,m)*a[poson][i-(1ll<<n)+1];
        }
        return res=kek*down(poson,v*2+1,m+1,r);
    }
}

ld dp(int v,int poson,int l,int r,int deep)
{
//    cerr<<"dp :: "<<v<<" "<<poson<<" || "<<l<<" "<<r<<" "<<deep<<"\n";
    if (l+1==r){
        return a[poson][poson%2==1?poson+1:poson-1];
    }
    if (rem_dp[v][poson]>-1e9){
        return rem_dp[v][poson];
    }
    ld& res=rem_dp[v][poson];
    int m=(l+r)/2;
    if (poson+(1ll<<n)-1<=m){
//        cerr<<"kekuska 1\n";
        ld kek=0;
//        cerr<<"aaa : :: "<<poson<<"\n";
        for (int i=m+1;i<=r;i++){
            kek+=down(i-(1ll<<n)+1,v*2+1,m+1,r);
        }
        ld kek1=0;
        for (int i=m+1;i<=r;i++){
            kek1=max(kek1,dp(v*2+1,i-(1ll<<n)+1,m+1,r,deep/2));
        }
//        cerr<<"for kek1 :: "<<kek1<<" :: "<<v<<" "<<poson<<" || "<<l<<" "<<r<<"\n";
//        cerr<<"deep :: "<<deep<<"\n";
//        cerr<<"kek :: "<<kek<<"\n";
//        cerr<<"down(poson,v,l,r) :: "<<down(poson,v,l,r)<<"\n";
        return res=deep*kek*down(poson,v,l,r)+dp(v*2,poson,l,m,deep/2)+kek1;
    }
    else{
        ld kek=0;
        for (int i=l;i<=m;i++){
            kek+=down(i-(1ll<<n)+1,v*2,l,m);
        }
        ld kek1=0;
        for (int i=l;i<=m;i++){
            kek1=max(kek1,dp(v*2,i-(1ll<<n)+1,l,m,deep/2));
        }
        return res=deep*kek*down(poson,v,l,r)+dp(v*2+1,poson,m+1,r,deep/2)+kek1;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    for (int i=0;i<ar;i++){
        for (int j=0;j<ar;j++){
            rem_dp[i][j]=-1e10;
            rem_down[i][j]=-1e10;
        }
    }
    cin>>n;
    for (int i=1;i<=(1ll<<n);i++){
        for (int j=1;j<=(1ll<<n);j++){
            int aa;
            cin>>aa;
            a[i][j]=ld(aa)/100.0;
        }
    }

//    cout<<a[1][2]<<"\n";

//    cout<<fixed<<setprecision(10)<<dp(2,1,4,5,1)<<"\n";
//    cout<<fixed<<setprecision(10)<<down(4,3,6,7)<<"\n";

    ld ans=0;
    for (int i=1;i<=(1ll<<n);i++){
        ans=max(ans,dp(1,i,(1ll<<n),(1ll<<(n+1))-1,(1ll<<(n-1))));
    }
    cout<<fixed<<setprecision(10)<<ans<<"\n";
}