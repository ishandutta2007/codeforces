#include<bits/stdc++.h>

const int N=200005;

int n,a[N],s[N],p[N],id[N],b[N],m;

bool cmp(int x,int y)
{
	return p[x]>p[y]||p[x]==p[y]&&s[x]>s[y];
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		scanf("%d",&m);
		for (int i=1;i<=m;i++) scanf("%d%d",&p[i],&s[i]),id[i]=i;
		std::sort(id+1,id+m+1,cmp);
		int top=0;
		for (int i=1;i<=m;i++) if (!top||s[id[i]]>s[b[top]]) b[++top]=id[i];
		bool flag=0;
		for (int i=1;i<=n;i++) if (a[i]>p[b[1]]) {puts("-1");flag=1;break;}
		if (flag) continue;
		int now=1,ans=0;
		while (now<=n)
		{
			ans++;int pts=top,cnt=0;
			while (now<=n)
			{
				int l=1,r=top;
				while (l<=r)
				{
					int mid=(l+r)/2;
					if (p[b[mid]]>=a[now]) l=mid+1;
					else r=mid-1;
				}
				pts=std::min(pts,l-1);
				if (cnt<s[b[pts]]) now++,cnt++;
				else break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}