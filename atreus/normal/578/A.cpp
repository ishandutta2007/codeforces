#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
const int maxn = 2e5 + 10;
const int mod = 1e9;

int main(){
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if (a < b)
		return cout << -1 << endl, 0;
	cout << fixed << setprecision(9) << (a + b) / (2.0 * ((a + b) / (2 * b))) << endl;
}