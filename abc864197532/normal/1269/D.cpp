#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)


int main () {
	int n;
	cin >> n;
	lli a[2] = {0, 0}, tmp;
	fop (i,0,n) {
		cin >> tmp;
		a[i % 2] += (tmp / 2);
		a[1 - (i % 2)] += (tmp - (tmp / 2));
	}
	cout << *min_element(a,a+2) << endl;
}