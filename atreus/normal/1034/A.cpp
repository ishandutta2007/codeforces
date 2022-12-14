#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e7 + 10;

int a[maxn], mpf[maxn], mp[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		x = gcd(x, a[i]);
	}
	for (int i = 2; i < maxn; i++)
		mpf[i] = i;
	for (int i = 2; 1ll * i * i < maxn; i++){
		if (mpf[i] != i)
			continue;
		for (int j = i; j < maxn; j += i)
			mpf[j] = i;
	}
	for (int i = 0; i < n; i++){
		a[i] /= x;
		while (a[i] > 1){
			int x = mpf[a[i]];
			mp[x] ++;
			while (mpf[a[i]] == x)
				a[i] /= x;
		}
	}
	int answer = n;
	for (int j = 2; j < maxn; j++)
		answer = min(answer, n - mp[j]);
	if (answer == n)
		answer = -1;
	cout << answer << endl;
}