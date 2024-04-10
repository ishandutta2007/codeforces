#include<bits/stdc++.h>
using namespace std;
int n,l,a;
pair<int,int>p[100005];
int main()
{
	scanf("%d%d%d",&n,&l,&a);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+n+1);
	int lst=0,ans=0;
	for(int i=1;i<=n;i++)ans+=(p[i].first-lst)/a,lst=p[i].first+p[i].second;
	ans+=(l-lst)/a;
	printf("%d\n",ans);
	return 0;
}