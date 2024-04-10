#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define mp std::make_pair
#define pb push_back

typedef std::pair<int,int> pi;

const int N=2005;

int n,m,ans[30][5];
std::vector<pi> vec[30];
char a[N][N];

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%s",a[i]+1);
		int mx=-1;
		for (int i=0;i<26;i++) vec[i].clear();
		bool flag=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (a[i][j]!='.')
				{
					if (vec[a[i][j]-'a'].size()==std::max(n,m)) {flag=1;break;}
					mx=std::max(mx,a[i][j]-'a');vec[a[i][j]-'a'].pb(mp(i,j));
				}
		if (mx==-1) {printf("YES\n%d\n",0);continue;}
		for (int k=mx;k>=0;k--)
		{
			if (!vec[k].size()) {ans[k][0]=ans[mx][0];ans[k][2]=ans[mx][2];ans[k][1]=ans[mx][1];ans[k][3]=ans[mx][3];continue;}
			int x=vec[k][0].first,y=vec[k][0].second;
			for (int i=1;i<vec[k].size();i++)
			{
				if (vec[k][i].first!=x) x=0;
				if (vec[k][i].second!=y) y=0;
			}
			if (!x&&!y) {flag=1;break;}
			else if (x&&y) ans[k][0]=ans[k][2]=x,ans[k][1]=ans[k][3]=y;
			else if (x)
			{
				int lef=m,rig=1;
				for (int i=0;i<vec[k].size();i++)
				{
					int t=vec[k][i].second;
					lef=std::min(lef,t);rig=std::max(rig,t);
				}
				for (int i=lef;i<=rig;i++) if (a[x][i]!='.'&&a[x][i]-'a'<k||a[x][i]=='.') {flag=1;break;}
				ans[k][0]=ans[k][2]=x,ans[k][1]=lef;ans[k][3]=rig;
			}
			else
			{
				int lef=n,rig=1;
				for (int i=0;i<vec[k].size();i++)
				{
					int t=vec[k][i].first;
					lef=std::min(lef,t);rig=std::max(rig,t);
				}
				for (int i=lef;i<=rig;i++) if (a[i][y]!='.'&&a[i][y]-'a'<k||a[i][y]=='.') {flag=1;break;}
				ans[k][0]=lef;ans[k][2]=rig,ans[k][1]=ans[k][3]=y;
			}
		}
		if (flag) puts("NO");
		else
		{
			puts("YES");
			printf("%d\n",mx+1);
			for (int i=0;i<=mx;i++) printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
		}
	}
	return 0;
}