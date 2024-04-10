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
int p[maxn],a[maxn],l[maxn];
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++) cin>>p[i+1],l[p[i+1]]=1;
    int check=1;
    for (int i=2;i<=n;i++)
        if (!l[i]) a[p[i]]++;
    for (int i=1;i<=n;i++)
        if (l[i] && a[i]<3) check=0;
    if (check) cout<<"Yes"; else cout<<"No";
    return 0;
}