#include<bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
int n,d;
double mn=inf;
int c[10],ans[10];
double t[10]={};
vector<int> vec[10];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int Pow(int a,int b)
{
	int res=1;
	for(int i=1;i<=b;++i)res*=a;
	return res;
}
inline void dfs(int x,int y,double z)
{
	switch(x)
	{
		case 1:c[1]=0,dfs(x+1,y,z);return ;
		case 2:c[2]=0,dfs(x+1,((y*Pow(2,vec[2].size()<1? 0:(vec[2].size()-1)%4+1))%10),z);
			   if(vec[2].size()>=1)c[2]=1,dfs(x+1,((y*Pow(2,vec[2].size()<2? 0:(vec[2].size()-2)%4+1))%10),z+log2(vec[2][0]));
			   if(vec[2].size()>=2)c[2]=2,dfs(x+1,((y*Pow(2,vec[2].size()<3? 0:(vec[2].size()-3)%4+1))%10),z+log2(vec[2][0])+log2(vec[2][1]));
			   if(vec[2].size()>=3)c[2]=3,dfs(x+1,((y*Pow(2,vec[2].size()<4? 0:(vec[2].size()-4)%4+1))%10),z+log2(vec[2][0])+log2(vec[2][1])+log2(vec[2][2]));
			   c[2]=vec[2].size(),dfs(x+1,y,z+t[2]);return ;
		case 3:c[3]=0,dfs(x+1,((y*Pow(3,vec[3].size()<1? 0:(vec[3].size()-1)%4+1))%10),z);
			   if(vec[3].size()>=1)c[3]=1,dfs(x+1,((y*Pow(3,vec[3].size()<2? 0:(vec[3].size()-2)%4+1))%10),z+log2(vec[3][0]));
			   if(vec[3].size()>=2)c[3]=2,dfs(x+1,((y*Pow(3,vec[3].size()<3? 0:(vec[3].size()-3)%4+1))%10),z+log2(vec[3][0])+log2(vec[3][1]));
			   if(vec[3].size()>=3)c[3]=3,dfs(x+1,((y*Pow(3,vec[3].size()<4? 0:(vec[3].size()-4)%4+1))%10),z+log2(vec[3][0])+log2(vec[3][1])+log2(vec[3][2]));
			   return ;
		case 4:c[4]=0,dfs(x+1,((y*Pow(4,vec[4].size()<1? 0:(vec[4].size()-1)%2+1))%10),z);
			   if(vec[4].size()>=1)c[4]=1,dfs(x+1,((y*Pow(4,vec[4].size()<2? 0:(vec[4].size()-2)%2+1))%10),z+log2(vec[4][0]));
			   c[4]=vec[4].size(),dfs(x+1,y,z+t[4]);return ;
		case 5:c[5]=0,dfs(x+1,((y*Pow(5,vec[5].size()>0))%10),z);
			   c[5]=vec[5].size(),dfs(x+1,y,z+t[5]);return ;
		case 6:c[6]=0,dfs(x+1,((y*Pow(6,vec[6].size()>0))%10),z);
			   c[6]=vec[6].size(),dfs(x+1,y,z+t[6]);return ;
		case 7:c[7]=0,dfs(x+1,((y*Pow(7,vec[7].size()<1? 0:(vec[7].size()-1)%4+1))%10),z);
			   if(vec[7].size()>=1)c[7]=1,dfs(x+1,((y*Pow(7,vec[7].size()<2? 0:(vec[7].size()-2)%4+1))%10),z+log2(vec[7][0]));
			   if(vec[7].size()>=2)c[7]=2,dfs(x+1,((y*Pow(7,vec[7].size()<3? 0:(vec[7].size()-3)%4+1))%10),z+log2(vec[7][0])+log2(vec[7][1]));
			   if(vec[7].size()>=3)c[7]=3,dfs(x+1,((y*Pow(7,vec[7].size()<4? 0:(vec[7].size()-4)%4+1))%10),z+log2(vec[7][0])+log2(vec[7][1])+log2(vec[7][2]));
			   return ;
		case 8:c[8]=0,dfs(x+1,((y*Pow(8,vec[8].size()<1? 0:(vec[8].size()-1)%4+1))%10),z);
			   if(vec[8].size()>=1)c[8]=1,dfs(x+1,((y*Pow(8,vec[8].size()<2? 0:(vec[8].size()-2)%4+1))%10),z+log2(vec[8][0]));
			   if(vec[8].size()>=2)c[8]=2,dfs(x+1,((y*Pow(8,vec[8].size()<3? 0:(vec[8].size()-3)%4+1))%10),z+log2(vec[8][0])+log2(vec[8][1]));
			   if(vec[8].size()>=3)c[8]=3,dfs(x+1,((y*Pow(8,vec[8].size()<4? 0:(vec[8].size()-4)%4+1))%10),z+log2(vec[8][0])+log2(vec[8][1])+log2(vec[8][2]));
			   c[8]=vec[8].size(),dfs(x+1,y,z+t[8]);return ;
		case 9:c[9]=0,dfs(x+1,((y*Pow(9,vec[9].size()<1? 0:(vec[9].size()-1)%2+1))%10),z);
			   if(vec[9].size()>=1)c[9]=1,dfs(x+1,((y*Pow(9,vec[9].size()<2? 0:(vec[9].size()-2)%2+1))%10),z+log2(vec[9][0]));
			   return ;
	}
	if(y==d && z<mn)
	{
		mn=z;
		for(int i=1;i<=9;++i)ans[i]=c[i];
	}
}
int main()
{
	read(n),read(d);
	for(int i=1,x;i<=n;++i)read(x),vec[x%10].push_back(x),t[x%10]+=log2(x);
	if(!d)
	{
		if(!vec[0].size())puts("-1");
		else
		{
			printf("%d\n",n);
			for(int i=0;i<=9;++i)
				for(int j=0;j<vec[i].size();++j)
					printf("%d ",vec[i][j]);
		}
		return 0;
	}
	for(int i=1;i<=9;++i)sort(vec[i].begin(),vec[i].end());
	dfs(1,1,0);
	if(mn==inf)puts("-1");
	else
	{
		n-=vec[0].size();
		for(int i=1;i<=9;++i)n-=ans[i];
		if(!n)puts("-1");
		else
		{
			printf("%d\n",n);
			for(int i=1;i<=9;++i)
				for(int j=ans[i];j<vec[i].size();++j)
					printf("%d ",vec[i][j]);
		}
	}
	return 0;
}