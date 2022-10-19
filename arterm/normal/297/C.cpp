#include <iostream>
#include <algorithm>

#define f first
#define s second
#define mp make_pair
#define M 200100

using namespace std;

pair<int,int> s[M];
int n,m,a[M],b[M];

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i){
		cin>>b[i];
		s[i]=mp(b[i],i);
	}
	sort(s,s+n);
	m=n;
	while (m%3!=0)
	s[m]=mp(s[m-1].f,m),m++;
}

void kill(void){
	int k=m/3;
	for (int i=0; i<k; ++i)
	a[s[i].s]=0;
	for (int i=k; i<2*k; ++i)
	a[s[i].s]=s[i].f;
	
	for (int i=2*k; i<m; ++i)
	a[s[i].s]=m-i;

	cout<<"YES\n";
	
	for (int i=0; i<n; ++i,cout<<" ")
	cout<<a[i];
	
	cout<<"\n";
	
	for (int i=0; i<n; ++i,cout<<" ")
	cout<<b[i]-a[i];
}

int main()
{
	read();
	kill();
	
	return 0;
}