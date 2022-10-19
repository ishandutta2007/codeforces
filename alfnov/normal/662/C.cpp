#include<bits/stdc++.h>
using namespace std;
char s[21][100005];
int d[1<<20];
long long a[1<<20],b[1<<20],c[1<<20],ap[1<<20],bp[1<<20],cp[1<<20];
void FWT_xor(int l,long long *c,long long *d)
{
	if(l==1)
	{
		*d=*c;
		return;
	}
	int m=l>>1;
	FWT_xor(m,c,d);
	FWT_xor(m,c+m,d+m);
	for(int i=0;i<m;i++)
	{
		long long a1=*(d+i),a2=*(d+i+m);
		*(d+i)=a1+a2,*(d+i+m)=a1-a2;
	}
}
void IFWT_xor(int l,long long *d,long long *c)
{
	if(l==1)
	{
		*c=*d;
		return;
	}
	int m=l>>1;
	IFWT_xor(m,d,c);
	IFWT_xor(m,d+m,c+m);
	for(int i=0;i<m;i++)
	{
		long long a1=*(c+i),a2=*(c+i+m);
		*(c+i)=(a1+a2)>>1,*(c+i+m)=(a1-a2)>>1;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int j=1;j<=m;j++)
	{
		int r=0;
		for(int i=1;i<=n;i++)r=2*r+(s[i][j]-'0');
		a[r]++;
	}
	for(int i=1;i<(1<<n);i++)d[i]=d[i>>1]+(i&1);
	for(int i=0;i<(1<<n);i++)b[i]=min(d[i],n-d[i]);
	FWT_xor(1<<n,a,ap);
	FWT_xor(1<<n,b,bp);
	for(int i=0;i<(1<<n);i++)cp[i]=ap[i]*bp[i];
	IFWT_xor(1<<n,cp,c);
	long long ans=LLONG_MAX;
	for(int i=0;i<(1<<n);i++)ans=min(ans,c[i]);
	cout<<ans<<endl;
	return 0;
}