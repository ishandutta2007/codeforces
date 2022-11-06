#include <iostream>
using namespace std;
#define LL long long

LL x, y; int t;

int main() {
	cin>>t;
	while (t--) {
		cin>>x>>y;
		if (x-y>1) puts("YES");
		else puts("NO");
	}
	return 0;
}