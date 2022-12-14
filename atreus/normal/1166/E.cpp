#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e4 + 10;

int s[55], a[55][maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++){
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++)
			cin >> a[i][j];
		sort(a[i] + 1, a[i] + s[i] + 1);
	}
	for (int i = 1; i <= m; i++){
		for (int j = i + 1; j <= m; j++){
			bool common = 0;
			int ptr = 1;
			for (int k = 1; k <= s[i]; k++){
				while (ptr < s[j] and a[j][ptr] < a[i][k])
					ptr ++;
				common |= (a[i][k] == a[j][ptr]);
			}
			if (common == 0)
				return cout << "impossible" << endl, 0;
		}
	}
	cout << "possible" << endl;
}