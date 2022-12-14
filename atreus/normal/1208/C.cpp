#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000 + 10;

int a[maxn][maxn];

int main(){
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i += 2){
		for (int j = 0; j < n; j += 2){
			a[i][j] = cnt ++;
			a[i][j+1] = cnt ++;
			a[i+1][j] = cnt ++;
			a[i+1][j+1] = cnt ++;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " \n"[j == n - 1];
}