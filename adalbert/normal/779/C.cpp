#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef double ld;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define int ll
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
pair<int,int> a[400000];
int sum1[400000],sum2[400000];
bool check(pair<int,int> i, pair<int,int> j)
{

    return(i.fir-j.fir<i.sec-j.sec);
}
signed main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].fir;
    }
    for (int i=1;i<=n;i++)
        cin>>a[i].sec;
    sort(a+1,a+1+n,check);
    for (int i=1;i<=n;i++)
        sum1[i]=sum1[i-1]+a[i].fir;
    for (int i=n;i>=1;i--)
        sum2[i]=sum2[i+1]+a[i].sec;
    int ans=(ll)1e16;
    for (int i=k;i<=n;i++)
        ans=min(ans,sum1[i]+sum2[i+1]);
    cout<<ans;
}