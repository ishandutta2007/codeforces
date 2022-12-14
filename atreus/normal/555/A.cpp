/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	ll answer = n - k + n - 1;
	for (int i = 1; i <= k; i++){
		int m;
		cin >> m;
		for (int j = 1; j <= m; j++)
			cin >> a[j];
		if (a[1] == 1){
			if (m == 1 or a[2] != 2)
				continue;
			for (int k = 2; k <= m + 1; k++){
				if (a[k] != a[k - 1] + 1)
					break;
				answer -= 2;
			}
		}
	}
	cout << answer << endl;
}