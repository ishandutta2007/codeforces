#include <bits/stdc++.h>
using namespace std;
const int N=200005;

int n;
vector<int> a[N];

long long z[N],zg[N],k[N],kg[N];

void dfs(int x,int p)
{
    z[x]++;
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(h==p)
            continue;
        dfs(h,x);
        z[x]+=k[h];
        zg[x]+=(k[h]+kg[h]);
        k[x]+=z[h];
        kg[x]+=(z[h]+zg[h]);
    }
}

long long ans;
void dfs2(int x,int p,long long zz,long long zzg,long long kk,long long kkg)
{
    ans+=(zzg/2);
    ans+=((kkg-kk)/2+kk);
    ans+=(zg[x]/2);
    ans+=((kg[x]-k[x])/2+k[x]);
    for(int i=0;i<a[x].size();++i)
    {
        int h=a[x][i];
        if(h==p)
            continue;
        z[x]-=k[h];
        zg[x]-=(k[h]+kg[h]);
        k[x]-=z[h];
        kg[x]-=(z[h]+zg[h]);
        dfs2(h,x,kk+k[x],kk+k[x]+kkg+kg[x],zz+z[x],zz+z[x]+zzg+zg[x]);
        z[x]+=k[h];
        zg[x]+=(k[h]+kg[h]);
        k[x]+=z[h];
        kg[x]+=(z[h]+zg[h]);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,1);
    dfs2(1,1,0,0,0,0);
    cout<<ans/2<<endl;
	return 0;
}