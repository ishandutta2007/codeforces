#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,A,B,t,X,Y,X1,Y1,Test_num;
int b[10002],u[10002];
vector<int> vec;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int query(int a,int b,int c)
{
	int t;
	printf("? %d %d %d\n",a,b,c),fflush(stdout),read(t);
	return t;
}
inline void calc(int x,int y)
{
	if(!y)u[x]=-1;else u[x]=1;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		int tot=0;
		read(n);
		A=B=X=Y=0,vec.clear();
		for(int i=1;i<=n;++i)u[i]=0;
		for(int i=1;i<=n/3;++i)
		{
			b[i]=query(3*i-2,3*i-1,3*i);
			if(b[i]==-1)return 0;
			if(b[i] && !A)A=i;
			if(!b[i] && !B)B=i;
		}
		t=query(3*A-2,3*A-1,3*B-2);
		if(!t)
		{
			u[3*B-2]=-1,u[3*A]=1;
			t=query(3*A-2,3*A-1,3*B-1),calc(3*B-1,t);
			t=query(3*A-2,3*A-1,3*B),calc(3*B,t);
			t=query(3*B-2,3*A,3*A-2),calc(3*A-2,t),u[3*A-1]=-u[3*A-2];
			X=3*A-1,Y=3*A-2;
		}
		else
		{
			t=query(3*A-2,3*A-1,3*B-1);
			if(!t)
			{
				u[3*B-2]=1,u[3*B-1]=-1,u[3*A]=1;
				t=query(3*A-2,3*A-1,3*B),calc(3*B,t);
				t=query(3*B-2,3*B-1,3*A-2),calc(3*A-2,t),u[3*A-1]=-u[3*A-2];
				X=3*A-1,Y=3*A-2;
			}
			else
			{
				u[3*A-2]=u[3*A-1]=1;
				t=query(3*B-2,3*B-1,3*A-1);
				if(!t)
				{
					u[3*B-2]=u[3*B-1]=-1;
					t=query(3*A-2,3*B-2,3*A),calc(3*A,t);
					t=query(3*A-2,3*B-2,3*B),calc(3*B,t);
					X=3*A-2,Y=3*B-2;
				}
				else
				{
					u[3*B]=-1;
					t=query(3*A-2,3*B,3*A),calc(3*A,t);
					t=query(3*A-2,3*B,3*B-2),calc(3*B-2,t),u[3*B-1]=-u[3*B-2];
					X=3*A-2,Y=3*B;
				}
			}
		}
		if(u[3*A-2]>0)++tot;
		if(u[3*A-1]>0)++tot;
		if(u[3*A]>0)++tot;
		if(u[3*B-2]>0)++tot;
		if(u[3*B-1]>0)++tot;
		if(u[3*B]>0)++tot;
		vec.push_back(3*A-2);
		vec.push_back(3*A-1);
		vec.push_back(3*A);
		vec.push_back(3*B-2);
		vec.push_back(3*B-1);
		vec.push_back(3*B);
		X1=Y1=0;
		for(int i=0;i<vec.size();++i)
		{
			if(u[vec[i]]>0 && !X1)X1=vec[i];
			if(u[vec[i]]<0 && !Y1)Y1=vec[i];
		}
		vec.clear();
		for(int i=1;i<=n/3;++i)
		{
			if(i==A || i==B)continue;
			if(b[i])
			{
				t=query(Y1,3*i-2,3*i-1);
				if(!t)u[3*i]=1,t=query(X,Y,3*i-2),calc(3*i-2,t),u[3*i-1]=-u[3*i-2];
				else u[3*i-2]=u[3*i-1]=1,t=query(X,Y,3*i),calc(3*i,t);
			}
			else
			{
				t=query(X1,3*i-2,3*i-1);
				if(t)u[3*i]=-1,t=query(X,Y,3*i-2),calc(3*i-2,t),u[3*i-1]=-u[3*i-2];
				else u[3*i-2]=u[3*i-1]=-1,t=query(X,Y,3*i),calc(3*i,t);
			}
		}
		for(int i=1;i<=n;++i)if(u[i]<0)vec.push_back(i);
		printf("! %d ",vec.size());
		for(int i=0;i<vec.size();++i)printf("%d%c",vec[i],i+1==vec.size()? '\n':' ');
		fflush(stdout);
	}
	return 0;
}