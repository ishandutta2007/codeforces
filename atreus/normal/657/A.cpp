#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 20 + 5;

int main(){
	ios_base::sync_with_stdio(false);
	int n, d, h;
	cin >> n >> d >> h;
	if (2 * h < d)
		return cout << -1 << endl, 0;
	if (d == 1){
		if (n > 2)
			return cout << -1 << endl, 0;
		return cout << 1 << " " << 2 << endl, 0;
	}
	int newint = 1;
	for (int i = 1; i <= h; i++){
		cout << newint << " " << newint + 1 << endl;
		newint ++;
	}
	if (h == d){
		int id = newint - 1;
		newint ++;
		while (newint <= n){
			cout << id << " " << newint ++ << endl;
		}
		return 0;
	}
	newint ++;
	cout << 1 << " " << newint << endl;
	for (int i = 1; i <= d - h - 1; i++){
		cout << newint << " " << newint + 1 << endl;
		newint ++;
	}
	newint ++;
	int id = h;
	while (newint <= n){
		cout << id << " " << newint ++ << endl;
	}
}