#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,p;
char s[N],c[10];
inline int ask(int p)
{
	if (s[p]=='a')
	{
		if (s[p+1]=='b'&&s[p+2]=='c')
			return 1;
		else
			return 0;
	}
	if (s[p]=='b')
	{
		if (p>=2&&s[p-1]=='a'&&s[p+1]=='c')
			return 1;
		else
			return 0;
	}
	if (s[p]=='c')
	{
		if (p>=3&&s[p-2]=='a'&&s[p-1]=='b')
			return 1;
		else
			return 0;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int ans=0;
	for (int i=1;i<=n-2;++i)
		if (s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
			++ans;
	for (int i=1;i<=m;++i)
	{
		scanf("%d%s",&p,c);
		ans-=ask(p);
		s[p]=c[0];
		ans+=ask(p);
		printf("%d\n",ans);
	}
	return 0;
}