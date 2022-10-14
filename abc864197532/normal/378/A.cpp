#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)


int main () {
	int a,b,aa=0,bb=0,cc=0;
	cin >> a >> b;
	fop (i,1,7) {
		if (abs(i-a)>abs(i-b)) cc++;
		else if (abs(i-a)<abs(i-b)) aa++;
		else bb++;
	}
	cout << aa << ' ' << bb << ' ' << cc << endl;
}