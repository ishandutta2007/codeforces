#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN=200005,MAXM=1000005,INF=1<<29;

int n,m,a[MAXN],s[MAXM],b[MAXN],bt;

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	s[a[i]]++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=a[n];i++)
    	s[i]+=s[i-1];
    for(int i=1;i<=n;i++)
    	if(a[i]!=a[i-1])b[++bt]=a[i];
    b[0]=-1;
    for(int i=2;i<=bt;i++)
    	ans+=s[b[i]-1]-s[max(b[i]-m,b[i-1])-1];
    cout<<n-ans<<endl;
    return 0;
}