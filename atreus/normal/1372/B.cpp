#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
const int maxn = 3e5 + 5;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		vector<int> dv;
		for (int i = 1; i * i <= n; i++){
			if (n % i == 0){
				dv.push_back(i);
				if (i * i != n)
					dv.push_back(n/i);
			}
		}
		int a = -1;
		ll lc = n;
		for (auto it : dv){
			if (it == n)
				continue;
			if (lcm(it, n-it) < lc){
				lc = lcm(it, n-it);
				a = it;
			}
		}
		cout << a << " " << n-a << '\n';
	}
}