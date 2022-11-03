#include <bits/stdc++.h>

using namespace std;
long long l,r,x,n,m,a[500010],v[500010];
void rec(long long u)
{
    if (u==n) return;
    if (a[u]!=a[u+1])
    {
        v[u]=u+1;
        rec(u+1);
    } else
    if (a[u]==a[u+1])
    {
        rec(u+1);
        v[u]=v[u+1];
    }
}
int main()
{
    cin>>n>>m;
    for (long long i=1;i<=n;i++)
        cin>>a[i];
    rec(1);
    for (long long i=1;i<=m;i++)
    {
        scanf("%d%d%d", &l, &r, &x);
        if (a[l]!=x) cout<<l<<'\n'; else
            if (v[l]<=r && v[l]!=0) cout<<v[l]<<'\n'; else cout<<-1<<'\n';
    }

}