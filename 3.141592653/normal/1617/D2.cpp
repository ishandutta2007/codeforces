#include<bits/stdc++.h>
int query(int x,int y,int z)
{
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}
void reportImpostors(const std::vector<int>Indices)
{
	printf("! %d ",Indices.size());
	for(int t:Indices)printf("%d ",t);
	puts("");
	fflush(stdout);
}
int stas[1<<20];
int key[1<<20];
void findImpostors(int n)
{
	for(int i=1;i<=n;i++)key[i]=stas[i]=0;
	int p0=-1,p1=-1,z0=-1,z1=-1;
	for(int i=1;i<=n;i+=3)
	{
		stas[i]=query(i,i+1,i+2);
		if(stas[i])p1=i;
		else p0=i;
	}
	// solve(p0,p1)
	if(query(p0+1,p0+2,p1))
	{
		z0=p0,z1=p1;
		key[z0]=0,key[z1]=1;
		key[p0+1]=query(z0,z1,p0+1);
		key[p1+1]=query(z0,z1,p1+1);
		key[p1+2]=query(z0,z1,p1+2);
		key[p0+2]=!key[p0+1];
		goto NXT;
	}
	if(query(p0+2,p1,p1+1))
	{
		z0=p0+1,z1=p1+1;
		key[z0]=0,key[z1]=1;
		key[p0]=query(z0,z1,p0);
		key[p1]=query(z0,z1,p1);
		key[p1+2]=query(z0,z1,p1+2);
		key[p0+2]=!key[p1];
	}
	else
	{
		z0=p0+2,z1=p1+2;
		key[z0]=0,key[z1]=1;
		key[p0]=query(z0,z1,p0);
		key[p0+1]=query(z0,z1,p0+1);
		key[p1]=query(z0,z1,p1);
		key[p1+1]=!key[p1];
	}
	NXT:
	for(int i=1;i<=n;i+=3)
		if(i!=p0&&i!=p1)
		{
			if(!stas[i])
			{
				bool d0=query(i,i+1,z1),d1=query(i+1,i+2,z1);
				if(d0==0&&d1==0)key[i]=key[i+1]=key[i+2]=0;
				if(d0==0&&d1==1)key[i]=key[i+1]=0,key[i+2]=1;
				if(d0==1&&d1==0)key[i+1]=key[i+2]=0,key[i]=1;
				if(d0==1&&d1==1)key[i]=key[i+2]=0,key[i+1]=1;
			}
			else
			{
				bool d0=query(i,i+1,z0),d1=query(i+1,i+2,z0);
				if(d0==0&&d1==0)key[i+1]=0,key[i]=key[i+2]=1;
				if(d0==0&&d1==1)key[i]=0,key[i+1]=key[i+2]=1;
				if(d0==1&&d1==0)key[i+2]=0,key[i]=key[i+1]=1;
				if(d0==1&&d1==1)key[i]=key[i+1]=key[i+2]=1;
			}
		}
	std::vector<int>ret;
	for(int i=1;i<=n;i++)if(!key[i])ret.push_back(i);
	reportImpostors(ret);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		findImpostors(n);
	}
}