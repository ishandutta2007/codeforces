#include <iostream>
#include <algorithm>

#define M 100100
#define long long long

using namespace std;

long n,m=0;

struct line{
	long k,b;
	void read(void){
		cin>>k>>b;
	}
} a[M],b[M];

bool operator <(line x, line y){
	return (double)x.b/x.k>(double)y.b/y.k;
}

bool operator == (line x, line y){
	return  x.k*y.b==x.b*y.k;
}

void read(void){
	cin>>n;
	for (int i=0; i<n; ++i)
	a[i].read();
	for (int i=0; i<n; ++i)
	if (a[i].k!=0)
	b[m++]=a[i];
}

void kill(void){
	int ans=0;
	sort(b,b+m);
	for (int i=0,j; i<m; ){
		j=i;
		while (j<m && b[i]==b[j])
		++j;
		i=j;
		ans++;
	}
	cout<<ans<<"\n";
}

int main()
{
	read();
	kill();
	return 0;
}