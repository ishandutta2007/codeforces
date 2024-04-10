#include<bits/stdc++.h>
using namespace std;
int t,n;
const int N=200005;
int a[N],f[N];
char s[N];
vector<int> v[2];
inline bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		scanf("%s",s+1);
		v[0].clear();
		v[1].clear();
		for (int i=1;i<=n;++i)
			v[s[i]-'0'].push_back(i);
		int cnt=0;
		for (int i=0;i<=1;++i)
		{
			if (v[i].size())
				sort(v[i].begin(),v[i].end(),cmp);
			for (int x:v[i])
				f[x]=++cnt;
		}
		for (int i=1;i<=n;++i)
			printf("%d ",f[i]);
		puts("");
	}
	return 0;
}