#include <iostream>
#include <algorithm>

#define M 5050
#define long long long

using namespace std;

int n,d[M];
long a[M],b[M];

void read(void){
	cin>>n;
	for (long x,i=0; i<n; ++i){
		cin>>x;
		while (x%2==0)
		a[i]++,x>>=1;
		b[i]=x;
	}
}

bool fit(int i, int j){
	if (b[i]%b[j]!=0)
	return 0;
	return a[j]-j==a[i]-i || a[j]<j-i;
}

void din(void){
	for (int i=n-1; i>=0; --i){
		d[i]=n-i-1;
		for (int j=i+1; j<n; ++j)
		if (fit(i,j))
		d[i]=min(d[i],(j-i-1+d[j]));
	}
	for (int i=0; i<n; ++i)
	d[i]+=i;
	cout<<*min_element(d,d+n)<<"\n";
}


int main()
{
	read();
	din();
	return 0;
}