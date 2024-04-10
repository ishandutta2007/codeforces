#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,q,l=1,r=0,block;
int a[100002],t[100002],tim[100002]={},cnt[100002]={},num[100002]={},ans[100002];
vector<int> vec;
priority_queue<int,vector<int>,greater<int> > pq,ept;
struct aaa
{
	int l,r,bel,id;
}qry[100002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;
	do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
inline bool cmp(aaa a,aaa b)
{
	return (a.bel==b.bel)? (a.r==b.r? (a.l<b.l):(a.r<b.r)):(a.bel<b.bel);
}
inline void modify(int k,int f)
{
	--num[cnt[a[k]]],cnt[a[k]]+=f,++num[cnt[a[k]]];
}
inline int calc()
{
	int x=0,res=0;pq=ept;
	for(int i=0;i<vec.size();++i)if(cnt[vec[i]]>block)pq.push(cnt[vec[i]]);
	for(int i=1;i<=block;++i)t[i]=num[i];
	for(int i=1;i<=block;++i)
		if(t[i])
		{
			if(x)
			{
				--t[i],x+=i,res+=x;
				if(x>block)pq.push(x);
				else ++t[x];x=0;
			}
			if(t[i]&1)x=i,--t[i];
			res+=t[i]*i;
			if((i<<1)>block)for(int j=1;j<=(t[i]>>1);++j)pq.push((i<<1));
			else t[(i<<1)]+=(t[i]>>1);
		}
	if(x)pq.push(x);
	while(pq.size()>1)x=pq.top(),pq.pop(),x+=pq.top(),pq.pop(),res+=x,pq.push(x);
	return res;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	read(q),block=sqrt(n);
	for(int i=1;i<=n;++i)
		if((++tim[a[i]])==block)
			vec.push_back(a[i]);
	for(int i=1;i<=q;++i)read(qry[i].l),read(qry[i].r),qry[i].bel=(qry[i].l-1)/block,qry[i].id=i;
	sort(qry+1,qry+q+1,cmp);
	for(int i=1;i<=q;++i)
	{
		while(l>qry[i].l)modify(--l,1);
		while(r<qry[i].r)modify(++r,1);
		while(l<qry[i].l)modify(l++,-1);
		while(r>qry[i].r)modify(r--,-1);
		ans[qry[i].id]=calc();
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}