#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,m,a[N],b[N],ans[N],t[N],tot;

void ins(int x)
{
	t[x]^=1;
	tot+=t[x]?1:-1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		ins(a[i]);ins(b[i]);
		if (!tot) cnt++;
	}
	if (cnt<m) {puts("NO");return 0;}
	int pos=0,now=0;
	for (int i=1;i<=n;i++)
	{
		ins(a[i]);ins(b[i]);
		if (!tot)
		{
			now=std::min(m,now+1);
			for (int j=pos+1;j<=i;j++) ans[a[j]]=now;
			pos=i;
		}
	}
	puts("YES");
	for (int i=1;i<=n;i++) putchar(ans[i]+'a'-1);
	return 0;
}