#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
const int N=100000;
pii a[N], tr[2*N];
int n, ans[N];

pii get_min(int l, int r)
{
    pii res={1000000000,0};
    for(l+=n, r+=n; l<=r; l=(l+1)>>1, r=(r-1)>>1)
    {
        if(l&1) res=min(res,tr[l]);
        if(!(r&1)) res=min(res,tr[r]);
    }
    return res;
}

int solve(int l, int r)
{
    pii g=get_min(l,r);
    int m=g.ss;
    if(l<m)
        ans[solve(l,m-1)]=m;
    if(r>m)
        ans[solve(m+1,r)]=m;
    return g.ff;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i].ff, a[i].ss=i;
    sort(a,a+n);
    for(int i=0; i<n; i++)
        tr[i+n]={a[i].ss,i};
    for(int i=n-1; i>0; i--)
        tr[i]=min(tr[i*2],tr[i*2+1]);
    solve(0,n-1);
    for(int i=1; i<n; i++)
        cout<<a[ans[i]].ff<<' ';
    return 0;
}