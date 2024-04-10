#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=1e5+1,msiz=2,mod=1e9+7,inf=1e18;
int check=0,a[16],n;

void dfs(int i,int s)
{
    if (i>n)
    {
        if (!s) check=1;
        return;
    }
    dfs(i+1,(s+a[i])%360);
    dfs(i+1,(s-a[i]+360)%360);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0);
    if (check) cout<<"YES"; else cout<<"NO";
    return 0;
}