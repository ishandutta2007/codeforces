#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;

ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			a[i] += a[i - 1];
		ll sum = a[n];
		ll mnm = 0;
		bool flag = 1;
		for (int i = 1; i <= n; i++){
			if (i == n and mnm == 0)
				break;
			if (a[i] - a[mnm] >= sum)
				flag = 0;
			if (a[i] <= a[mnm])
				mnm = i;
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}