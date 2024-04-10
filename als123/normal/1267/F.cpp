#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N=200005;
int n,m,ka,kb;
int a[N],b[N];
int du[N];
set<int> s;
int main()
{
	scanf("%d%d%d%d",&n,&m,&ka,&kb);
	if (kb>n-1) {printf("NO\n");return 0;}
	if (ka>m-1) {printf("NO\n");return 0;}
	for (int u=1;u<=ka;u++) 
	{
		scanf("%d",&a[u]);
		du[a[u]]++;
	}
	for (int u=1;u<=kb;u++) 
	{
		scanf("%d",&b[u]);
		du[b[u]]++;
	}
	while (ka<m-1) {a[++ka]=1;du[1]++;}
	while (kb<n-1) {b[++kb]=n+1;du[n+1]++;}
	for (int u=1;u<=n+m;u++) if (du[u]==0) s.insert(u);
	printf("Yes\n");
	int now=1,now1=1;
	for (int u=1;u<=n+m-2;u++)
	{
		int x=(*s.begin());s.erase(x);
		if (x<=n) 
		{
			printf("%d %d\n",x,b[now1]);
			du[b[now1]]--;
			if (du[b[now1]]==0) s.insert(b[now1]);
			now1++;
		}
		else
		{
			printf("%d %d\n",x,a[now]);
			du[a[now]]--;
			if (du[a[now]]==0) s.insert(a[now]);
			now++;
		}
	}
	int x=*s.begin();s.erase(x);
	int y=*s.begin();
	printf("%d %d\n",x,y);
	return 0;
}