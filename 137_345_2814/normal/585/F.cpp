#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define mod 1000000007
#define N 50050
int ch[N][12],l1,l2,fail[N],ct=1,dp[N][52][2][2][2],is[N],fa[N];
char s[N],l[N],r[N];
void ins(int l,int r)
{
	int st=1;
	for(int i=l;i<=r;i++)
	{
		int vl=s[i]-'0';
		if(!ch[st][vl])ch[st][vl]=++ct,fa[ct]=st;
		st=ch[st][vl];
	}
	is[st]=1;
}
void init()
{
	queue<int> st;
	st.push(1);
	while(!st.empty())
	{
		int x=st.front();st.pop();
		for(int i=0;i<10;i++)
		if(ch[x][i])
		{
			int t=fail[x];
			while(t&&!ch[t][i])t=fail[t];
			if(t==0&&x!=1)t=1;
			fail[ch[x][i]]=ch[t][i];
			st.push(ch[x][i]);
		}
	}
}
int main()
{
	scanf("%s%s%s",s+1,l+1,r+1);
	l1=strlen(s+1);l2=strlen(l+1);
	for(int i=1;i<=l1-l2/2+1;i++)
	ins(i,i+l2/2-1);
	init();
	dp[1][0][1][1][0]=1;
	for(int i=0;i<l2;i++)
	for(int j=1;j<=ct;j++)
	for(int k=0;k<2;k++)
	for(int l1=0;l1<2;l1++)
	for(int s=0;s<2;s++)
	if(dp[j][i][k][l1][s])
	{
		int lb=k?l[i+1]-'0':0,rb=l1?r[i+1]-'0':9;
		for(int t=lb;t<=rb;t++)
		{
			int st=j;
			while(!ch[st][t]&&st)st=fail[st];
			if(!st)st=1;
			st=ch[st][t];
			if(!st)st=1;
			int nk=k&(t==l[i+1]-'0'),nl=l1&(t==r[i+1]-'0'),ns=s|is[st];
			dp[st][i+1][nk][nl][ns]=(dp[st][i+1][nk][nl][ns]+dp[j][i][k][l1][s])%mod;
		}
	}
	int as=0;
	for(int i=1;i<=ct;i++)
	for(int j=0;j<2;j++)
	for(int k=0;k<2;k++)
	as=(as+dp[i][l2][j][k][1])%mod;
	printf("%d\n",as);
}