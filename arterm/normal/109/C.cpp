#include <iostream>

#define M 100100

using namespace std;

int p[M],w[M],n,a[M],m=0;
long long ans=0;

void ini(void){
	for (int i=0; i<M; ++i)
	p[i]=i,w[i]=1;
}

int get(int x){
	return p[x]= p[x]==x ? x:get(p[x]);
}

void uni(int x, int y){
	x=get(x);
	y=get(y);
	if (w[x]>w[y])
	swap(x,y);
	p[x]=y;
	w[y]+=w[x];
}

bool lucky(int x){
	while (x){
		if (x%10!=4 && x%10!=7)
		return 0;
		x/=10;
	}
	return 1;
}

void kill(void){
	cin>>n;
	for (int i=0,a,b,x; i+1<n; ++i){
		cin>>a>>b>>x;
		if (!lucky(x))
		uni(a,b);
	}
	
	for (int i=1; i<=n; ++i)
	if (p[i]==i)
	a[m++]=w[i];
	
	for (int i=0; i<m; ++i)
	ans=ans+1ll*a[i]*(n-a[i])*(n-a[i]-1);
	
	cout<<ans<<"\n";
}

int main()
{
	ini();
	kill();
	return 0;
}