#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
const int N=200005;
char ss[N];
int len;
set<int> a,b;
vector<int> ans[N];
int tot=0;
int main()
{
	scanf("%s",ss+1);len=strlen(ss+1);
	for (int u=1;u<=len;u++)
	{
		if (ss[u]=='0') a.insert(u);
		else b.insert(u);
	}
	while (true)
	{
		if (b.empty()) break;
		if (a.empty()) {printf("-1");return 0;}
		if ((*a.begin())>(*b.begin())) {printf("-1");return 0;}	
		int now=0;
		tot++;
		int mn=0;
		while (true)
		{
			if (now==0)
			{
				if (a.lower_bound(mn)==a.end()) {printf("-1");return 0;}
				mn=(*a.lower_bound(mn));
				a.erase(mn);
			}
			else
			{
				if (b.lower_bound(mn)==b.end()) break;
				mn=(*b.lower_bound(mn));
				b.erase(mn);
			}
			now^=1;
			//printf("%d ",mn);
			ans[tot].push_back(mn);
		}
		//printf("\n");
	}
	set<int>::iterator it;
	for (it=a.begin();it!=a.end();it++)
		ans[++tot].push_back(*it);
	printf("%d\n",tot);
	for (int u=1;u<=tot;u++)
	{
		int lalal=ans[u].size();
		printf("%d ",lalal);
		for (int i=0;i<lalal;i++)
			printf("%d ",ans[u][i]);
		printf("\n");
	}
	return 0;
}