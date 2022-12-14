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
string s1,s2,s3;
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
    for(i=0;i<m;i++)
    {
        cin >> a1 >> b1 >> c1;
        k=0;
        ans=0;
        for(j=1;j<=n;j++)if(a[j]<a1)k++;
        if(k<b1)cout << -1;else
        {
            for(j=1;j<=n;j++)if(a[j]<a1 && b1>0)
            {
                b1--;
                a[j]=a1+c1-1;
                ans+=j;
            }
            cout << ans;
        }
        cout << endl;
    }
    return 0;
}