#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 800080
int n,m,lb[N],rb[N],a,b,c,l1,tp[N];
char s[N];
struct SA{
	int sa[N],rk[N],a[N],b[N],su[N],n,m,he[N],mn[N][20],lg[N];
	char v[N];
	void init()
	{
		m=n+255;
		for(int i=1;i<=n;i++)su[a[i]=v[i]]++;
		for(int i=1;i<=m;i++)su[i]+=su[i-1];
		for(int i=n;i>=1;i--)sa[su[a[i]]--]=i;
		for(int k=1;k<=n;k<<=1)
		{
			int ct=0;
			for(int i=n;i>n-k;i--)b[++ct]=i;
			for(int i=1;i<=n;i++)if(sa[i]>k)b[++ct]=sa[i]-k;
			for(int i=1;i<=m;i++)su[i]=0;
			for(int i=1;i<=n;i++)su[a[i]]++;
			for(int i=1;i<=m;i++)su[i]+=su[i-1];
			for(int i=n;i>=1;i--)sa[su[a[b[i]]]--]=b[i];
			ct=2;
			for(int i=1;i<=n;i++)b[i]=a[i];
			a[sa[1]]=1;
			for(int i=2;i<=n;i++)a[sa[i]]=b[sa[i]]==b[sa[i-1]]&&b[sa[i]+k]==b[sa[i-1]+k]?ct-1:ct++;
		}
		for(int i=1;i<=n;i++)rk[sa[i]]=i;
		int ls=0;s[n+1]='%';
		for(int i=1;i<=n;i++)
		{
			if(ls)ls--;
			if(rk[i]==1)continue;
			while(v[i+ls]==v[sa[rk[i]-1]+ls])ls++;
			he[rk[i]]=ls;
		}
		for(int i=2;i<=n;i++)mn[i][0]=he[i];
		for(int j=1;j<=19;j++)
		for(int i=2;i+(1<<j)-1<=n;i++)
		mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
		for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	}
	int query(int l,int r)
	{
		if(l==r)return 1e9;
		if(l>r)l^=r^=l^=r;
		l++;
		int tp=lg[r-l+1];
		return min(mn[l][tp],mn[r-(1<<tp)+1][tp]);
	}
}sa;
struct pretree{
	int ch[N*8][2],su[N*8],rt[N],ct,ct2;
	int build(int l,int r)
	{
		int st=++ct;
		if(l==r)return st;
		int mid=(l+r)>>1;
		ch[st][0]=build(l,mid);
		ch[st][1]=build(mid+1,r);
		return st;
	}
	void init(){rt[0]=build(1,l1);}
	int adds(int x,int l,int r,int v)
	{
		int st=++ct;
		ch[st][0]=ch[x][0];ch[st][1]=ch[x][1];su[st]=su[x]+1;
		if(l==r)return st;
		int mid=(l+r)>>1;
		if(mid>=v)ch[st][0]=adds(ch[x][0],l,mid,v);
		else ch[st][1]=adds(ch[x][1],mid+1,r,v);
		return st;
	}
	void add(int v){rt[ct2+1]=adds(rt[ct2],1,l1,v);ct2++;}
	int query(int x,int l,int r,int l1,int r1)
	{
		if(l==l1&&r==r1)return su[x];
		if(!x)return 0;
		int mid=(l+r)>>1;
		if(mid>=r1)return query(ch[x][0],l,mid,l1,r1);
		else if(mid<l1)return query(ch[x][1],mid+1,r,l1,r1);
		else return query(ch[x][0],l,mid,l1,mid)+query(ch[x][1],mid+1,r,mid+1,r1);
	}
}pt;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		lb[i]=l1+1;
		scanf("%s",s+1);
		int l2=strlen(s+1);
		for(int j=1;j<=l2;j++)sa.v[l1+j]=s[j];
		rb[i]=l1+l2;
		l1+=l2;sa.v[++l1]='#';
	}
	sa.n=l1;sa.init();
	pt.init();
	for(int i=1;i<=n;i++)
	{
		for(int j=lb[i];j<=rb[i];j++)
		pt.add(sa.rk[j]);
		tp[i]=pt.ct2;
	}
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		int l=sa.rk[lb[c]],lb1=l,rb1=l1,as=l;
		while(lb1<=rb1)
		{
			int mid=(lb1+rb1)>>1;
			if(sa.query(l,mid)>=rb[c]-lb[c]+1)as=mid,lb1=mid+1;
			else rb1=mid-1;
		}
		lb1=1,rb1=l;
		int as2=l;
		while(lb1<=rb1)
		{
			int mid=(lb1+rb1)>>1;
			if(sa.query(mid,l)>=rb[c]-lb[c]+1)as2=mid,rb1=mid-1;
			else lb1=mid+1;
		}
		printf("%d\n",pt.query(pt.rt[tp[b]],1,l1,as2,as)-pt.query(pt.rt[tp[a-1]],1,l1,as2,as));
	}
}/////