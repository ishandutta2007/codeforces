#include<bits/stdc++.h>
using namespace std;
int n,k,Mx,sum=0;
int a[18],b[18];
bitset<2002> bs[65536];
struct cmp
{
	inline bool operator () (const int &x,const int &y) const
	{
		return b[x]<b[y];
	}
};
priority_queue<int,vector<int>,cmp> pq;
inline void calc(int x,int y)
{
	if(!x)return ;
	for(int i=0;i<n;++i)if((x>>i)&1 && a[i]<=y && bs[x^(1<<i)].test(y-a[i]))return calc(x^(1<<i),y-a[i]);
	for(int i=0;i<n;++i)if((x>>i)&1)++b[i];
	calc(x,y*k);
}
int main()
{
	scanf("%d%d",&n,&k),Mx=(1<<n)-1,bs[0].set(0);
	for(int i=0;i<n;++i)scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=Mx;++i)
	{
		for(int j=0;j<n;++j)if((i>>j)&1)bs[i]|=(bs[i^(1<<j)]<<a[j]);
		for(int j=sum/k;j;--j)if(bs[i].test(j*k))bs[i].set(j);
	}
	if(!bs[Mx].test(1))return 0&puts("NO");
	puts("YES"),calc(Mx,1);
	for(int i=0;i<n;++i)pq.push(i);
	for(int x,y;pq.size()>1;pq.push(x))for(x=pq.top(),pq.pop(),y=pq.top(),pq.pop(),printf("%d %d\n",a[x],a[y]),a[x]+=a[y];!(a[x]%k);a[x]/=k)--b[x];
	return 0;
}