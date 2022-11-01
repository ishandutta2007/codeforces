#include<bits/stdc++.h>
#define pb push_back

const int N=300005;

int n,m,mn[N],mx[N],a[N],w[N],c[N];
std::vector<int> vec[N];

void ins(int x,int y)
{
	while (x<=n) c[x]+=y,x+=x&(-x);
}

int find(int x)
{
	int ans=0;
	while (x) ans+=c[x],x-=x&(-x);
	return ans;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) vec[i].clear(),c[i]=0,mn[i]=n+1,mx[i]=0;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),w[i]=a[i];
		std::sort(w+1,w+n+1);
		m=std::unique(w+1,w+n+1)-w-1;
		for (int i=1;i<=n;i++)
		{
			a[i]=std::lower_bound(w+1,w+m+1,a[i])-w;
			vec[a[i]].pb(i);
			mx[a[i]]=std::max(mx[a[i]],i);
			mn[a[i]]=std::min(mn[a[i]],i);
		}
		int pos=m+1;
		for (int i=1;i<=m;i++)
		{
			if (find(n)-find(mn[i]-1)) {pos=i;break;}
			for (int j=0;j<vec[i].size();j++) ins(vec[i][j],1);
		}
		int ans=m-pos+1;
		for (int i=1;i<=m;i++)
		{
			for (int j=0;j<vec[i].size();j++) ins(vec[i][j],-1);
			while (pos<=m&&!(find(n)-find(mn[pos]-1)))
			{
				for (int j=0;j<vec[pos].size();j++) ins(vec[pos][j],1);
				pos++;
			}
			ans=std::min(ans,i+m-pos+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}