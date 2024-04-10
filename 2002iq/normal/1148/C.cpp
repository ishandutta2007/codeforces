#include <iostream>
#include <vector>
using namespace std;
int p[300005],inv[300005],a[300005];
vector<pair<int,int> > ans;
void go(int i,int j)
{
	ans.push_back({i,j});
	swap(inv[p[i]],inv[p[j]]);
	swap(p[i],p[j]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		inv[p[i]]=i;
		a[i]=1;
		if (i>n/2)
		a[i]=n;
	}
	for (int i=2;i<n;i++)
	{
		int pos=inv[i];
		if (a[i]!=a[pos])
		go(pos,a[i]);
		pos=inv[i];
		go(pos,n-a[i]+1);
		pos=inv[i];
		go(pos,i);
	}
	if (p[1]!=1)
	go(1,n);
	printf("%d\n",ans.size());
	for (auto p:ans)
	printf("%d %d\n",p.first,p.second);
}