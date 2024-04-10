#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>


using namespace std;
typedef long long ll;

ll f(ll n) {
	if (n <= 1)
		return 0;
	return (n >> 1) + (f((n+1) >> 1) << 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n;
	cin >> n;
	cout << f(n);
	return 0;
}