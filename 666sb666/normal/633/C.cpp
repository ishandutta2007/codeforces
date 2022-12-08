#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define GC getchar()
#define PC putchar
inline void read(int&n)
{int x=0,f=1;char ch=GC;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=GC;}while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=GC;n=x*f;}
int outputarray[20];
inline void write(int k)
{int num=0;if(k<0)PC('-'),k=-k;do{outputarray[++num]=k%10,k/=10;}while(k);while(num)PC(outputarray[num--]+'0');puts("");}
const int N=1e4+5,M=1e6+5;
int n,m,trans[M][26],num[M],cnt=1,ans[M],tot;
pair<int,int>f[N];
inline void add(char*s,int k)
{
	int p=1,len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int x;
		if(s[i]>='A'&&s[i]<='Z')x=s[i]-'A';
		else x=s[i]-'a';
		if(!trans[p][x])trans[p][x]=++cnt;
		p=trans[p][x];
	}
	num[p]=k;
}
char s[N],str[N];
string t[M];
void dfs(int n)
{
	ans[++tot]=f[n].second;
	if(f[n].first)dfs(f[n].first);
}
int main()
{
	read(n);
	scanf("%s",s+1);
	read(m);
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
		int len=t[i].size();
		for(int j=0;j<len;j++)str[j]=t[i][j];
		str[len]=0;
		add(str,i);
	}
	for(int i=1;i<=n;i++)
	{
		int p=1,j=i;
		while(j&&trans[p][s[j]-'a'])
		{
			p=trans[p][s[j]-'a'],j--;
			if(num[p]&&(f[j]!=make_pair(0,0)||j==0)){f[i]=make_pair(j,num[p]);break;}
		}
	}
	dfs(n);
	for(int i=tot;i>=1;i--)cout<<t[ans[i]]<<' ';
	return 0;
}