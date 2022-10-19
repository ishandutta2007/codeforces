#include<bits/stdc++.h>
using namespace std;
int n,m,t,Test_num;
int a[300002],cnt[300002],rt[300002],p[300002];
vector<int> ans;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m);
		for(int i=1;i<=n;++i)read(a[i]),p[a[i]]=i,cnt[i]=0;
		for(int i=1;i<=n;++i)++cnt[(i-a[i]+n)%n];
		ans.clear();
		for(int i=0;i<n;++i)
		{
			if(n-cnt[i]>2*m)continue;
			for(int j=1;j<=n;++j)rt[j]=j;
			t=0;
			for(int j=1,k;j<=n;++j)
			{
				getroot(k=(j+i-1)%n+1),getroot(p[j]);
				if(rt[k]!=rt[p[j]])rt[rt[k]]=rt[p[j]],++t;
			}
			if(t<=m)ans.push_back(i);
		}
		printf("%d",ans.size());
		for(int i=0;i<ans.size();++i)printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}