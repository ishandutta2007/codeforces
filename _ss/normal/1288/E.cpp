#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=3e6+10;
int n,m,a[N],mark[N],ans[N],bit[N],last[N];

void read()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++) scanf("%d",&a[i]),mark[a[i]]=1;
}

void add(int v,int x)
{
    for (int i=v;i<=m+n;i+=(i&-i)) bit[i]+=x;
}

int get(int v)
{
    int res=0;
    for (int i=v;i>0;i-=(i&-i)) res+=bit[i];
    return res;
}

void process()
{
    for (int i=1;i<=n;i++) ans[i]=i;
    for (int i=1;i<=n;i++) last[i]=m+i,add(m+i,1);
    for (int i=1;i<=m;i++)
    {
        ans[a[i]]=max(ans[a[i]],get(last[a[i]]));
        add(last[a[i]],-1);
        last[a[i]]=m-i+1;
        add(m-i+1,1);
    }
    for (int i=1;i<=n;i++) ans[i]=max(ans[i],get(last[i]));
    for (int i=1;i<=n;i++)
        if (mark[i]) cout<<1<<" "<<ans[i]<<"\n";
        else cout<<i<<" "<<ans[i]<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    read();
    process();
    return 0;
}