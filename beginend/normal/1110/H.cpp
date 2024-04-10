#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

const int N=2005;
const int M=805;

int l1,l2,n,tot,now,ans[N],fail[M*20],ch[M*20][10],sum[M*20][M],f[N][M*20],pre[N][M*20],dep[M*20],vis[M];
char lef[M],rig[M],str[M];
std::queue<int> que;
bool pd[N][M*20];

int ins(int L)
{
	int x=0;
	for (int i=1;i<=L;i++)
		if (!ch[x][str[i]-'0']) ch[x][str[i]-'0']=++tot,dep[tot]=dep[x]+1,x=tot;
		else x=ch[x][str[i]-'0'];
	return x; 
}

void dfs(int L,int op1,int op2)
{
	int t=0;
	for (int i=1;i<=std::min(L,l1);i++)
		if (str[i]<lef[i]) break;
		else if (str[i]>lef[i]) {t+=1;break;}
	for (int i=1;i<=L;i++)
		if (str[i]<rig[i]) break;
		else if (str[i]>rig[i]) {t+=2;break;}
	int k=ins(L);
	if (op1&&L==l1||op2&&L==l2) sum[k][0]++;
	for (int i=std::max(0,l1-L);i<=l2-L;i++)
		if (vis[L+i]) continue;
		else if (L+i>l1&&L+i<l2) sum[k][i]++;
		else if (L+i==l1)
		{
			if (!op1&&(t&1)&&(l2>l1||l2==l1&&!op2&&!(t&2))) sum[k][i]++;
		}
		else if (!op2&&!(t&2)) sum[k][i]++;
	if (str[1]=='0') for (int i=0;i<=l2;i++) sum[k][i]=0;
	if (L==l2||!op1&&!op2) return;
	for (int i=0;i<=l2-L;i++) vis[L+i]+=sum[k][i];
	for (int i=0;i<=9;i++) str[L+1]=i+'0',dfs(L+1,op1&(L<l1&&i==lef[L+1]-'0'),op2&(i==rig[L+1]-'0'));
	for (int i=0;i<=l2-L;i++) vis[L+i]-=sum[k][i];
}

void get_fail()
{
	for (int i=0;i<=9;i++)
		if (ch[0][i]) que.push(ch[0][i]);
	while (!que.empty())
	{
		int x=que.front();que.pop();
		for (int i=0;i<=l2;i++) sum[x][i]+=sum[fail[x]][i];
		for (int i=0;i<=9;i++)
			if (ch[x][i]) que.push(ch[x][i]),fail[ch[x][i]]=ch[fail[x]][i];
			else ch[x][i]=ch[fail[x]][i];
	}
	for (int i=0;i<=tot;i++)
		for (int j=1;j<=l2;j++)
			sum[i][j]+=sum[i][j-1];
}

void dp()
{
	for (int i=0;i<=n;i++)
		for (int j=0;j<=tot;j++)
			f[i][j]=-1;
	f[0][0]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<=tot;j++)
		{
			if (f[i][j]<0) continue;
			for (int k=0;k<=9;k++)
			{
				int to=ch[j][k];
				int w=f[i][j]+sum[to][std::min(l2,n-i-1)];
				if (w>f[i+1][to])
				{
					f[i+1][to]=w;
					pre[i+1][ch[j][k]]=j*10+k;
				}
			}
		}
}

void work(int x,int y)
{
	if (x==n)
	{
		for (int i=1;i<=n;i++) printf("%d",ans[i]);
		exit(0);
	}
	for (int i=0;i<=9;i++)
		if (pd[x+1][ch[y][i]]&&f[x][y]+sum[ch[y][i]][std::min(l2,n-x-1)]==f[x+1][ch[y][i]]) ans[x+1]=i,work(x+1,ch[y][i]);
}

void pri()
{
	int mx=0;
	for (int i=0;i<=tot;i++) mx=std::max(mx,f[n][i]);
	printf("%d\n",mx);
	for (int i=0;i<=tot;i++) if (f[n][i]==mx) pd[n][i]=1;
	for (int i=n-1;i>=0;i--)
		for (int j=0;j<=tot;j++)
		{
			if (f[i][j]<0) continue;
			for (int k=0;k<=9;k++)
			{
				int to=ch[j][k];
				int w=f[i][j]+sum[to][std::min(l2,n-i-1)];
				if (w==f[i+1][to]&&pd[i+1][to]) pd[i][j]=1;
			}
		}
	work(0,0);
}

int main()
{
	scanf("%s%s%d",lef+1,rig+1,&n);
	l1=strlen(lef+1);
	l2=strlen(rig+1);
	for (int i=0;i<=9;i++) str[1]=i+'0',dfs(1,i==lef[1]-'0',i==rig[1]-'0');
	get_fail();
	dp();
	pri();
	return 0;
}