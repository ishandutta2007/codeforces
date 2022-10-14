#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int
lli a[200000],n;


int main () {
	cin >> n;
	for (int i=0;i<n;++i) {
		cin >> a[i];
	}
	sort(a,a+n);
	int max=0,j=0,i=0;
	while (i<n) {
		if (n-i<max) break;
		if (a[i+max]>a[i]+5) {
			i++;
		} else {
			int now=1;
			while (now+i<n and a[now+i]<=a[i]+5) now++;
			i++;
			if (now>max) max=now;
		}
	}
	cout << max << endl;
}