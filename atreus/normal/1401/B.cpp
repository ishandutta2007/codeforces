#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

int x[5], y[4];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		cin >> x[0] >> x[1] >> x[2] >> y[0] >> y[1] >> y[2];
		int tmp = min(x[2], y[1]);
		int answer = 2*tmp;
		x[2] -= tmp, y[1] -= tmp;
		tmp = min(x[0]+x[2], y[2]);
		y[2] -= tmp;
		tmp = min(y[0]+y[1], x[1]);
		x[1] -= tmp;
		tmp = min(x[1], y[2]);
		answer -= 2*tmp;
		cout << answer << '\n';
	}
}