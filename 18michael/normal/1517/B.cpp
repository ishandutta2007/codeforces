#include<bits/stdc++.h>
using namespace std;
int n,m,Test_num;
int a[10002],id[10002];
bool vis[10002],vis1[10002];
set<int> s;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return a[x]<a[y]? 1:0;
}
inline int num(int x,int y)
{
	return x*m+y;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m);
		for(int i=0;i<n;++i)for(int j=0;j<m;++j)read(a[id[num(i,j)]=num(i,j)]),vis[num(i,j)]=0;
		sort(id,id+n*m,cmp);
		for(int i=0;i<m;++i)vis[id[i]]=1,vis1[i]=0,s.insert(id[i]);
		for(int i=0,x;i<m;++i)
		{
			for(int j=0;j<n;++j)
				if(vis[num(j,i)])
				{
					vis1[i]=1,vis[num(j,i)]=0,s.erase(num(j,i));
					break;
				}
			if(!vis1[i])x=(*s.begin()),s.erase(x),swap(a[x],a[x-(x%m)+i]),vis[x]=0;
		}
		for(int i=0;i<n;++i)for(int j=0;j<m;++j)printf("%d%c",a[num(i,j)],j+1==m? '\n':' ');
	}
	return 0;
}