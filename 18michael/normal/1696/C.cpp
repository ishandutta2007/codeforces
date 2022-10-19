#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,k,nt,kt,cnt,val,o,res,Test_num;
int a[1000002],b[1000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check()
{
	for(nt=kt=1,cnt=val=0,o=-1;nt<=n || kt<=k;)
	{
		//printf("nt:%d kt:%d cnt:%d val:%d o:%d\n",nt,kt,cnt,val,o);
		if(o==1)
		{
			if(nt>n)return 0;
			for(res=1;!(a[nt]%m);a[nt]/=m,res*=m);
			if(a[nt]!=val)return 0;
			cnt-=res,++nt;
			if(cnt<0)o^=1,cnt=-cnt;
		}
		else if(!o)
		{
			if(kt>k)return 0;
			for(res=1;!(b[kt]%m);b[kt]/=m,res*=m);
			if(b[kt]!=val)return 0;
			cnt-=res,++kt;
			if(cnt<0)o^=1,cnt=-cnt;
		}
		else
		{
			if(nt>n)return 0;
			for(res=1;!(a[nt]%m);a[nt]/=m,res*=m);
			val=a[nt],cnt=res,o=0,++nt;
		}
		if(!cnt)cnt=val=0,o=-1;
	}
	return o==-1;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m);
		for(int i=1;i<=n;++i)read(a[i]);
		read(k);
		for(int i=1;i<=k;++i)read(b[i]);
		puts(check()? "Yes":"No");
	}
	return 0;
}