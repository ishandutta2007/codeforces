#include<cstdio>
#include<algorithm>
using namespace std;
long long x, y, z, RR = 3e18;
void UDT(long long a, long long b) {
	if (a < 0 || b < 0)return;
	if (RR > abs(a - x))RR = abs(a - x);
}
int main() {
	scanf("%lld%lld%lld", &x, &y, &z);
	long long tx = x / z * z;
	long long ty = x + y - tx;
	if (tx / z + ty / z == x / z + y / z) {
		printf("%lld %d\n", x / z + y / z, 0);
	}
	else {
		long long px = x / z * z, py = y / z * z;
		UDT(px, x + y - px);
		UDT(x + y - py, py);
		UDT(px + z, x + y - (px + z));
		UDT(x + y - (py + z), py + z);
		printf("%lld %lld\n", tx / z + ty / z, RR);
	}
}