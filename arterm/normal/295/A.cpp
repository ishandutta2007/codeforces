#include <iostream>
#include <algorithm>
#include <vector>

#define long long long
#define f first
#define s second
#define mp make_pair
#define M 100100

using namespace std;

long n,m,k,a[M],t[M], q[M],l[M],r[M],d[M];

void read(void){
	cin>>n>>m>>k;
	for (int i=1; i<=n; ++i)
	cin>>a[i];
	
	for (int i=1; i<=m; ++i)
	cin>>l[i]>>r[i]>>d[i];
	
	for (int i=0,x,y; i<k; ++i){
		cin>>x>>y;
		q[x]++;
		q[y+1]--;
	}
	
	for (int i=1; i<=m; ++i)
	q[i]+=q[i-1];
	
	for (int i=1; i<=m; ++i){
		long x=l[i];
		long y=r[i];
		long val=d[i];
		t[x]+=(val*q[i]);
		t[y+1]-=(val*q[i]);
	}
	
	for (int i=1; i<=n; ++i)
	t[i]+=t[i-1];
	
	for (int i=1; i<=n; ++i)
	a[i]+=t[i];
	
	for (int i=1; i<=n; ++i,cout<<" ")
	cout<<a[i];
	cout<<"\n";
}


int main()
{
	read();
	return 0;
}