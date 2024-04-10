#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
template <typename T>
T sqr(T x)
{
    return x*x;
}
const ll shl=1;
const ll MAXN=1123456;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll dp[MAXN];
bool f[MAXN];
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll W,B,X;
    cin >> n >> W >> B >> X;
    for(i = 0; i < n; i++)cin >> a[i];
    for(i = 0; i < n; i++)sc += a[i];
    for(i = 0; i < n; i++)cin >> b[i];
    dp[0] = W;
    f[0] = 1;
    ll i1;
    for(i = 0; i < n; i++){
        for(j = 0; j < a[i]; j++){
            for(i1 = sc; i1 > 0; i1--)if(f[i1 - 1] && dp[i1 - 1] >= b[i]){
                if(!f[i1])dp[i1] = dp[i1 - 1] - b[i];
                f[i1] = 1;
                dp[i1] = max(dp[i1],dp[i1 - 1] - b[i]);
            }
        }
        for(j = 0; j <= sc; j++)if(f[j])dp[j] = min(dp[j] + X, W + j * B);
    }
    i = sc;
    while(1){
        if(f[i])vout(i);
        i--;
    }
    return 0;
}