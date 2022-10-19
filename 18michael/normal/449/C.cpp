#include<bits/stdc++.h>
using namespace std;
int n,p_t=0,las;
int p[100002];
bool u[100002]={},u1[100002]={};
typedef pair<int,int> P;
vector<P> vec;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void init()
{
	for(int i=2;i<=n;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=n/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
int main()
{
	read(n),init();
	for(int i=n/2;i>1;--i)
		if(!u[i])
		{
			las=0;
			for(int j=i;j<=n;j+=i)
				if(j!=2*i && !u1[j])
				{
					if(!las)las=j;
					else u1[las]=u1[j]=1,vec.push_back(P(las,j)),las=0;
				}
			if(las)u1[las]=u1[2*i]=1,vec.push_back(P(las,2*i));
		}
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();++i)printf("%d %d\n",vec[i].first,vec[i].second);
	return 0;
}