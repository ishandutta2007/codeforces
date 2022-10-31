#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int M=998244353,N=1000005;
int sta[2][N],l,r,top[2],last,s[2][N],mn[2][N],mx[2][N],i,e,n;
char c[N],p[N];
void Add(int i,int x)
{
	sta[i][++top[i]]=x;
	s[i][top[i]]=s[i][top[i]-1]+x;
	mn[i][top[i]]=min(mn[i][top[i]-1],s[i][top[i]]);
	mx[i][top[i]]=max(mx[i][top[i]-1],s[i][top[i]]);
}
void Dec(int i)
{
	--top[i];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	scanf("%s",c);
	for(i=0;c[i];++i)
	{
		if(c[i]=='L')
			if(e)
			{
				if(p[e]=='(')
					Add(1,-1);
				if(p[e]==')')
					Add(1,1);
				if(p[e]=='('||p[e]==')')
					Dec(0);
				--e;
			}
		if(c[i]=='R')
		{
			++e;
			if(p[e]=='(')
				Add(0,1);
			if(p[e]==')')
				Add(0,-1);
			if(p[e]=='('||p[e]==')')
				Dec(1);
		}
		if(c[i]!='L'&&c[i]!='R')
		{
			if(p[e]=='('||p[e]==')')
				Dec(0);
			if(c[i]==')')
				Add(0,-1);
			if(c[i]=='(')
				Add(0,1);
			p[e]=c[i];
		}
		//cout<<mn[0][top[0]]<<' '<<mn[1][top[1]]<<endl;
		if(s[0][top[0]]==s[1][top[1]]&&mn[0][top[0]]>=0&&mn[1][top[1]]>=0)
			printf("%d ",max(mx[0][top[0]],mx[1][top[1]]));
		else
			printf("-1 ");
	}
}