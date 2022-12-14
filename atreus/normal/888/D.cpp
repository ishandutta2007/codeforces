#include <iostream>

using namespace std;

long long entekhab(int r, int k){
	long long jav = 1;
	for (int i = k; i > k - r; i--)
		jav *= i;
	long long p = 1;
	for (int i = 1; i <= r; i++)
		p *= i;
	jav /= p;
	return jav;
}

int main(){
	long long n, k, ans = 0;
	cin >> n >> k;
	for (int i = 2; i <= k; i++){
		long long l = entekhab(i, n);
		int x = 1;
		if (i == 3)
			x = 2;
		if (i == 4)
			x = 9;
		ans += x * l;
	}
	cout << ans + 1 << endl;
}