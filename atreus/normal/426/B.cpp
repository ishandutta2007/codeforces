#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
string s[200];

bool ismir(int r){
	int mx = 2 * r + 1;
	for (int i = 1; i <= r; i ++)
		if (s[i] != s[mx - i])
			return false;
	return true;
}

int main (){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < m; j++){
			int b;
			cin >> b;
			s[i] += (b + '0');
		}
	}
	if (n % 2 == 1)
		return cout << n << endl, 0;
	int r = n / 2, ans = n;
	while (r >= 1){
		if (ismir(r)){
			ans = r;
			if (r % 2 == 1)
				break;
			r /= 2;
		}
		else
			break;
	}
	cout << ans << endl;
}