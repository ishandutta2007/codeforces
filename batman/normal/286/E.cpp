#include <bits/stdc++.h>
using namespace std;
#define ld double
#define Point complex<ld>
#define N ((int)1<<21)

const ld PI=acos(-1);
int n,m,K;
Point a[N];
bool mark[N];

void fft(Point a[],int inv)
{
	for(int i=0;i<n;i++)
	{
		int x=0;
		for(int j=0;j<K;j++)if((i&(1<<j)))x+=(1<<(K-j-1));
		if(x>i)swap(a[i],a[x]);
	}
	for(int len=2;len<=n;len*=2)
	{
		Point wn(cos(2*PI/len),inv*sin(2*PI/len));
		for(int i=0;i<n;i+=len)
		{
			Point w(1,0);
			for(int j=0;j<len/2;j++)
			{
				Point ex1=a[i+j]+w*a[i+j+len/2];
				Point ex2=a[i+j]-w*a[i+j+len/2];
				a[i+j]=ex1;
				a[i+j+len/2]=ex2;
				w*=wn;
			}
		}
	}
	if(inv==-1)
		for(int i=0;i<n;i++)
			a[i]/=n;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int x;scanf("%d",&x);
		mark[x]=1;a[x]={1,0};
	}
	n=1;
	while(n<=2*m)n*=2,K++;
	fft(a,1);
	for(int i=0;i<n;i++)a[i]*=a[i];
	fft(a,-1);
	vector <int> res;
	for(int i=1;i<=m;i++)
	{
		if(mark[i] && a[i].real()<0.7)res.push_back(i);
		if(!mark[i] && a[i].real()>0.8)return printf("NO\n"),0;
	}
	printf("YES\n%d\n",res.size());
	for(auto u:res)printf("%d ",u);
	printf("\n");
	return 0;
}