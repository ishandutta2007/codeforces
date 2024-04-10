#include <iostream>

#define long long long

using namespace std;

long n,m,x,y,a,b,k;

long gcd(long x, long y){
	while (x>0){
		y%=x;
		swap(x,y);
	}
	return x+y;
}

void kill(void){
	long d=gcd(a,b);
	a/=d,b/=d;
	
	k=min((n/a),(m/b));
	a*=k,b*=k;
	
	long x1=x-(a+1)/2;
	long y1=y-(b+1)/2;
	
	if (x1<0)
	x1=0;
	if (x1+a>n)
	x1=n-a;
	
	if (y1<0)
	y1=0;
	if (y1+b>m)
	y1=m-b;
	
	cout<<x1<<" "<<y1<<" ";
	x1+=a;
	y1+=b;
	cout<<x1<<" "<<y1<<"\n";
	
}

int main()
{
	cin>>n>>m>>x>>y>>a>>b;
	kill();
	return 0;
}