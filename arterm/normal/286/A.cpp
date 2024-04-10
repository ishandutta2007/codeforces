#include <iostream>

#define M 100100

using namespace std;

int n,p[M];

void read(void){
	cin>>n;
}

void kill(void){
	if (n%4==3 || n%4==2){
		cout<<"-1\n";
		return;
	}
	for (int i=1; 2*i<=n; i+=2){
		p[i]=i+1;
		p[i+1]=n+1-i;
		p[n+1-i]=n-i;
		p[n-i]=i;
	}
	if (n%2==1)
	p[(n+1)/2]=(n+1)/2;
	for (int i=1; i<=n; ++i,cout<<" ")
	cout<<p[i];
}

int main()
{
	read();
	kill();
	return 0;
}