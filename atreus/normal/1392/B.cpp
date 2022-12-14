#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		ll n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		ll mxm = *max_element(a+1, a+n+1);
		for (int i = 1; i <= n; i++)
			a[i] = mxm - a[i];
		k --;
		mxm = *max_element(a+1, a+n+1);
		k %= 2;
		if (k == 1)
			for (int i = 1; i <= n; i++)
				a[i] = mxm - a[i];
		for (int i = 1; i <= n; i++)
			cout << a[i] << " \n"[i == n];
	}
}