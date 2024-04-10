#include <string>
#include <iostream>

#define long long long
#define p 1000000007ll
#define M 1010

using namespace std;

string s,t;
int n,k;
bool u[M];

long bin(long x, long a){
	long y=1;
	while (a){
		if (a&1)
		y*=x,y%=p;
		x*=x,x%=p;
		a>>=1;
	}
	return y;
}

void read(void){
	cin>>s>>t>>k;
	n=s.length();
}

long val(long pos, long n, long k){
	long s=bin(n-1,k);
	
	if (k%2==0)
	s--;
	else
	s++;
	
	s*=bin(n,p-2);
	s%=p;
	
	if (pos==0)
	if (k%2==0)
	s++;
	else
	s--;
	return s;
}

void make(void){
	long ans=0;
	
	s=s+s;
	for (int i=0; i<n; ++i)
	if (s.substr(i,n)==t)
	ans+=val(i,n,k);
	
	ans%=p;
	if (ans<0)
	ans+=p;
	
	cout<<ans<<"\n";
	
}

int main()
{
	read();
	make();
	return 0;
}