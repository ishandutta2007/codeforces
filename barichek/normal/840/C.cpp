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

bool is_sqr(int a)
{
    int sqrt=sqrtl(a);
    for (int i=sqrt-1;i<=sqrt+1;i++){
        if (i*i==a){
            return 1;
        }
    }
    return 0;
}

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%md;
        }
        a=a*a%md;
        n/=2;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

int f[arr];
int rf[arr];

void init()
{
    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }
    rf[arr-1]=inv(f[arr-1]);
    for (int i=arr-2;i>=0;i--){
        rf[i]=rf[i+1]*(i+1)%md;
    }
}

int C(int n,int k)
{
    if (n<k||k<0){
        return 0;
    }
//    cerr<<"C("<<n<<","<<k<<")"<<" :: "<<f[n]*rf[k]%md*rf[n-k]%md<<"\n";
    return f[n]*rf[k]%md*rf[n-k]%md;
}

bool use[arr];
int a[arr];
vi reb[arr];

int dfs(int now)
{
    use[now]=1;
    int res=1;
    for (auto wh:reb[now]){
        if (!use[wh]){
            res+=dfs(wh);
        }
    }
    return res;
}

int dp[ar][ar];

void inc(int& a,int b)
{
    a+=b;
    a%=md;
}

int mult(int& a,int b)
{
    a*=b;
    a%=md;
}

int solve(vi v)
{
    sort(all(v),greater<int>());
//    cerr<<"solve :: ";
//    for (auto i:v){
//        cerr<<i<<" ";
//    }
//    cerr<<"\n";
    dp[0][v[0]-1]=f[v[0]];
    int pref_sum=0;
    for (int i=0;i+1<len(v);i++){
        pref_sum+=v[i];
        for (int j=0;j<pref_sum;j++){
            if (dp[i][j]){
                int to_push=v[i+1];
                for (int new_block=1;new_block<=to_push;new_block++){
                    for (int bad=0;bad<=min(j,new_block);bad++){
                        int ways=1;
                        mult(ways,f[to_push]);
                        mult(ways,C(to_push-1,new_block-1));
                        mult(ways,C(j,bad));
                        mult(ways,C(pref_sum+1-j,new_block-bad));
                        mult(ways,dp[i][j]);
                        inc(dp[i+1][j+to_push-bad-new_block],ways);
                    }
                }
            }
        }
    }
    return dp[len(v)-1][0];
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

    init();

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (is_sqr(a[i]*a[j])){
                reb[i].pb(j);
            }
        }
    }
    vi v(0);
    for (int i=1;i<=n;i++){
        if (!use[i]){
            v.pb(dfs(i));
        }
    }
    cout<<solve(v)<<"\n";
}