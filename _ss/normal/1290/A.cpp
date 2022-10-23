#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10,inf=2e9;
int n,m,k,a[N];

void read()
{
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void process()
{
    int res=0;
    k=min(k,m-1);
    int h=m-1-k;
    for (int i=0;i<=k;i++)
    {
        int l=1+i,r=n-(k-i);
        int can=inf;
        for (int j=0;j<=h;j++)
        {
            int u=l+j,v=r-(h-j);
            can=min(can,max(a[u],a[v]));
        }
        res=max(res,can);
    }
    cout<<res<<"\n";
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        read();
        process();
    }
    return 0;
}