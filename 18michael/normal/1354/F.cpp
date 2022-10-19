#include<bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
int n,k,Test_num;
int f[76][76],from[76][76];
vector<int> vec,vec1;
struct aaa
{
	int a,b,id;
}w[76];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.b<b.b? 1:0;
}
inline void print(int x,int y)
{
	if(!x)return ;
	print(x-1,from[x][y]);
	if(from[x][y]==y)vec1.push_back(w[x].id);
	else vec.push_back(w[x].id);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(k);
		for(int i=1;i<=n;++i)read(w[i].a),read(w[i].b),w[i].id=i;
		sort(w+1,w+n+1,cmp),f[0][0]=0;
		for(int i=1;i<=k;++i)f[0][i]=-inf;
		for(int i=1,v1,v2;i<=n;++i)
		{
			f[i][0]=f[i-1][0]+(k-1)*w[i].b;
			for(int j=1;j<=k;++j)
			{
				v1=f[i-1][j-1]+(j-1)*w[i].b+w[i].a,v2=f[i-1][j]+(k-1)*w[i].b;
				if(v1>v2)f[i][j]=v1,from[i][j]=j-1;else f[i][j]=v2,from[i][j]=j;
			}
		}
		vec.clear(),vec1.clear(),print(n,k),printf("%d\n",vec.size()+2*vec1.size());
		for(int i=0;i<vec.size()-1;++i)printf("%d ",vec[i]);
		for(int i=0;i<vec1.size();++i)printf("%d %d ",vec1[i],-vec1[i]);
		printf("%d\n",vec.back());
	}
	return 0;
}