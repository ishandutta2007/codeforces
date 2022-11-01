#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define pb push_back

const int N=100005;

int n,m;
std::vector<int> vec[N];

bool check(int w)
{
	for (int i=1;i<=n;i++)
	{
		int j=i+w;
		j-=j>n?n:0;
		if (vec[i].size()!=vec[j].size()) return 0;
		for (int k=0;k<vec[i].size();k++) if (vec[i][k]!=vec[j][k]) return 0;
 	}
 	return 1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		int len=y-x;
		len+=len<0?n:0;
		vec[x].pb(len);
		vec[y].pb(n-len);
	}
	for (int i=1;i<=n;i++) std::sort(vec[i].begin(),vec[i].end());
	for (int i=1;i<n;i++) if (n%i==0&&(check(i)||check(n-i))) {puts("Yes");return 0;}
	puts("No");
	return 0;
}