#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 or y1 == y2)
			cout << abs(x2-x1) + abs(y2-y1) << '\n';
		else
			cout << abs(x2-x1) + abs(y2-y1) + 2 << '\n';
	}
}