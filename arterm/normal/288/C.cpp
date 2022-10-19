#include <iostream>

#define M 23
#define N 1001000
#define long long long

using namespace std;

long n,s=0;
long p[M],a[M],b[N],ans=0;

void pre(void){
	p[0]=1;
	for (int i=1; i<M; ++i)
	p[i]=2*p[i-1];
}

void calc(void){
	
	for (int i=0; i<=n; ++i)
	b[i]=i;
	
	for (int i=0; p[i]<=n; ++i){
		long t=(n+1)/p[i+1];
		
		t*=p[i];
		
		long r=(n+1)%p[i+1];
		
		t+=min(r,p[i]);
		
		
		for (long l=0,r=p[i]; r<=n; ){
			swap(b[l],b[r]);
			
			
			l++,r++;
			
			if ((l&p[i])!=0)
			l+=p[i],r+=p[i];
			
		}
		
		
		ans=ans+2*p[i]*(n+1-t);
	}
	
	cout<<ans<<"\n";
	
	for (int i=0; i<=n; ++i,cout<<" ")
	cout<<b[i];
	
	cout<<"\n";
	
	/*long s=0;
	
	for (int i=0; i<=n; ++i)
	s=s+(b[i]^i);
	
	
	cout<<s<<"\n";*/
	
}

int main()
{
	pre();
	cin>>n;
	calc();
	return 0;
}