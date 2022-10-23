#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const ll N=1e5+10,mod=1e9+7,inf=1e18;
int n,k,a[N],s=0,ans[N],d=1;
int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    if (s%k)
    {
        cout<<"No";
        return 0;
    }
    int t=0;
    for (int i=1;i<=n;i++)
        if (t+a[i]<s/k) ans[d]++,t+=a[i];
        else if (t+a[i]==s/k) ans[d++]++,t=0;
        else
        {
            cout<<"No";
            return 0;
        }
    cout<<"Yes\n";
    for (int i=1;i<=k;i++) cout<<ans[i]<<" ";
    return 0;
}