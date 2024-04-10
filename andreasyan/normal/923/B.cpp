#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N=100003;

int n;
long long a[N];
long long ans[N];
vector<int> t[N];

long long b[N];
long long p[N];

long long sum(int l,int r)
{
    return p[r]-p[l-1];
}
int byn(int x)
{
    int l=x,r=n;
    while((r-l)>4)
    {
        int m=(l+r)/2;
        if(sum(x,m)>=a[x])
            r=m;
        else
            l=m;
    }
    for(int i=l;i<=r;++i)
        if(sum(x,i)>=a[x])
            return i;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;++i)
        p[i]=p[i-1]+b[i];
//////////////////////////
    for(int i=1;i<=n;++i)
    {
        int x=byn(i);
        if(x!=-1)
            t[x].push_back(i);
    }
//////////////////////////
    long long v=0;
    for(int i=1;i<=n;++i)
    {
        ans[i]=(i-v-t[i].size())*b[i];
        for(int j=0;j<t[i].size();++j)
        {
            int x=t[i][j];
            ans[i]+=(a[x]-sum(x,i-1));
        }
        v+=t[i].size();
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    return 0;
}