#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll binpow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
ll log(ll a,ll b){
    ll res=0;
    while(a){
        a/=b;
        res++;
    }
    return res;
}
const ll shl=1;
const ll MAXN=1123456;
vector <ll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll dp[1001][1001],dp1[1001][1001][2];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> s1;
    n=s1.size();
    cin >> k;
    if(k==0)vout(1);
    for(i=1;i<=1000;i++){
        ll ke=i;
        sc=0;
        while(ke>1){
            x=ke;
            ke=0;
            while(x){ke+=x%2;x/=2;}
            sc++;
        }
        a[i]=sc+1;
    }
    ll md=1e9+7;
    dp[1][1]=1;
    for(i=1;i<n;i++){
        for(j=1;j<=i;j++)if(dp[i][j]){
            dp[i+1][j]+=dp[i][j];
            dp[i+1][j]%=md;
            dp[i+1][j+1]+=dp[i][j];
            dp[i+1][j+1]%=md;
        }
    }
    for(i=2;i<n;i++)
    for(j=1;j<=i;j++)if(a[j]==k){
        ans+=dp[i][j];
        ans%=md;
    }
    dp1[1][1][1]=1;
    for(i=1;i<n;i++){
        for(j=1;j<=i;j++){
                dp1[i+1][j+1][0]+=dp1[i][j][0];
                dp1[i+1][j+1][0]%=md;
            if(s1[i]=='1'){
                dp1[i+1][j][0]+=dp1[i][j][0];
                dp1[i+1][j][0]+=dp1[i][j][1];
                dp1[i+1][j][0]%=md;
                dp1[i+1][j+1][1]+=dp1[i][j][1];
                dp1[i+1][j+1][1]%=md;
            }else{
                dp1[i+1][j][1]+=dp1[i][j][1];
                dp1[i+1][j][1]%=md;
                dp1[i+1][j][0]+=dp1[i][j][0];
                dp1[i+1][j][0]%=md;
            }
        }
    }
    for(i=1;i<=n;i++)if(a[i]==k && n>1){
        ans+=dp1[n][i][1];
        ans+=dp1[n][i][0];
        ans%=md;
        ans%=md;
    }
    cout << ans%md << endl;;
    return 0;
}