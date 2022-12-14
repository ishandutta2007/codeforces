#include <iostream>
#include <queue>
#include <bitset>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;

const int maxn = 3000 + 100;

bool prime (ll x) {
	for (int i = 2; i <= sqrt (x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int main (){
	ios_base::sync_with_stdio (false);
	int tc;
	cin >> tc;
	while (tc --) {
		ll a, b;
		cin >> a >> b;
		if (a - b > 1 or !prime (a + b)) {
			cout << "NO \n";
		}
		else
			cout << "YES \n";
	}
}