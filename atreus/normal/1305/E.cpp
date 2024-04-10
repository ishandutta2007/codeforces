#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int p = 0, cnt = 0;
	while (p < n and cnt < m){
		p ++;
		cnt += (p - 1) / 2;
	}
	if (p == n and cnt < m)
		return cout << -1 << endl, 0;
	int N = p;
	int t = p;
	while (cnt > m){
		cnt -= (t - 1) / 2;
		p ++;
		t --;
		cnt += (t - 1) / 2;
	}
	if (N >= 1){
		for (int i = 1; i <= N - 1; i++)
			cout << i << " ";
		cout << p << " ";
	}
	for (int i = 1; i <= n - N; i++)
		cout << 100000000 + 1ll * i * (p + 1) << " ";
	cout << endl;
}