#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli nums[100];


int main () {
	int n,sum=0;
	cin >> n;
	int a[n];
	for (int i=0;i<n;++i) {
		cin >> a[i];
		sum+=a[i];
	}
	int c,d;
	cin >> c >> d;
	if (d<c) {
		int tmp=d;
		d=c;
		c=tmp;
	}
	int sum2=0;
	for (int i=c-1;i<d-1;++i) {
		sum2+=a[i];
	}
	cout << min(sum-sum2,sum2) << endl;

}