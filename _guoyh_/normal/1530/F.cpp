# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 31607;
const int MAXN = 21;
int n, U;
ll a[MAXN][MAXN];
ll b[MAXN][1 << MAXN];
ll pwr(ll x, ll y){
	x %= P;
	y = (y % (P - 1) + (P - 1)) % (P - 1);
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int p[1 << MAXN];
ll work(int s){
	ll ans0 = 1, ans1 = 1, ans2 = 1, ans3 = 1;
	for (int i = 0; i < n; i++){
		ans0 = ans0 * (1 - b[i][U ^ s]) % P * b[i][s] % P;
		ans1 = ans1 * (1 - b[i][U ^ (s | (1 << i))]) % P * b[i][s | (1 << i)] % P;
		ans2 = ans2 * (1 - b[i][U ^ (s | (1 << (n - i - 1)))]) % P * b[i][s | (1 << (n - i - 1))] % P;
		ans3 = ans3 * (1 - b[i][U ^ (s | (1 << i) | (1 << (n - i - 1)))]) % P * b[i][s | (1 << i) | (1 << (n - i - 1))] % P;
		// cout << "ans: \n";
		// prt(ans0);
		// prt(ans1);
		// prt(ans2);
		// prt(ans3);
	}
	return (ans0 - ans1 - ans2 + ans3) % P;
}
int main(){
	cin >> n;
	U = (1 << n) - 1;
	for (int i = 0; i < n; i++){
		b[i][0] = 1;
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			a[i][j] = a[i][j] * pwr(10000, -1) % P;
			b[i][1 << j] = a[i][j];
		}
		for (int j = 1; j < (1 << n); j++) b[i][j] = b[i][j ^ (j & (-j))] * b[i][j & (-j)] % P;
	}
	ll ans = 0;
	p[0] = 1;
	for (int i = 0; i < (1 << n); i++){
		if (i > 0) p[i] = -p[i ^ (i & (-i))];
		ans = (ans + p[i] * work(i)) % P;
		// cout << "work " << i << ' ';
		// prt(work(i));
	}
	ans = (1 - ans) % P;
	cout << (ans + P) % P << '\n';
	return 0;
}