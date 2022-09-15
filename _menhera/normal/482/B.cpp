#include<cstdio>
#define MAXN 131072
int N,M;
int l[MAXN];
int r[MAXN];
int q[MAXN];
int seg[2*MAXN];
void setv(int a,int b,int c)
{
	a+=MAXN;
	b+=MAXN;
	while(a<=b)
	{
		if(a%2==1)
			seg[a++]|=c;
		if(b%2==0)
			seg[b--]|=c;
		a/=2;
		b/=2;
	}
	return;
}
int getv(int a,int b)
{
	a+=MAXN;
	b+=MAXN;
	int res=seg[a];
	while(a<=b)
	{
		if(a%2==1)
			res&=seg[a++];
		if(b%2==0)
			res&=seg[b--];
		a/=2;
		b/=2;
	}
	return res;
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d%d",l+i,r+i,q+i);
		l[i]--; r[i]--;
		setv(l[i],r[i],q[i]);
	}
	for(int i=0;i<MAXN*2;i++)
		seg[i]|=seg[i/2];
	for(int i=MAXN-1;i>=0;i--)
		seg[i]|=seg[2*i]&seg[2*i+1];
	for(int i=0;i<M;i++)
	{
		if(getv(l[i],r[i])!=q[i])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=0;i<N;i++)
		printf("%d ",seg[i+MAXN]);
	return 0;
}