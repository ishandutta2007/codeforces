#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".in","r",stdin); freopen (name".out","w",stdout);
#define time pdojegoritg
#define left eorgjrptgj
#define right rtyjtokh
#define int ll
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int arr=3e5+100;
int md=998244353;

map<pair<int,int>,int > mp;

int bpow(int u, int step)
{
    if (mp.count({u,step}))
        return(mp[{u,step}]);
    if (step==0)
        return(mp[{u,step}]=1);
    if (step%2)
        return(mp[{u,step}]=bpow(u,step-1)*u%md);
    return(mp[{u,step}]=bpow(u*u%md,step/2));
}

int cp[2100][2100],strong[2100],ans[2100];

signed main()
{
    int n;
    cin>>n;
    int p,b;
    cin>>p>>b;
    p*=bpow(b,md-2);
    p%=md;

    for (int i=0;i<=n;i++)
        cp[i][0]=1;

    for (int s=1;s<=n;s++)
        for (int c=1;c<=s;c++)
    {
        cp[s][c]=cp[s-1][c]*bpow((1-p+md)%md,c)%md+cp[s-1][c-1]*bpow(p,s-c)%md;
        cp[s][c]%=md;
    }

    strong[0]=1;
    strong[1]=1;

    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<i;j++)
        {
            strong[i]+=strong[j]*cp[i][j]%md;
            strong[i]%=md;
        }
        strong[i]=(1-strong[i]+md)%md;
    }

    ans[0]=ans[1]=0;

    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<i;j++)
        {
            ans[i]+=strong[j]*cp[i][j]%md*(j*(i-j)%md+j*(j-1)%md*bpow(2,md-2)%md+ans[j]+ans[i-j]);
            ans[i]%=md;
        }
        int k=strong[i]%md;
        ans[i]+=k*i*(i-1)%md*bpow(2,md-2)%md;
        ans[i]%=md;
        ans[i]*=bpow((1-k+md)%md,md-2);
        ans[i]%=md;
    }

    cout<<ans[n];
}