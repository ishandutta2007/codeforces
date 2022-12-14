#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 50;

int a[20];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		ll x;
		cin >> x;
		if (x <= 14){
			cout << "NO\n";
			continue;
		}
		x %= 14;
		x += 14;
		if (x >= 15 and x <= 20)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}