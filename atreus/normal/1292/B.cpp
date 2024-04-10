#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 100 + 5;

ll x[maxn], y[maxn];

ll dis(ll x1, ll y1, ll x2, ll y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> x[0] >> y[0];
	ll Ax, Ay, Bx, By;
	cin >> Ax >> Ay >> Bx >> By;
	ll xs, ys, t;
	cin >> xs >> ys >> t;
	int m = 0;
	for (int i = 1; ; i++){
		if (log2(x[i - 1]) + log2(Ax) >= 58)
			break;
		if (log2(y[i - 1]) + log2(Ay) >= 58)
			break;
		m ++;
		x[i] = x[i - 1] * Ax + Bx;
		y[i] = y[i - 1] * Ay + By;
	}
	int answer = 0;
	for (int i = 0; i <= m; i++){
		ll D = 0;
		for (int j = i; j <= m; j++){
			ll D = dis(x[i], y[i], x[j], y[j]);
			if (D + dis(xs, ys, x[i], y[i]) > t and D + dis(xs, ys, x[j], y[j]) > t)
				break;
			answer = max(answer, j - i + 1);
			D += dis(x[j], y[j], x[j + 1], y[j + 1]);
		}
	}
	cout << answer << endl;
}