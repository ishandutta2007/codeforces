#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>

using namespace std;

bool isprime(int n){
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
int main() {
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 2)
		return cout << 1, 0;
	if (n % 2 == 0)
		return cout << 2 << endl, 0;
	if (isprime(n))
		return cout << 1 << endl, 0;
	if (isprime(n - 2))
		return cout << 2 << endl, 0;
	else
		return cout << 3 << endl, 0;
}