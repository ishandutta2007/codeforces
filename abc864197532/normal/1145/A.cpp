#include <iostream>
#include <math.h>
using namespace std;

int a[16],n;

bool is (int i,int b) {
	int now=0;
	for (int k=i;k<i+b;++k) {
		if (now<=a[k]) now=a[k];
		else return false;
	}
	return true;
}


int main () {
	cin >> n;
	int now=n;
	for (int i=0;i<n;++i) cin >> a[i];
	int i=0;
	while (now>1) {
		if (i==n) {
			now/=2;
			i=0;
		}
		if (is(i,now)) {
			cout << now << endl;
			return 0;
		}
		i+=now;
	}
	cout << 1 << endl;
	return 0;
}