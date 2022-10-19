#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
	int l, r, x, y, k;
	scanf("%d%d%d%d%d", &l, &r, &x, &y, &k);

	l = (l - 1) / k + 1;
	r /= k;
	
	if (l <= r && l <= y && r >= x)
		puts("YES");
	else
		puts("NO");
			
	return 0;
}