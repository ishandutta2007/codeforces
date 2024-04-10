#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
#define mp make_pair
const ll maxn=2e5+10,mod=1e9+7,inf=1e18;
int a[maxn],n,r[maxn],mark[maxn],sl[maxn],q;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        r[a[i]]=i;
        sl[a[i]]++;
    }
    int i=1,d=0,t;
    while (i<=n)
    {
        int tmp=i,mm=sl[a[i]];
        t=r[a[i]];
        mark[a[i]]=1;
        for (;i<=t;i++)
            if (!mark[a[i]])
            {
                mark[a[i]]=1;
                t=max(t,r[a[i]]);
                mm=max(mm,sl[a[i]]);
            }
        d+=i-tmp-mm;
    }
    cout<<d;
    return 0;
}