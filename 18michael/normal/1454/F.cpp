#include<bits/stdc++.h>
using namespace std;
int Test_num,n;
bool ok;
int arr[200002],num[200002];
struct aaa
{
	int val,id;
}a[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.val==b.val? (a.id<b.id):(a.val>b.val);
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int x,int d)
{
	while(x<=n)arr[x]+=d,x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)res+=arr[x],x-=lowbit(x);
	return res;
}
inline int before(int l,int x)
{
	int r=x,mid,t=query(x);
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(t==query(mid-1))r=mid-1;
		else l=mid+1;
	}
	return l;
}
inline int after(int x,int r)
{
	int l=x,mid,t=query(x-1);
	while(l<=r)
	{
		mid=((l+r)>>1);
		if(query(mid)==t)l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n);
		for(int i=1;i<=n;++i)read(a[i].val),a[i].id=i,arr[i]=0,num[i]=a[i].val;
		sort(a+1,a+n+1,cmp);
		for(int i=1,j,k1,k2,t1,t2;i<=n;i=j+1)
		{
			for(j=i;j+1<=n && a[j+1].val==a[i].val;++j);
			if(j-i<=1 || query(a[i].id-1) || query(a[j].id)<i-1){for(int k=i;k<=j;++k)modify(a[k].id,1);continue;}
			k1=after(a[i].id,a[j].id),k2=before(a[i].id,a[j].id);
			if(k1>k2){printf("YES\n%d %d %d\n",a[i+1].id-1,1,n-a[i+1].id);goto QAQ;}
			t1=query(k2-1)-query(k1);
			for(int k=i;k<=j;++k)modify(a[k].id,1);
			t2=query(k2-1)-query(k1);
			if(t2<k2-k1-1)continue;
			if(t1<k2-k1-1){printf("YES\n%d %d %d\n",k1,k2-1-k1,n-k2+1);goto QAQ;}
			if(num[k1]==a[i].val && k1>a[i].id){printf("YES\n%d %d %d\n",k1-1,k2-k1,n-k2+1);goto QAQ;}
			if(num[k2]==a[j].val && k2<a[j].id){printf("YES\n%d %d %d\n",k1,k2-k1,n-k2);goto QAQ;}
		}
		puts("NO");QAQ:;
	}
	return 0;
}