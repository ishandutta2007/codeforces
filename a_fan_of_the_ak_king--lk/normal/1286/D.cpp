#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int M=998244353;
int n,x[N],v[N],p[N],i,k;
int tmpx[N*2],tmpv[N*2],op[N*2];
long long s;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
long long ans[N*2][2][2];
void Insert(int x,int v)
{
	int i;
	for(i=1;i<=k;++i)
		if(1ll*x*tmpv[i]<=1ll*v*tmpx[i])
			break;
	for(int j=k;j>=i;--j)
		tmpx[j+1]=tmpx[j],tmpv[j+1]=tmpv[j],op[j+1]=op[j];
	tmpx[i]=x,tmpv[i]=v;
	op[i]=2;
	++k;
}
void dfs(int l,int r)
{
	if(l==r)
	{
		k=1;
		tmpx[k]=0,tmpv[k]=0;
		ans[k][0][0]=1-p[l];
		ans[k][1][1]=p[l];
		ans[k][1][0]=ans[k][0][1]=0;
		return;
	}
	long long a1[(r-l+1)*2+2][2][2],a2[(r-l+1)*2+2][2][2];
	int tx1[N*2],tx2[N*2],tv1[N*2],tv2[N*2];
	int mid=l+r>>1;
	int i;
	dfs(l,mid);
	for(i=1;i<=k;++i)
	{
		tx1[i]=tmpx[i],tv1[i]=tmpv[i];
		a1[i][0][0]=ans[i][0][0],a1[i][1][0]=ans[i][1][0],a1[i][0][1]=ans[i][0][1],a1[i][1][1]=ans[i][1][1];
	}
	int k1=k;
	dfs(mid+1,r);
	for(i=1;i<=k;++i)
	{
		tx2[i]=tmpx[i],tv2[i]=tmpv[i];
		a2[i][0][0]=ans[i][0][0],a2[i][1][0]=ans[i][1][0],a2[i][0][1]=ans[i][0][1],a2[i][1][1]=ans[i][1][1];
	}
	//cout<<l<<' '<<r<<endl;
	int k2=k;
	l=1,r=1;
	k=0;
	while(l<k1&&r<k2)
		if(1ll*tx1[l]*tv2[r]<1ll*tx2[r]*tv1[l])
		{
			tmpx[++k]=tx1[l];
			tmpv[k]=tv1[l];
			op[k]=0;
			++l;
		}
		else
		{
			tmpx[++k]=tx2[r];
			tmpv[k]=tv2[r];
			op[k]=1;
			++r;
		}
	while(l<k1)
	{
		tmpx[++k]=tx1[l];
		tmpv[k]=tv1[l];
		op[k]=0;
		++l;
	}
	while(r<k2)
	{
		tmpx[++k]=tx2[r];
		tmpv[k]=tv2[r];
		op[k]=1;
		++r;
	}
	Insert(x[mid+1]-x[mid],v[mid+1]+v[mid]);
	if(v[mid]<v[mid+1])
		Insert(x[mid+1]-x[mid],v[mid+1]-v[mid]);
	if(v[mid]>v[mid+1])
		Insert(x[mid+1]-x[mid],v[mid]-v[mid+1]);
	++k;
	tmpx[k]=tmpv[k]=0;
	for(i=1;i<=k;++i)
		ans[i][0][1]=ans[i][1][0]=ans[i][0][0]=ans[i][1][1]=0;
	/*for(i=1;i<=k;++i)
		printf("%d %d %d %lf\n",op[i],tmpx[i],tmpv[i],1.0*tmpx[i]/tmpv[i]);
	printf("\n");*/
	for(int a=0;a<=1;++a)
		for(int b=0;b<=1;++b)
			for(int c=0;c<=1;++c)
				for(int d=0;d<=1;++d)
				{
					int id=k;
					if(c==1&&d==0)
						for(i=1;i<=k;++i)
							if(x[mid+1]-x[mid]==tmpx[i]&&v[mid]+v[mid+1]==tmpv[i]&&op[i]==2)
								id=i;
					if(c==0&&d==0)
						if(v[mid+1]>v[mid])
							for(i=1;i<=k;++i)
								if(x[mid+1]-x[mid]==tmpx[i]&&v[mid+1]-v[mid]==tmpv[i]&&op[i]==2)
									id=i;
					if(c==1&&d==1)
						if(v[mid+1]<v[mid])
							for(i=1;i<=k;++i)
								if(x[mid+1]-x[mid]==tmpx[i]&&v[mid]-v[mid+1]==tmpv[i]&&op[i]==2)
									id=i;
					long long sa=a1[k1][a][c],sb=a2[k2][d][b];
					int t1=k1-1,t2=k2-1;
					i=id;
					if(id!=k)
					{
						for(i=k-1;i>id;--i)
						{
							if(op[i]==0)
							{
								sa=(sa+a1[t1][a][c])%M;
								--t1;
							}
							if(op[i]==1)
							{
								sb=(sb+a2[t2][d][b])%M;
								--t2;
							}
						}
					}
					ans[id][a][b]=(ans[id][a][b]+sa*sb)%M;
					for(i=id-1;i>=1;--i)
					{
						if(op[i]==0)
						{
							ans[i][a][b]=(ans[i][a][b]+a1[t1][a][c]*sb)%M;
							sa=(sa+a1[t1][a][c])%M;
							--t1;
						}
						if(op[i]==1)
						{
							ans[i][a][b]=(ans[i][a][b]+a2[t2][d][b]*sa)%M;
							sb=(sb+a2[t2][d][b])%M;
							--t2;
						}
					}
				}
	/*for(i=1;i<=k;++i)
		cout<<((ans[i][0][0]+ans[i][0][1]+ans[i][1][0]+ans[i][1][1])%M+M)%M<<endl;
	cout<<endl;*/
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d %d",&x[i],&v[i],&p[i]);
		p[i]=p[i]*qpow(100,M-2)%M;
	}
	dfs(1,n);
	for(i=1;i<k;++i)
		s=(s+(ans[i][0][0]+ans[i][0][1]+ans[i][1][0]+ans[i][1][1])%M*qpow(tmpv[i],M-2)%M*tmpx[i])%M;
	cout<<(s%M+M)%M;
}