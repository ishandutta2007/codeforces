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
ll dp[MAXN],c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
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
    cin >> n;
    dp[0]=1;
    for(i=1;i<3;i++)
    {
        x=i;
        for(j=x;j<MAXN;j++)dp[j]+=dp[j-x];
    }
    for(i=1;i<MAXN;i++)if(dp[i]==n){cout << i << " ";break;}
    cout << 2 << endl;
    cout << 1 << " " << 2 << endl;
        return 0;
}