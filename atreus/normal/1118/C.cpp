/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e3 + 10;
int a[25][25], num[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n * n; i++){
		int x;
		cin >> x;
		num[x] ++;
	}
	if (n % 2 == 0){
		int mx = 1000;
		for (int i = 1; i <= mx; i++)
			if (num[i] % 4 != 0)
				return cout << "No" << endl, 0;
		cout << "Yes" << endl;
		for (int i = 1; i <= n / 2; i++){
			for (int j = 1; j <= n / 2; j++){
				for (int k = 1; k <= mx; k++){
					if (num[k] != 0){
						num[k] -= 4;
						a[i][j] = k;
						a[i][n - j + 1] = k;
						a[n - i + 1][j] = k;
						a[n - i + 1][n - j + 1] = k;
						break;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		return 0;
	}
	int mx = 1000;
	int cnt = 0;
	for (int i = 1; i <= mx; i++){
		if (num[i] & 1){
			cnt ++;
			a[n / 2 + 1][n / 2 + 1] = i;
			num[i] --;
		}
	}
	if (cnt != 1)
		return cout << "No" << endl, 0;
	cnt = 0;
	for (int i = 1; i <= mx; i++)
		if (num[i] % 4 == 2)
			cnt ++;
	if (cnt > n - 1)
		return cout << "No" << endl, 0;

	for (int i = 1; i <= n / 2 + 1; i++){
		for (int j = 1; j <= n / 2 + 1; j++){
			if (i < n / 2 + 1 and j < n / 2 + 1){
				int k;
				for (k = 1; k <= mx; k++)
					if (num[k] >= 4)
						break;
				a[i][j] = k;
				a[n - i + 1][j] = k;
				a[i][n - j + 1] = k;
				a[n - i + 1][n - j + 1] = k;
				num[k] -= 4;
			}
			else if (i == n / 2 + 1 and j != n / 2 + 1){
				int k = 0;
				for (k = 1; k <= mx; k++)
					if (num[k] % 4 == 2)
						break;
				if (k == 1001)
					for (k = 1; k <= mx; k++)
						if (num[k] >= 4)
							break;
				a[i][j] = k;
				a[i][n - j + 1] = k;
				num[k] -= 2;
			}
			else if (i != n / 2 + 1 and j == n / 2 + 1){
				int k = 0;
				for (k = 1; k <= mx; k++)
					if (num[k] % 4 == 2)
						break;
				if (k == 1001)
					for (k = 1; k <= mx; k++)
						if (num[k] >= 4)
							break;		
				a[i][j] = k;
				a[n - i + 1][j] = k;
				num[k] -= 2;
			}
			else{
				continue;
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}