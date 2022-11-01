#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define mp std::make_pair
#define pb push_back

typedef std::pair<int,int> pi;

const int N=100005;

int n,m,a[N],col[N];
bool ans[N],pd[N];
pi b[N];
std::vector<int> vec[N];
char str[N];

void ask()
{
	if (!m) return; 
	printf("Q %d ",m);
	for (int i=1;i<=m;i++) printf("%d %d ",b[i].first,b[i].second);
	puts("");
	fflush(stdout);
	scanf("%s",str+1);
	for (int i=1;i<=m;i++) ans[i]=str[i]-'0';
}

int get(int x,int y)
{
	if (x>y) std::swap(x,y);
	if (x>0) return 0;
	else if (y==2) return 1;
	else return 2;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) a[i]=i,vec[i].clear();
		m=0;
		for (int i=1;i<n;i+=2) b[++m]=mp(i,i+1);
		ask();
		for (int i=1,j=1;i<n;i+=2,j++) pd[i]=ans[j];
		m=0;
		for (int i=2;i<n;i+=2) b[++m]=mp(i,i+1);
		ask();
		for (int i=2,j=1;i<n;i+=2,j++) pd[i]=ans[j];
		int tmp=0;
		vec[++tmp].pb(a[1]);
		for (int i=2;i<=n;i++)
			if (pd[i-1]) vec[tmp].pb(a[i]);
			else vec[++tmp].pb(a[i]);
		n=tmp;
		
		m=0;
		for (int i=1;i+2<=n;i+=4) b[++m]=mp(vec[i][0],vec[i+2][0]);
		ask();
		for (int i=3,j=1;i<=n;i+=4,j++) pd[i]=ans[j];
		m=0;
		for (int i=3;i+2<=n;i+=4) b[++m]=mp(vec[i][0],vec[i+2][0]);
		ask();
		for (int i=5,j=1;i<=n;i+=4,j++) pd[i]=ans[j];
		
		m=0;
		for (int i=2;i+2<=n;i+=4) b[++m]=mp(vec[i][0],vec[i+2][0]);
		ask();
		for (int i=4,j=1;i<=n;i+=4,j++) pd[i]=ans[j];
		m=0;
		for (int i=4;i+2<=n;i+=4) b[++m]=mp(vec[i][0],vec[i+2][0]);
		ask();
		for (int i=6,j=1;i<=n;i+=4,j++) pd[i]=ans[j];
		
		col[1]=0;col[2]=1;
		for (int i=3;i<=n;i++) col[i]=(pd[i]?col[i-2]:get(col[i-2],col[i-1]));
		int k1=0,k2=0,k3=0;
		for (int i=1;i<=n;i++)
			if (!col[i]) k1+=vec[i].size();
			else if (col[i]==1) k2+=vec[i].size();
			else k3+=vec[i].size();
		printf("A %d %d %d\n",k1,k2,k3);
		for (int i=1;i<=n;i++) if (!col[i])
			for (int j=0;j<vec[i].size();j++) printf("%d ",vec[i][j]);
		puts("");
		for (int i=1;i<=n;i++) if (col[i]==1)
			for (int j=0;j<vec[i].size();j++) printf("%d ",vec[i][j]);
		puts("");
		for (int i=1;i<=n;i++) if (col[i]==2)
			for (int j=0;j<vec[i].size();j++) printf("%d ",vec[i][j]);
		puts("");
		fflush(stdout);
	}
	return 0;
}