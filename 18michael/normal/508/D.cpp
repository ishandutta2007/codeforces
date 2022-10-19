#include<bits/stdc++.h>
#define Mx 3844
using namespace std;
int n,s=-1,t=0;
char c[4];
int now[Mx],in[Mx],out[Mx],st[200002];
vector<int> vec[Mx];
inline int f(char x)
{
	return x<='9'? x-'0':10+(x<='Z'? x-'A':26+x-'a');
}
inline int num(char x,char y)
{
	return f(x)*62+f(y);
}
inline char get(int x)
{
	return x<10? x+'0':((x-=10)<26? x+'A':x-26+'a');
}
inline void add_edge(int x,int y)
{
	vec[x].push_back(y),++out[x],++in[y];
}
inline void dfs(int x)
{
	for(int &i=now[x];(++i)<vec[x].size();)dfs(vec[x][i]);
	st[++t]=x;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%s",c),add_edge(num(c[0],c[1]),num(c[1],c[2]));
	for(int i=0;i<Mx;now[i]=-1,++i)
	{
		if(out[i]>in[i]+1)return 0&puts("NO");
		if(out[i]==in[i]+1)
		{
			if(~s)return 0&puts("NO");
			s=i;
		}
	}
	if(!(~s))for(int i=0;i<Mx;++i)if(in[i])
	{
		s=i;
		break;
	}
	dfs(s);
	if(t<n+1)return 0&puts("NO");
	printf("YES\n%c",get(st[t]/62));
	for(int i=t;i;--i)printf("%c",get(st[i]%62));
	return 0;
}