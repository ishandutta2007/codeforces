#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18 + 1;

ll f[100001];
int q;
string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string z  = "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	f[0] = 75;
	for(int i = 1; i <= 100000; i++) f[i] = min(inf, 2 * f[i - 1] + 68);
	cin >> q;
	while(q--) {
		int n; ll k;
		cin >> n >> k;
		if(f[n] < k) { cout << '.'; continue; }
		for(int i = n; i >= 0; i--)
			if(i == 0) { cout << f0[k - 1]; break; }
			else {
				if(k <= 34) { cout << z[k - 1]; break; }
				else {
					k -= 34;
					if(k <= f[i - 1]) continue;
					k -= f[i - 1];
					if(k <= 32) { cout << z[33 + k]; break; }
					k -= 32;
					if(k <= f[i - 1]) continue;
					k -= f[i - 1];
					cout << z[65 + k]; break;
				}
			}
	}
}