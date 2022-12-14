#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	long long n;
	cin >> n;
	if (n == 0){
		cout << 1 << endl;
		return 0;
	}
	long long l = 6, r = 6 * n, tedad = (r - l) / 6 + 1;
	cout << 1ll * tedad * (r + l) / 2 + 1 << endl;
}