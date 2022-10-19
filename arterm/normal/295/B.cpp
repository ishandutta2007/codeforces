#include <iostream>

#define M 507
#define long long long

using namespace std;

long n,d[M][M],x[M],s[M];

void read(void){
	cin>>n;
	for (int i=1; i<=n; ++i)
	for (int j=1; j<=n; ++j)
	cin>>d[i][j];
	for (int i=1; i<=n; ++i)
	cin>>x[i];
}

void bell(void){
	for (int k=n; k>=1; --k){
		int t=x[k];
		for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
		d[i][j]=min(d[i][j],(d[i][t]+d[t][j]));
		for (int i=k; i<=n; ++i)
		for (int j=k; j<=n; ++j)
		s[k]+=d[x[i]][x[j]];
	}
	for (int i=1; i<=n; ++i,cout<<" ")
	cout<<s[i];
	cout<<"\n";
}

int main()
{
	read();
	bell();
	return 0;
}