#include<bits/stdc++.h>
using namespace std;
int p;
int Pow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=1ll*a*ret%p;
		a=1ll*a*a%p;
		b>>=1;
	}
	return ret;
}
map<int,int> M1,M2;
queue<int> Q;
int ans[303];
int main()
{
	int u,v;
	scanf("%d%d%d",&u,&v,&p);
	int T=100000;
	Q.push(u);
	M1[u]=0;
	for(int t=1;t<=T&&(!Q.empty());t++)
	{
		int now=Q.front();
		Q.pop();
		int tmp;
		tmp=(now+1)%p;
		if(M1.count(tmp)==0)
		{
			M1[tmp]=1;
			Q.push(tmp);
		}
		tmp=(now+p-1)%p;
		if(M1.count(tmp)==0)
		{
			M1[tmp]=2;
			Q.push(tmp);
		}
		tmp=Pow(now,p-2);
		if(M1.count(tmp)==0)
		{
			M1[tmp]=3;
			Q.push(tmp);
		}
	}
	while(!Q.empty())
		Q.pop();
	Q.push(v);
	M2[v]=0;
	while(!Q.empty())
	{
		int now=Q.front();
		Q.pop();
		if(M1.count(now))
		{
			int tmp=now;
			while(tmp!=u)
			{
				ans[0]++;
				int res=M1[tmp];
				ans[ans[0]]=res;
				if(res==1)
					tmp=(tmp+p-1)%p;
				else if(res==2)
					tmp=(tmp+1)%p;
				else
					tmp=Pow(tmp,p-2);
			}
			reverse(ans+1,ans+ans[0]+1);
			tmp=now;
			while(tmp!=v)
			{
				ans[0]++;
				int res=M2[tmp];
				ans[ans[0]]=res;
				if(res==1)
					tmp=(tmp+1)%p;
				else if(res==2)
					tmp=(tmp+p-1)%p;
				else
					tmp=Pow(tmp,p-2);
			}
			printf("%d\n",ans[0]);
			for(int i=1;i<=ans[0];i++)
				printf("%d ",ans[i]);
			printf("\n");
			return 0;
		}
		
		int tmp;
		tmp=(now+1)%p;
		if(M2.count(tmp)==0)
		{
			M2[tmp]=2;
			Q.push(tmp);
		}
		tmp=(now+p-1)%p;
		if(M2.count(tmp)==0)
		{
			M2[tmp]=1;
			Q.push(tmp);
		}
		tmp=Pow(now,p-2);
		if(M2.count(tmp)==0)
		{
			M2[tmp]=3;
			Q.push(tmp);
		}
	}
	return 0;
}