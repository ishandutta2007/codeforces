#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;
LL ans;
map<int,int> mp;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int query(int x)
{
	if(mp.count(x))return mp[x];
	int t;
	printf("? %d\n",x),fflush(stdout),scanf("%d",&t),mp[x]=t;
	if(t)ans=min(ans,1LL*x*t);
	return t;
}
inline void solve(LL l,LL r)
{
	LL R=query(r);
	if(!R)return ;
	LL mid=(ans-1)/R;
	if(mid<l)return ;
	LL L=query(l);
	if(l+1>=r || L==R)
	{
		if(L)ans=min(ans,l*L);
		if(R)ans=min(ans,r*R);
		return ;
	}
	solve(l,mid);
}
int main()
{
	read(n);
	int l,r,mid;
	for(l=2,r=n*2000;l<=r;)
	{
		mid=((l+r)>>1);
		if(query(mid)==1)r=mid-1;
		else l=mid+1;
	}
	ans=l,solve(1,r);
	printf("! %lld",ans),fflush(stdout);
	return 0;
}