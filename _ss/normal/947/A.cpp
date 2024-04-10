#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e6+1,msiz=2,mod=1e9+7,inf=1e18;
int lp[maxn];

int mp(int x)
{
    int res=0;
    while (x>1)
    {
        res=max(res,lp[x]);
        x/=lp[x];
    }
    return res;
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)
        if (!lp[i])
            for (int j=i;j<=n;j+=i) lp[j]=i;
    int t=mp(n);
    int res=1e9;
    for (int i=n-t+1;i<=n;i++)
        if (lp[i]!=i) res=min(res,i-mp(i)+1);
    if (res<3) res=3;
    cout<<res;
    return 0;
}