#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll inf = 1e18;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int a, b;
		cin >> a >> b;
		if (a == 1){
			if (b == 1)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if (a <= 3){
			if (b <= 3)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
			cout << "YES\n";
	}
}