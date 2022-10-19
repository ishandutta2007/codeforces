#include<cstdio>
#include<vector>
using namespace std;
int n,m,ans=0,lena,lenb;
bool ok;
int a[202],b[202];
bool u[202][202]={};
vector<int> va0,va1,vb0,vb1;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check()
{
	lena=va1.size(),lenb=vb0.size();
	for(int i=0;i<lena;++i)
	{
		ok=0;
		for(int j=0;j<lenb;++j)
			if(!u[va1[i]][vb0[j]])
			{
				ok=1;
				break;
			}
		if(!ok)return 1;
	}
	lena=va1.size(),lenb=vb1.size();
	for(int i=0;i<lena;++i)
		for(int j=0;j<lenb;++j)
			u[va1[i]][vb1[j]]=1;
	return 0;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(b[i]);
	for(int r=256;r;r>>=1)
	{
		va0.clear(),va1.clear(),vb0.clear(),vb1.clear();
		for(int i=1;i<=n;++i)
		{
			if(a[i]&r)va1.push_back(i);
			else va0.push_back(i);
		}
		for(int i=1;i<=m;++i)
		{
			if(b[i]&r)vb1.push_back(i);
			else vb0.push_back(i);
		}
		ans+=r*check();
	}
	printf("%d",ans);
	return 0;
}