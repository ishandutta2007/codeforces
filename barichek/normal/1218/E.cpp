//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

#define md (ll)(998244353ll)

void inc(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
}

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

const int K=16;
const int N=(1ll<<K);

int rev_N;
int pw[N];
int rpw[N];

void init()
{
    int root=-1;
    for (int i=2;;i++){
        if (bpow(i,N)==1){
            int cur=1;
            for (int j=1;j<N;j++){
                cur=1ll*cur*i%md;
                if (cur==1){
                    break;
                }
            }
            if (cur!=1){
                root=i;
                break;
            }
        }
    }
    pw[0]=1;
    for (int i=1;i<N;i++){
        pw[i]=1ll*pw[i-1]*root%md;
    }
    int rroot=bpow(root,md-2);
    rpw[0]=1;
    for (int i=1;i<N;i++){
        rpw[i]=1ll*rpw[i-1]*rroot%md;
    }
}

void fft(int* a,int* pw)
{
    for (int i=0;i<N;i++){
        int r=0;
        for (int j=0;j<K;j++){
            if (i&(1ll<<j)){
                r|=(1ll<<(K-j-1));
            }
        }
        if (i<r){
            swap(a[i],a[r]);
        }
    }
    for (int i=1,pl=N/2;i<N;i*=2,pl/=2){
        for (int j=0;j<N;j+=2*i){
            for (int k=j,cur=0;k<j+i;k++,cur+=pl){
                int L=a[k];
                int R=1ll*pw[cur]*a[k+i]%md;
                a[k]=L+R;
                if (a[k]>=md){
                    a[k]-=md;;
                }
                a[k+i]=L-R;
                if (a[k+i]<0){
                    a[k+i]+=md;
                }
            }
        }
    }
}

void make_mult(int* a,int* b,int* c) /// c=a*b
{
    fft(a,pw);
    fft(b,pw);
    for (int i=0;i<N;i++){
        c[i]=1ll*a[i]*b[i]%md;
    }
    fft(c,rpw);
    for (int i=0;i<N;i++){
        c[i]=1ll*c[i]*rev_N%md;
    }
}

/*

    Q*(N*B+N/B*N*log(N))

    N*B==N*N*log(N)/B
    B*B==N*log(N)
    B=sqrt(N*log(N))
*/

const int B=1000;

int fft_bl[N/B+10][N];

int a[N];
int b[N];

int dp[B+10][B+10];
int ans_fft[N];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    init();
    rev_N=bpow(N,md-2);

    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    auto get_ans=[&](int q)
    {
        for (int i=0;i<n;i++){
            b[i]=q-a[i];
            b[i]%=md;
            if (b[i]<0){
                b[i]+=md;
            }
        }
//        cout<<"b :: ";
//        for (int i=0;i<n;i++){
//            cout<<b[i]<<" ";
//        }
//        cout<<"\n";
        int num=0;
        for (int bl_st=0;bl_st<n;bl_st+=B){
            int L=bl_st;
            int R=min(n-1,L+B-1);
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for (int j=L;j<=R;j++){
                for (int t=0;t<=j-L;t++){
                    inc(dp[j-L+1][t],dp[j-L][t]);
                    inc(dp[j-L+1][t+1],1ll*dp[j-L][t]*b[j]%md);
                }
            }
            for (int j=0;j<=B;j++){
                fft_bl[num][j]=dp[R-L+1][j];
            }
            for (int j=B+1;j<N;j++){
                fft_bl[num][j]=0;
            }
            num++;
        }
//        return fft_bl[0][2];
        memset(ans_fft,0,sizeof(ans_fft));
        ans_fft[0]=1;
        for (int i=0;i<num;i++){
            make_mult(ans_fft,fft_bl[i],ans_fft);
        }
        return ans_fft[k];
    };

    int Q;
    cin>>Q;
    while (Q--){
        int type,q;
        cin>>type>>q;
        if (type==1){
            int pos,d;
            cin>>pos>>d;
            pos--;
            int buf=a[pos];
            a[pos]=d;
            cout<<get_ans(q)<<"\n";
            a[pos]=buf;
        }
        else{
            int l,r,d;
            cin>>l>>r>>d;
            l--;
            r--;
            for (int j=l;j<=r;j++){
                a[j]+=d;
            }
            cout<<get_ans(q)<<"\n";
            for (int j=l;j<=r;j++){
                a[j]-=d;
            }
        }
    }
}