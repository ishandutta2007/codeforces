#include <iostream>
#include <cstdlib>

#define N 5050
#define M 1001000

using namespace std;

int n,a[N],b[M],k,t[M];

void read(void){
	cin>>n>>k;
	for (int i=0; i<n; ++i)
	cin>>a[i];
	
	for (int i=0; i<n; ++i)
	for (int j=i+1; j<n; ++j)
	b[abs(a[i]-a[j])]++;
	
	for (int i=1; i<M; ++i)
	for (int j=i+i; j<M; j+=i)
	b[i]+=b[j];
}

bool cou(int m){
	return b[m]<=k*(k+1)/2;
}

bool brute(int m){
	int s=0;
	for (int i=0; i<m; ++i)
	t[i]=0;
	for (int i=0; i<n; ++i)
	t[a[i]%m]++;
	for (int i=0; i<m; ++i)
	if (t[i]>0)
	s=s+t[i]-1;
	return s<=k;
}


void kill(void){
	for (int i=1; i<M; ++i)
	if (cou(i) && brute(i)){
		cout<<i<<"\n";
		return;
	}
}

int main()
{
	read();
	kill();
	return 0;
}