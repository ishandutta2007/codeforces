//CF1074C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 333333;
const int inf = 1e9;
int n,x[N],y[N],ans,l=inf,r=-inf,d=inf,u=-inf;
int main()
{
	int i,t;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",x+i,y+i);
		l=min(l,x[i]);
		r=max(r,x[i]);
		d=min(d,y[i]);
		u=max(u,y[i]);
	}
	ans=0;
	for(i=1;i<=n;i=i+1)
		ans=max(ans,max(x[i]-l,r-x[i])+max(y[i]-d,u-y[i]));
	cout<<ans*2;
	ans=(r-l+u-d)*2;
	for(i=4;i<=n;i=i+1)
		cout<<' '<<ans;
	return 0;
}