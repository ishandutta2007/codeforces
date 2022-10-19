#include<cstdio>
#include<vector>
using namespace std;
int n,m,m1,t=0,cnt,mx;
bool ok=0;
int dif[250002]={};
vector<int> v;
vector<int> vec[250002];
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void print()
{
	puts("Yes");
	for(int i=0;i<m;++i)printf("%d ",vec[1][i]);
}
inline bool check()
{
	for(int i=2;i<=n;++i)
	{
		cnt=0;
		for(int j=0;j<m;++j)cnt+=(vec[i][j]!=vec[1][j]);
		if(cnt+dif[i]>2)return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&x),vec[i].push_back(x);
	for(int i=2;i<=n;++i)
	{
		cnt=0;
		for(int j=0;j<m;++j)cnt+=(vec[i][j]!=vec[1][j]);
		if(cnt>t)t=cnt,mx=i;
	}
	if(t>4)return 0&puts("No");
	if(t<=2){print();return 0;}
	for(int i=0;i<m;++i)if(vec[1][i]!=vec[mx][i])v.push_back(i);
	if(t==4)
	{
		for(int i=0,x,y;i<3;++i)
		{
			x=vec[1][v[i]],vec[1][v[i]]=vec[mx][v[i]];
			for(int j=i+1;j<4;++j)
			{
				y=vec[1][v[j]],vec[1][v[j]]=vec[mx][v[j]];
				if(check()){print();return 0;}
				vec[1][v[j]]=y;
			}
			vec[1][v[i]]=x;
		}
		return 0&puts("No");
	}
	for(int i=2;i<=n;++i)
	{
		for(int j=0;j<m;++j)
			if(j!=v[0] && j!=v[1] && j!=v[2] && vec[i][j]!=vec[1][j])
				vec[i][j]=vec[1][j],++dif[i];
		if(dif[i]>2)return 0&puts("No");
	}
	vec[0]=vec[1],m1=m,m=3;
	for(int i=1;i<=n;++i)vec[i][0]=vec[i][v[0]],vec[i][1]=vec[i][v[1]],vec[i][2]=vec[i][v[2]];
	for(int i=0,x,y;i<3;++i)
	{
		x=vec[1][i],vec[1][i]=vec[mx][i];
		for(int j=0;j<3;++j)
			if(j!=i)
			{
				y=vec[1][j];
				if(check()){ok=1;break;}
				vec[1][j]=vec[mx][j];
				if(check()){ok=1;break;}
				for(int k=2;k<=n;++k)
					if(vec[k][j]!=vec[1][j] && vec[k][j]!=vec[mx][j])
					{
						vec[1][j]=vec[k][j];
						break;
					}
				if(check()){ok=1;break;}
			}
		if(ok)break;
		vec[1][i]=x;
	}
	if(ok){vec[0][v[0]]=vec[1][0],vec[0][v[1]]=vec[1][1],vec[0][v[2]]=vec[1][2],vec[1]=vec[0],m=m1,print();return 0;}
	return 0&puts("No");
}