#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100500
char s[N*2],t[N];
int k=350,n,m,a,b,c,su[351][N],id[N],tid[N],ct,id2[N*2],lb[N][2],lb2[N][2],le,l,ct1,id3[N*2],id4[N*2];
long long as[N],as2[N];
struct sth{int a,t,id;};
vector<sth> v[N];
struct SA{
	int a[N*4],b[N*4],c[N*4],sa[N*4],rk[N*4],su[N*4],n,m,he[N*4],f[N*2][18],lg[N*2];
	void pre()
	{
		n=le,m=255;
		for(int i=1;i<=n;i++)su[a[i]=s[i]]++;
		for(int i=1;i<=m;i++)su[i]+=su[i-1];
		for(int i=n;i>=1;i--)sa[su[a[i]]--]=i;
		for(int l=1;l<=n;l<<=1)
		{
			int ct=0;
			for(int i=n-l+1;i<=n;i++)b[++ct]=i;
			for(int i=1;i<=n;i++)if(sa[i]>l)b[++ct]=sa[i]-l;
			for(int i=1;i<=m;i++)su[i]=0;
			for(int i=1;i<=n;i++)su[a[i]]++;
			for(int i=1;i<=m;i++)su[i]+=su[i-1];
			for(int i=n;i>=1;i--)sa[su[a[b[i]]]--]=b[i];
			for(int i=1;i<=n;i++)b[i]=a[i];
			m=2;a[sa[1]]=1;
			for(int i=2;i<=n;i++)a[sa[i]]=b[sa[i]]==b[sa[i-1]]&&b[sa[i]+l]==b[sa[i-1]+l]?m-1:m++;
			m--;
		}
		for(int i=1;i<=n;i++)rk[sa[i]]=i;
		s[n+1]='%';
		for(int i=1;i<=n;i++)
		{
			if(rk[i]==1)continue;
			int tp=he[rk[i-1]]-1;
			if(tp<0)tp=0;
			while(s[i+tp]==s[sa[rk[i]-1]+tp])tp++;
			he[rk[i]]=tp;
		}
		for(int i=2;i<=n;i++)f[i][0]=he[i],lg[i]=lg[i>>1]+1;
		for(int i=1;i<=17;i++)
		for(int j=2;j+(1<<i)-1<=n;j++)
		f[j][i]=min(f[j][i-1],f[j+(1<<i-1)][i-1]);
	}
	int query1(int l,int r)
	{
		if(l==r)return 1e7;
		int a=l,b=r;
		if(a>b)b++,a^=b^=a^=b;else a++;
		int tp=lg[b-a+1];
		return min(f[a][tp],f[b-(1<<tp)+1][tp]);
	}
	pair<int,int> query2(int x,int k)
	{
		pair<int,int> as1;
		int l=1,r=x,as=x;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(query1(mid,x)>=k)as=mid,r=mid-1;
			else l=mid+1;
		}
		as1.first=as;
		l=x,r=n,as=x;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(query1(x,mid)>=k)as=mid,l=mid+1;
			else r=mid-1;
		}
		as1.second=as;
		return as1;
	}
}sa;
struct sqrttr{
	int v[N*2],su[451],k=450,bel[N*2];
	void init(){for(int i=1;i<=le+1;i++)bel[i]=(i-1)/k+1;}
	void add(int x,int s)
	{
		for(int i=x;i<=bel[x]*k;i++)v[i]+=s;
		for(int i=bel[x]+1;i<=450;i++)su[i]+=s;
	}
	int que(int x){return su[bel[x]]+v[x];}
}tr;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",t+1);l=strlen(t+1);
		lb[i][0]=ct1+1,lb[i][1]=ct1+l;
		lb2[i][0]=le+1;lb2[i][1]=le+l;
		for(int j=1;j<=l;j++)s[++le]=t[j],id3[le]=++ct1;
		s[++le]='z'+1;
		if(l>k)tid[++ct]=i,id[i]=ct;
	}
	sa.pre();tr.init();
	for(int i=1;i<=ct;i++)
	for(int j=1,tp=0;j<=le;j++)
	if(id3[sa.sa[j]])
	su[i][tp+1]=su[i][tp]+(id3[sa.sa[j]]>=lb[tid[i]][0]&&id3[sa.sa[j]]<=lb[tid[i]][1]),id4[j]=++tp;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		v[a-1].push_back((sth){c,-1,i});
		v[b].push_back((sth){c,1,i});
	}
	for(int i=1;i<=n;i++)
	{
		pair<int,int> fu=sa.query2(sa.rk[lb2[i][0]],lb2[i][1]-lb2[i][0]+1);
		tr.add(fu.first,1);
		tr.add(fu.second+1,-1);
		for(int j=1;j<=ct;j++)as2[j]+=su[j][id4[fu.second]]-su[j][id4[fu.first]-1];
		for(int j=0;j<v[i].size();j++)
		{
			if(id[v[i][j].a])as[v[i][j].id]+=v[i][j].t*as2[id[v[i][j].a]];
			else for(int k=lb2[v[i][j].a][0];k<=lb2[v[i][j].a][1];k++)as[v[i][j].id]+=v[i][j].t*tr.que(sa.rk[k]);
		}
	}
	for(int i=1;i<=m;i++)printf("%lld\n",as[i]);
}