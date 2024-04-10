#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
int n,Test_num;
int a[1000002];
unordered_map<int,int> mp;
vector<int> vec2;
struct aaa
{
	int x,y;
};
vector<aaa> vec;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void ins(int x,int y)
{
	for(int i=n;i>x;--i)a[i+2]=a[i];
	a[x+1]=a[x+2]=y,n+=2,vec.push_back((aaa){x,y});
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),mp.clear(),vec.clear(),vec2.clear();
		for(int i=1;i<=n;++i)read(a[i]),++mp[a[i]];
		for(int i=1;i<=n;++i)
			if(mp[a[i]]&1)
			{
				puts("-1");
				goto QAQ;
			}
		for(int i=1,j,k,l;i<=n;i=2*j-i)
			for(j=i+1;j<=n;++j)
				if(a[i]==a[j])
				{
					//printf("i:%d j:%d\n",i,j);
					vec2.push_back((j-i)*2);
					for(k=i+1,l=j+1;k<j;++k,++l)
					{
						//printf("k:%d %d l:%d %d\n",k,a[k],l,a[l]);
						if(l<=n && a[k]==a[l])continue;
						ins(l-1,a[k]);
					}
					break;
				}
		printf("%d\n",vec.size());
		for(int i=0;i<vec.size();++i)printf("%d %d\n",vec[i].x,vec[i].y);
		printf("%d\n",vec2.size());
		for(int i=0;i<vec2.size();++i)printf("%d\n",vec2[i]);
		QAQ:;
	}
	return 0;
}