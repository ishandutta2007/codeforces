#include <iostream>
#include <algorithm>

#define M 100100

using namespace std;

int n;
double p[M],a[M],sum[M];

struct song{
	int a, p;
	void read(void){
		cin>>a>>p;
	}
} s[M];

bool operator <(song a, song b){
	return a.a*a.p*(100-b.p)>b.a*b.p*(100-a.p);
}

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i)
	s[i].read();
	
	sort(s,s+n);
}

void calc(void){
	for (int i=0; i<n; ++i)
	a[i]=s[i].a,p[i]=0.01*s[i].p;
	for (int i=n-1; i>=0; --i)
	sum[i]=sum[i+1]+p[i];
	
	double ans=0;
	
	for (int i=0; i<n; ++i)
	ans=ans+a[i]*p[i]*(n-i-1-sum[i+1])+a[i];
	
	cout<<ans<<"\n";
	
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.precision(16);
	cout<<fixed;
	read();
	calc();
	return 0;
}