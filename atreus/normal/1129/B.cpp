// In the name of GOD
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5000 + 100;

void solve(int k, int n){
	int x = k % n;
	int mx = n - x;
	int p = (mx + k) / n;
	while (p >= mx){
		mx += n;
		p ++;
	}
	cout << n << endl;
	for (int i = 0; i < n - 2; i++)
		cout << 0 << " ";
	cout << p - mx << " " << mx << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	int k;
	cin >> k;
	solve(k, 2000);
}