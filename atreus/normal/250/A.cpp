#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int d = 0, cnt = 0;
	vector<int> ops;
	for (int i = 1; i <= n; i++){
		d ++;
		int x;
		cin >> x;
		if (cnt == 2 and x < 0){
			ops.push_back(d-1);
			cnt = 1;
			d = 1;
			continue;
		}
		if (x < 0)
			cnt ++;
	}
	ops.push_back(d);
	cout << ops.size() << endl;
	for (auto it : ops)
		cout << it << " ";
	cout << endl;
}