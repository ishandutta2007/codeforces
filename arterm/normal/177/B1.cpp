#include <iostream>

#define long long long

using namespace std;

long n;

long div(long n){
	for (int i=2; i*i<=n; ++i)
	if (n%i==0)
	return i;
	return n;
}

void kill(void){
	long s=1;
	while (n>1){
		s+=n;
		n/=div(n);
	}
	cout<<s<<"\n";
}

int main()
{
	cin>>n;
	kill();
	return 0;
}