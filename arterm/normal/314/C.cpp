#include <iostream>

#define M 100100
#define N 1000100
#define p 1000000007ll
#define long long long

using namespace std;

long n,a[M],f[N];

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i)
	cin>>a[i];
}

long sum(long r){
	long s=0;
	for (int i=r; i>=0; i=(i&(i+1))-1){
		s=s+f[i];
		if (s>=p)
		s-=p;
	}
	return s;
}

long sum(long l, long r){
	return (sum(r)-sum(l-1)+p)%p;
}

void inc(long i, long d){
	for (;i<N; i=(i|(i+1))){
		f[i]+=d;
		if (f[i]>p)
		f[i]-=p;
		if (f[i]<0)
		f[i]+=p;
	}
}

void kill(void){
	inc(0,1);
	for (int i=0; i<n; ++i){
		long del=a[i]*sum(a[i])-sum(a[i],a[i]);
		inc(a[i],(del+p)%p);
	}
	long ans=sum(N-10)-1;
	ans%=p;
	if (ans<0)
	ans+=p;
	cout<<ans<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	read();
	kill();
	return 0;
}