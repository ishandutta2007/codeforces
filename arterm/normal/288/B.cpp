#include <iostream>

#define long long long
#define p 1000000007ll
#define M 17

using namespace std;


long n,k,a[M],h[]={0,1, 2, 9, 64, 625, 7776, 117649, 2097152};
bool b[M],c[M];

void next(void){
	int t=k;
	while (a[t]==k)
	a[t]=1,t--;
	a[t]++;
}

bool good(void){
	for (int i=1; i<=k; ++i)
	b[i]=0,c[i]=0;
	
	for (int i=1; i<=k; ++i){
		int t=i;
		for (int i=1; i<=k; ++i)
		c[i]=0;
		
		while (t!=1 && !c[t])
		c[t]=1,t=a[t];
		
		if (t!=1)
		return 0;
		
	}
	
	int t=a[1];
	
	while (t!=1 && !b[t])
	b[t]=0,t=a[t];
	
	if (t!=1)
	return 0;
	
	return 1;
}

void read(void){
	cin>>n>>k;
	long s=h[k];
	
	n-=k;
	
	for (int i=0; i<n; ++i)
	s*=n,s%=p;
	
	cout<<s<<"\n";
	
}

void make(){
	for (int i=1; i<=k; ++i)
	a[i]=1;
	
	long s=0,t=1;
	
	for (int i=1; i<=k; ++i)
	t*=k;
	
	for (int i=0; i<t; ++i){
		if (good())
		s++;
		next();
	}
	
	cout<<s<<", ";
	
}

int main()
{
	read();
	return 0;
}