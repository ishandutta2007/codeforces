#include<bits/stdc++.h>
using namespace std;
int n,t1,t2,vec_t=0,la;
bool ok;
int a[54],b[54],l[54];
vector<int> vec[54];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void get_l()
{
	la=0;
	for(int i=1;i<=n+1;++i)
	if(a[i]!=a[i-1]+1)
	{
		for(int j=la;j<i;++j)l[j]=la;
		la=i;
	}
}
int main()
{
	read(n),a[0]=a[n+1]=-1;
	for(int i=1;i<=n;++i)read(a[i]);
	get_l();
	while(1)
	{
		ok=0;
		for(int i=1;i<n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(a[j]==i)t1=j;
				if(a[j]==i+1)t2=j;
			}
			if(t1>t2){ok=1;break;}
		}
		if(!ok)break;++vec_t;
		for(int i=1;i<=n;++i)b[i]=a[i];
		if(t2-1)
		{
			vec[vec_t].push_back(t2-1);
			for(int i=n-t2+2;i<=n;++i)a[i]=b[i-n+t2-1];
		}
		vec[vec_t].push_back(l[t1]-t2);
		for(int i=n-l[t1]+2;i<=n-t2+1;++i)a[i]=b[i-n+l[t1]+t2-2];
		vec[vec_t].push_back(t1-l[t1]+1);
		for(int i=n-t1+1;i<=n-l[t1]+1;++i)a[i]=b[i-n+l[t1]+t1-1];
		if(n-t1)
		{
			vec[vec_t].push_back(n-t1);
			for(int i=1;i<=n-t1;++i)a[i]=b[i+t1];
		}
		get_l();
	}
	printf("%d\n",vec_t);
	for(int i=1;i<=vec_t;++i)
	{
		printf("%d",vec[i].size());
		for(int j=0;j<vec[i].size();++j)printf(" %d",vec[i][j]);
		puts("");
	}
	return 0;
}