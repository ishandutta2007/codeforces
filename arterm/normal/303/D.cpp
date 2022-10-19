#include <iostream>
#include <vector>

#define long long long

using namespace std;

bool isPrime(long p){
	for (long i=2; i*i<=p && i<p; ++i)
	if (p%i==0)
	return 0;
	return 1;
}

long poww(long x, long a, long p){
	long y=1;
	while (a){
		if (a&1)
		y*=x,y%=p;
		x*=x,x%=p;
		a>>=1;
	}
	return y;
}

long n,x,p,t;
vector<long> f;

bool isRoot(long k){
	k%=p;
	if (k==0)
	return 0;
	
	for (int j=0; j<(int)f.size(); ++j)
	if (poww(k,n/f[j],p)==1)
	return 0;
	return 1;
}

void kill(void){
	p=n+1;
	
	if (n==1){
		long y=x-1;
		if (y<=1)
		y=-1;
		cout<<y<<"\n";
		return;
	}
	
	if (!isPrime(p)){
		cout<<"-1\n";
		return;
	}
	
	for (int i=2; i<=n; ++i)
	if (n%i==0){
		f.push_back(i);
		while (n%i==0)
		n/=i;
	}
	
	n=p-1;
	
	for (int i=x-1; i>1; --i)
	if (isRoot(i)){
		cout<<i<<"\n";
		return;
	}
	
	cout<<"-1\n";
	
}


int main()
{
	cin>>n>>x;
	kill();
	return 0;
}