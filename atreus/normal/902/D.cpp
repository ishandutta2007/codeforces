#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 200;
int v[maxn][maxn];

int main () {
	int n;
	cin >> n;
	v[0][0] = 1;
	v[1][1] = 1;
	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0){
				v[i][j] = v[i - 2][j];
				continue;
			}
			v[i][j] = v[i - 1][j - 1];
			v[i][j] += v[i - 2][j];
			v[i][j] %= 2;
		}
	}
	cout << n << endl;
	for (int i = 0; i <= n; i++)
		cout << v[n][i] << " ";
	cout << endl << n - 1 << endl;
	for (int i = 0; i < n; i++)
		cout << v[n - 1][i] << " ";
}