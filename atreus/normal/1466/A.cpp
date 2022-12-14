#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 2e6 + 10;
const ll mod = 1e9 + 7;

int a[120];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		set<int> S;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				S.insert(a[j]-a[i]);
		cout << S.size() << '\n';
	}
}