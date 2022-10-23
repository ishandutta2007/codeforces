#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
int n,m,a[N],val[N],f[N],g[N];

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1,l,r;i<=n;i++)
    {
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }
    for (int i=2;i<=m;i++) a[i]+=a[i-1];
    int len=0;
    for (int i=1;i<=m;i++)
    {
        int vt=upper_bound(val+1,val+len+1,a[i])-val;
        if (vt>len) len++;
        val[vt]=a[i];
        f[i]=vt;
    }
    len=0;
    for (int i=m;i;i--)
    {
        int vt=upper_bound(val+1,val+len+1,a[i])-val;
        if (vt>len) len++;
        val[vt]=a[i];
        g[i]=vt;
    }
    int res=0;
    for (int i=1;i<=m;i++) res=max(res,f[i]+g[i]-1);
    cout<<res;
    return 0;
}