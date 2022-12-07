#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1000005;
int T;
int bin[N];
int a[N];
int solve (vector<int> a)
{
	int n=a.size();
	if (n==0) return 0;
	int t=bin[n-1];
	int ans=(a[0]>>t)<<t;
	for (int u=0;u<n;u++) a[u]^=ans;
	int tot=0;
	for (int u=0;u<n;u++)
	{
		if (a[u]&(1<<t)) tot++;
		else 			 tot--;
	}
//	printf("%d %d %d\n",tot,ans,(1<<t));
	if (tot>0)
	{
		for (int u=0;u<n;u++) a[u]^=(1<<t);
		ans^=(1<<t);tot=-tot;
	}
	if (tot==-n) return ans;
	
	vector<int> b;
	b.clear();
	for (int u=0;u<n;u++) if (a[u]&(1<<t)) b.push_back(a[u]^(1<<t));
	return ans^solve(b);
}
int main()
{
	bin[0]=bin[1]=0;for (int u=2;u<(1<<17);u++) bin[u]=bin[u>>1]+1;
	scanf("%d",&T);
	while (T--)
	{
		int l,r,n;
		scanf("%d%d",&l,&r);
		vector<int> vec;
		vec.clear();
		n=(r-l+1);
		for (int u=0;u<n;u++)
		{
			int x;
			scanf("%d",&x);
			vec.push_back(x);
		}
		printf("%d\n",solve(vec));
	}
	return 0;
}