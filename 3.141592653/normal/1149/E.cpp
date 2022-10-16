#include<bits/stdc++.h>
int n,m;
std::vector<int>v[1111111],w[1111111];
int xors[1111111];
int mex[1111111],a[1111111],vin[1111111];
inline int qmex(const std::set<int>&S)
{for(register int i=0;;i++)if(S.find(i)==S.end())return i;}
int main()
{
	scanf("%d%d",&n,&m);
	register int i;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),v[x].push_back(y),vin[y]++;
	}
	std::queue<int>q;
	std::vector<int>ps;
	for(i=1;i<=n;i++)if(!vin[i])q.push(i);
	for(;!q.empty();q.pop())
	{
		int p=q.front();ps.push_back(p);
		for(int t:v[p])(--vin[t])?(void)0:q.push(t);
	}
	for(i=n-1;~i;i--)
	{
		std::set<int>S;
		int p=ps[i];
		for(int t:v[p])S.insert(mex[t]);
		mex[p]=qmex(S);
		w[mex[p]].push_back(p),xors[mex[p]]^=a[p];
	}
	for(i=n;~i;i--)
		if(xors[i])
		{
			puts("WIN");
			for(int t:w[i])
			{
				if((a[t]^xors[i])<a[t])
				{
					a[t]^=xors[i],xors[i]=0;
					for(int s:v[t])
					{
						int d=mex[s];
						if(xors[d])a[s]^=xors[d],xors[d]=0;
					}
				}
			}
			for(i=1;i<=n;i++)printf("%d ",a[i]);puts("");
			return 0;
		}
	puts("LOSE");
}