#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define arr vector<ll>
const ll maxn=2e5+10,msiz=2,mod=1e9+7,inf=1e18;
pii b[maxn];
int a[maxn],ans[maxn];
bool cmp(int t1,int t2) {return t1>t2;}
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++) cin>>b[i].fi,b[i].se=i;
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++) ans[b[i].se]=a[i];
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}