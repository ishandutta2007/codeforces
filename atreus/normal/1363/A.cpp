#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 300 + 10;
const int mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n, x;
		cin >> n >> x;
		int a = 0, b = 0;
		for (int i = 1; i <= n; i++){
			int y;
			cin >> y;
			if (y & 1)
				a ++;
			else
				b ++;
		}
		if (a == 0){
			cout << "NO\n";
			continue;
		}
		x --;
		a --;
		while (x){
			if (x > 1 and a > 1)
				x -= 2, a -= 2;
			else if (b > 0)
				x -= 1, b -= 1;
			else
				break;
		}
		cout << (x == 0 ? "YES\n" : "NO\n");
	}
}