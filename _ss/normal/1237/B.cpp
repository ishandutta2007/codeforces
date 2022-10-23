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
const ll maxn=1e5+10,mod=1e9+7,inf=1e18;
int a[maxn],s[maxn],n;

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int x;
    for (int i=1;i<=n;i++) cin>>x,s[x]=i;
    int res=0,m=s[a[1]];
    for (int i=2;i<=n;i++)
    {
        if (s[a[i]]<m) res++;
        m=max(m,s[a[i]]);
    }
    cout<<res;
    return 0;
}