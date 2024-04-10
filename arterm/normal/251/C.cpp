#include <iostream>

#define M 400400
#define long long long

using namespace std;

long a,b,k,n=1,d[M],p[M];

long gcd(long x, long y){
	while (x){
		y%=x;
		swap(x,y);
	}
	return y;
}

long lcm(long x, long y){
	return x/gcd(x,y)*y;
}

void din(void){
	for (int i=1; i<=k; ++i)
	n=lcm(n,i);
	
	for (int i=1; i<=n; ++i){
		d[i]=d[i-1]+1;
		for (int j=2; j<=k; ++j)
		d[i]=min(d[i],(d[i-(i%j)]+1));
	}
}

void two(int r){
	for (int i=1; i<=n; ++i){
		p[i]=p[i-1]+1;
		int h=i+r;
		for (int j=2; j<=k; ++j)
		if (i-(h%j)>=0)
		p[i]=min(p[i],(p[i-(h%j)]+1));
	}
}

int main()
{
	cin>>a>>b>>k;
	din();
	long t=b/n,ans=0;
	b-=(t*n);
	a-=(t*n);
	
	two(b);
	
	if (a<=n)
	ans=p[a-b];
	else
	ans=p[n-b]+d[n]*(a/n-1)+d[a%n];
	
	cout<<ans<<"\n";
	return 0;
}