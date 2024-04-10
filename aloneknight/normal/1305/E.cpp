#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=5005;
int n,m,a[N];vector<int>V;
inline int calc(int n,int m)
{
	int t=m&1?m/2:m/2-1;
	return max(0,t-(m-1-n));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=3;i<=n+1;i++)
	{
		int t=0;
		for(int j=1,s=i-2;j<=n&&s>0;j++,s-=2)t+=s;
		a[i]=t;
	}
	if(m>a[n]){puts("-1");return 0;}
	if(n==1){puts("1");return 0;}
	for(int i=1;i<=n;i++)if(a[i]<=m&&m<a[i+1])
	{
		for(int j=1;j<=i;j++)V.pb(j);
		if(i<n)
		{
			int s=m-a[i];
			for(int j=i+1;j;j++)if(calc(i,j)==s){V.pb(j);break;}
			for(int j=i+2,t=1e9;j<=n;j++)V.pb(t),t-=50005;
		}
		sort(V.begin(),V.end());
		for(int j=0;j<n;j++)printf("%d ",V[j]);
		return 0;
	}
	return 0;
}