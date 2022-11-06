#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,a[N],b[N];
struct st{int a,b,c,d;};
vector<st>ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i&&b[i]==i)continue;
		ans.push_back((st){a[i],i,i,b[i]});
		for(int j=i;j<=n;j++)if(a[j]==i){a[j]=a[i];ans[ans.size()-1].a=j;break;}
		for(int j=i;j<=n;j++)if(b[j]==i){b[j]=b[i];ans[ans.size()-1].d=j;break;}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d %d %d %d\n",ans[i].a,ans[i].b,ans[i].c,ans[i].d);
	return 0;
}