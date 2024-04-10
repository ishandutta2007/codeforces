#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

map<pair<int,int>, bool> mp;
vector<int> vX[maxn], vY[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int x, t, a, b, da, db;
	cin >> x >> t >> a >> b >> da >> db;
	for (int i = 0; i < t; i++){
		for (int j = 0; j < t; j++){
			if (x == 0 or a + b - i * da - j * db == x)
				return cout << "YES\n", 0;
		}
		if (a - i * da == x or b - i * db == x)
			return cout << "YES\n", 0;
	}
	cout << "NO\n";
}