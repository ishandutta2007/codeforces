#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 4e5 + 10;
const int inf = 1e9;

int a[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	ll sum = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	if (sum & 1 or sum < 2 * a[n - 1])
		return cout << "NO\n", 0;
	cout << "YES\n";
}