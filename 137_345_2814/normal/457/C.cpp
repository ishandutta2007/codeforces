#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> hxy[100074],s[100014];
int n,a,b,k,siz[100025],sb[100041];
struct ed{
	int l,r,sz,sum;
}e[41004];
void build(int m,int l,int r)
{
	e[m].l=l;
	e[m].r=r;
	e[m].sz=e[m].sum=0;
	if(l==r)
	return;
	int mid=(l+r)>>1;
	build(m<<1,l,mid);
	build(m<<1|1,mid+1,r);
}
void add(int m,int x,int y)
{
	if(e[m].l==e[m].r)
	{
		e[m].sz+=y;
		e[m].sum+=x*y;
		return;
	}
	int mid=(e[m].l+e[m].r)>>1;
	if(mid>=x)
	add(m<<1,x,y);
	else
	add(m<<1|1,x,y);
	e[m].sz=e[m<<1].sz+e[m<<1|1].sz;
	e[m].sum=e[m<<1].sum+e[m<<1|1].sum;
}
int que(int m,int x)
{
	if(x<=0)return 0;
	if(e[m].l==e[m].r)
	return e[m].sum/e[m].sz*x;
	if(e[m<<1].sz>=x)
	return que(m<<1,x);
	else
	return e[m<<1].sum+que(m<<1|1,x-e[m<<1].sz);
}
bool cmp(int a,int b)
{
	return siz[a]>siz[b];
}
bool cmp2(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%d",&n);
	long long tmp=0,ans=2e9,cnt=0,scnt=n,tmp2;
	build(1,0,10000);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a==0)k++,scnt--;
		else
		{
			s[a].push_back(b);
			siz[a]++;
			tmp+=b;
		}
	}
	for(int i=1;i<=100000;i++)
	sb[i]=i;
	stable_sort(sb+1,sb+100001,cmp);
	for(int i=1;i<=100000;i++)
	{
		if(siz[i])
		cnt++;
		hxy[i]=s[sb[i]];
	}
	stable_sort(siz+1,siz+100001+1,cmp2);
	for(int i=1;i<=cnt;i++)
	sort(hxy[i].begin(),hxy[i].end());
	for(int i=0;i<=n;i++)
	{
		int k1=i-scnt-k;
		tmp2=que(1,k1);
		ans=min(ans,tmp+tmp2);
		if(i)
		for(int j=cnt;j>=1;j--)
		{
			tmp-=hxy[j][siz[j]-i];
			add(1,hxy[j][siz[j]-i],1);
			if(i==siz[j])
			cnt--;
			scnt--;
		}
	}
	printf("%lld\n",ans);
}//%%%lsj