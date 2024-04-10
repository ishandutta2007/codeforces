#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
const int MAXN=1005,MOD=998244353;

int n,a[MAXN],b[MAXN],x[MAXN],y[MAXN];
map<pii,int> p;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    if(n==1)return 0*printf("%d %d\n",x[1]+a[1],y[1]+b[1]);
    for(int j=1;j<=n;j++)
    	p[mp(x[1]+a[j],y[1]+b[j])]=1;
    for(int i=2;i<n;i++)
    	for(int j=1;j<=n;j++)
    	{
    		pii k=mp(x[i]+a[j],y[i]+b[j]);
    		if(p.count(k) && p[k]==i-1)
    			p[k]=i;
    	}
	for(int j=1;j<=n;j++)
	{
		pii k=mp(x[n]+a[j],y[n]+b[j]);
		if(p.count(k) && p[k]==n-1)
			return 0*printf("%d %d\n",k.first,k.second);
	}
	return 0;
}