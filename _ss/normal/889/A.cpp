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

int mark[maxn];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,x;
    cin>>n;
    int res=1;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (mark[x]) res++;
        else mark[x]=1;
    }
    cout<<res;
    return 0;
}