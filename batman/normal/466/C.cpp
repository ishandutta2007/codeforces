#include <iostream>
using namespace std;
int n, i, a;
long long b[500000], s, ans;
int main()
{
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>a;
		s+=a; b[i]=s;
	}
	for (a=0,i=0; i<n; i++) {
		if (i>0 && i<n-1 && b[i]*3==b[n-1]*2) ans+=a;
		if (b[i]*3==b[n-1]) a++;
	}
	cout<<ans<<endl;
	return 0;
}