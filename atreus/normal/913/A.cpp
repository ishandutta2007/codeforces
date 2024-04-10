#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn];

int main (){
	long long n, m;
	cin >> n >> m;
	if (n > 40)
		return cout << m << endl, 0;
	cout << m % (1ll << n);
}