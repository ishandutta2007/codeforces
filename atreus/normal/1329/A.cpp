#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;

int p[maxn], l[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	for (int i = 1; i <= m; i++){
		cin >> l[i];
		sum += l[i];
	}
	if (sum < n)
		return cout << -1 << endl, 0;
	int idx = 1, k = n;
	for (int i = 1; i <= n; i++){
		if (l[idx] > k)
			return cout << -1 << endl, 0;
		p[idx] = i;
		sum -= l[idx];
		k --;
		if (k > sum){
			i += k - sum;
			k -= (k - sum);
		}
		idx ++;
	}
	for (int i = 1; i <= m; i++)
		cout << p[i] << " \n"[i == m];
}