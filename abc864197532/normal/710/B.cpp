#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int


lli a[300000];

int main () {
	int n;
	cin >> n;
	for (int i=0;i<n;++i) cin >> a[i];
	sort(a,a+n);
	cout << a[(n-1)/2] << endl;
}