#include <iostream>
using namespace std;
#define lli long long int

int main () {
	lli a[4],sum=0;
	for (int i=0;i<4;++i) {
		cin >> a[i];
		sum+=a[i];
	}
	sum/=3;
	for (int i=0;i<4;++i) {
		if (sum!=a[i]) cout << sum-a[i] << ' ';
	}
	cout << endl;
}