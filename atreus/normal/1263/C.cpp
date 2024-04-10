#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e5 + 5;
 
map<string, bool> mp;
 
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		vector<int> a;
		int now = 1;
		while (now <= n){
			int lo = now, hi = n + 1;
			while (hi - lo > 1){
				int mid = (lo + hi) >> 1;
				if (n / mid == n / now)
					lo = mid;
				else
					hi = mid;
			}
			a.push_back(n / now);
			now = hi;
		}
		a.push_back(0);
		sort(a.begin(), a.end());
		cout << a.size() << endl;
		for (auto it : a)
			cout << it << " ";
		cout << endl;
	}
}