#include <iostream>
using namespace std;

int main () {
	int n,m,a,b,c,d;
	cin >> n >> m >> a >> b >> c >> d;
	for (int i=m;i>=1;--i) {
		n+=i;
		if (i==b) n-=a;
		if (i==d) n-=c;
		if (n<0) n=0;
	}
	cout << n << endl;
}