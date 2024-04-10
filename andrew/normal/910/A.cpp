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
    cin >> n >> m;
    string s1;
    cin >> s1;
    for(i=0;i<n;i++)
    {
        if(s1[i]=='0')b[i+1]=-1;else b[i+1]=1e18;
    }
    b[1]=0;
    for(i=1;i<=n;i++)if(b[i]!=-1 && b[i]!=1e18)
    {
        for(j=i+1;j<=min(i+m,n);j++)b[j]=min(b[j],b[i]+1);
    }
    if(b[n]==1e18)b[n]=-1;
    cout << b[n] << endl;
    return 0;
}