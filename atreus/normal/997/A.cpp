#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e5 + 10;
 
int main(){
	ios_base::sync_with_stdio(false);
	int n, x, y;
	string s;
	cin >> n >> x >> y;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '0' and (i == n - 1 or s[i + 1] == '1'))
			cnt ++;
	if (cnt == 0)
		return cout << 0 << endl, 0;
	cout << min(1ll * y * cnt, 1ll * x * (cnt - 1) + y) << '\n';
}