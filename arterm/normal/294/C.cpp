#include <iostream>
#include <algorithm>

#define M 1010
#define mod 1000000007

using namespace std;

int n,m,a[M],p[M],c[M][M];
long long ans=1;

void pre(void){
	p[0]=1;
	for (int i=1; i<M; ++i){
		p[i]=2*p[i-1];
		if (p[i]>=mod)
		p[i]-=mod;
	}
	
	for (int i=0; i<M; ++i)
	c[i][0]=1;
	
	for (int i=1; i<M; ++i)
	for (int j=1; j<=i; ++j){
		c[i][j]=c[i-1][j]+c[i-1][j-1];
		if (c[i][j]>=mod)
		c[i][j]-=mod;
	}
}

void read(void){
	cin>>n>>m;
	for (int i=0; i<m; ++i)
	cin>>a[i];
	a[m++]=n+1;
	a[m++]=0;
	sort(a,a+m);
}

void kill(void){
	int s=0;
	for (int i=1; i<m; ++i){
		int len=a[i]-a[i-1]-1;
		if (len<=0)
		continue;
		s=s+len;
		ans*=c[s][len];
		ans%=mod;
		if (a[i-1]!=0 && a[i]!=n+1)
		ans*=p[len-1],ans%=mod;
	}
	cout<<ans<<"\n";
}

int main()
{
	pre();
	read();
	kill();
	return 0;
}