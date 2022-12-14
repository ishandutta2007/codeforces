#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 5000 + 10;
const ll inf = 1e18;

int a[maxn], par[maxn], l[maxn], r[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= q; i++){
		cin >> l[i] >> r[i];
		for (int j = l[i]; j <= r[i]; j++)
			a[j] ++;
	}
	int answer = 0;
	for (int i = 1; i <= q; i++){
		for (int j = l[i]; j <= r[i]; j++)
			a[j] --;
		int sum = 0;
		for (int k = 1; k <= n; k++){
			par[k] = par[k - 1] + (a[k] == 1);
			sum += (a[k] > 0);
		}
		for (int j = 1; j <= q; j++){
			if (j == i)
				continue;
			answer = max(answer, sum - par[r[j]] + par[l[j] - 1]);
		}
		for (int j = l[i]; j <= r[i]; j++)
			a[j] ++;
	}
	cout << answer << endl;
}