#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1550
int n,m,ct,ty[N*4],cl[N*4],s1[N*4],is[N*4],sz[N*4],id[N*4],ty2[N*4],as[N],c1;
char s[N][N];
vector<int> sn[N*4],tp[N],sn2[N*4];
void dfs(int x)
{
	if(x<=m)return;
	cl[x]=0;
	for(int i=0;i<sn[x].size();i++)dfs(sn[x][i]),cl[x]|=cl[sn[x][i]];
}
void dfs2(int x)
{
	if(x<=m){sz[x]=1;return;}sz[x]=0;
	for(int i=0;i<sn[x].size();i++)
	{
		while(sn[x][i]>m&&sn[sn[x][i]].size()==1)is[sn[x][i]]=0,sn[x][i]=sn[sn[x][i]][0];
		dfs2(sn[x][i]),sz[x]+=sz[sn[x][i]];
	}
}
void failed(){printf("NO\n");exit(0);}
void solvel(int x,vector<int> &v1,vector<int> &v2)
{
	if(!ty[x])
	{
		int ls=sn[x][0],rs=sn[x].back();
		if((cl[rs]==2&&cl[ls]!=2)||(cl[rs]==3&&cl[ls]==1))reverse(sn[x].begin(),sn[x].end());
		vector<int> s1;
		int fg=1;
		for(int i=0;i<sn[x].size();i++)
		if(cl[sn[x][i]]==2)
		{
			if(!fg)failed();
			v1.push_back(sn[x][i]);
		}
		else if(cl[sn[x][i]]==3)
		{
			if(!fg)failed();fg=0;
			solvel(sn[x][i],v1,v2);
		}
		else
		{
			if(fg)fg=0;
			v2.push_back(sn[x][i]);
		}
	}
	else
	{
		int f1=++ct,f2=++ct,c1=0;ty[f1]=ty[f2]=1;
		for(int i=0;i<sn[x].size();i++)
		if(cl[sn[x][i]]==2)sn[f1].push_back(sn[x][i]);
		else if(cl[sn[x][i]]==1)sn[f2].push_back(sn[x][i]);
		v1.push_back(f1);
		for(int i=0;i<sn[x].size();i++)if(cl[sn[x][i]]==3)
		{
			c1++;if(c1>1)failed();
			solvel(sn[x][i],v1,v2);
		}
		v2.push_back(f2);
	}
	sn[x].clear();
}
void solver(int x,vector<int> &v1,vector<int> &v2)
{
	vector<int> s1,s2;
	solvel(x,s1,s2);
	reverse(s1.begin(),s1.end());reverse(s2.begin(),s2.end());
	for(int i=0;i<s1.size();i++)v1.push_back(s1[i]);
	for(int i=0;i<s2.size();i++)v2.push_back(s2[i]);
}
void solve(int x)
{
	if(cl[x]!=3)return;
	int c1=0,c2=0,ls=0;
	for(int i=0;i<sn[x].size();i++)if(cl[sn[x][i]]==3)c2++;else if(cl[sn[x][i]]==2)c1++;
	if(c2>2)failed();
	if(!c1&&c2==1)
	{
		for(int i=0;i<sn[x].size();i++)if(cl[sn[x][i]]==3)solve(sn[x][i]);
		return;
	}
	if(!ty[x])
	{
		int fg=0;
		vector<int> s1,s3,s2;
		for(int i=0;i<sn[x].size();i++)
		if(cl[sn[x][i]]==1)
		{
			if(fg==1)fg=2;
			if(fg==0)s1.push_back(sn[x][i]);else s3.push_back(sn[x][i]);
		}
		else if(cl[sn[x][i]]==2)
		{
			if(fg==0)fg=1;if(fg==2)failed();
			s2.push_back(sn[x][i]);
		}
		else
		{
			if(fg==0)fg=1,solver(sn[x][i],s2,s1);
			else if(fg==1)fg=2,solvel(sn[x][i],s2,s3);
			else failed();
		}
		for(int i=0;i<s2.size();i++)s1.push_back(s2[i]);for(int i=0;i<s3.size();i++)s1.push_back(s3[i]);
		sn[x]=s1;return;
	}
	int st=++ct,sb=++ct,sw=++ct;ty[st]=0;ty[sw]=ty[sb]=1;
	vector<int> s1,s2,s3,s4;
	for(int i=0;i<sn[x].size();i++)if(cl[sn[x][i]]==1)s2.push_back(sn[x][i]);else if(cl[sn[x][i]]==2)sn[sb].push_back(sn[x][i]);
	for(int i=0;i<sn[x].size();i++)if(cl[sn[x][i]]==3&&!ls)solver(sn[x][i],sn[st],s3),ls=sn[x][i];
	sn[st].push_back(sb);
	for(int i=0;i<sn[x].size();i++)if(cl[sn[x][i]]==3&&ls!=sn[x][i])solvel(sn[x][i],sn[st],s4);
	for(int i=0;i<sn[st].size();i++)s3.push_back(sn[st][i]);for(int i=0;i<s4.size();i++)s3.push_back(s4[i]);
	sn[st]=s3;
	s2.push_back(st);sn[x]=s2;
}
void dfs3(int x)
{
	if(x<=m){as[++c1]=x;return;}
	for(int i=0;i<sn[x].size();i++)dfs3(sn[x][i]);
}
int main()
{
	scanf("%d",&n);m=n;
	for(int i=1;i<=n;i++){scanf("%s",s[i]+1);for(int j=1;j<=m;j++)if(s[i][j]=='1')tp[i].push_back(j);}
	ty[m+1]=1;for(int i=1;i<=m;i++)sn[m+1].push_back(i);
	ct=m+1;
	for(int i=1;i<=n;i++)
	{
		int c1=0;
		for(int j=1;j<=m;j++)cl[j]=1;
		for(int j=0;j<tp[i].size();j++)cl[tp[i][j]]=2;
		dfs(m+1);solve(m+1);
		for(int j=1;j<=ct;j++)is[j]=1,sz[j]=0;
		dfs2(m+1);
		for(int j=1;j<=ct;j++)if(!sz[j])is[j]=0;else if(is[j])
		{
			ty2[++c1]=ty[j];id[j]=c1;
			for(int l=0;l<sn[j].size();l++)if(sz[sn[j][l]]>0)sn2[c1].push_back(sn[j][l]);
		}
		for(int j=1;j<=ct;j++)sn[j].clear();
		for(int j=1;j<=c1;j++)ty[j]=ty2[j],sn[j]=sn2[j],sn2[j].clear();
		for(int j=1;j<=c1;j++)for(int l=0;l<sn[j].size();l++)sn[j][l]=id[sn[j][l]];
		ct=c1;
	}
	dfs3(m+1);
	printf("YES\n");
	for(int i=1;i<=n;i++,printf("\n"))for(int j=1;j<=m;j++)printf("%c",s[i][as[j]]);
}