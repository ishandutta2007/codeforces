#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;


int main(){
	ios_base::sync_with_stdio(false);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	int answer = 0;
	vector<int> c;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		x %= (a + b);
		if (x == 0)
			x = (a + b);
		c.push_back((x + a - 1) / a);
	}
	sort(c.begin(), c.end());
	for (int i = 0; i < n; i++){
		if (k >= c[i] - 1){
			k -= (c[i] - 1);
			answer ++;
		}
	}
	cout << answer << endl;
}