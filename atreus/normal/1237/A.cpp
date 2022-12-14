#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const int maxn = 5e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	bool pos = 0, neg = 0;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		if (x == 0){
			cout << x << '\n';
			continue;
		}
		if (x > 0){
			if (x % 2 == 0){
				cout << x / 2 << '\n';
				continue;
			}
			if (pos == 0)
				cout << x / 2 << '\n';
			else
				cout << (x + 1) / 2 << '\n';
			pos ^= 1;
		}
		else{
			if (abs(x) % 2 == 0){
				cout << x / 2 << '\n';
				continue;
			}
			if (neg == 0)
				cout << x / 2 << '\n';
			else
				cout << (x-1) / 2 << '\n';
			neg ^= 1;
		}
	}
}