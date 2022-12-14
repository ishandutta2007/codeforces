#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
const int maxn = 5e3 + 5;
const int inf = (int)1e9;
int A[maxn][maxn], a[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		A[i][i] = a[i];
		A[i][i + 1] = (a[i] ^ a[i + 1]);
	}
	for (int len = 2; len < n; len ++){
		for (int i = 1; i <= n - len; i++){
			int j = i + len;
			A[i][j] = (A[i][j - 1] ^ A[i + 1][j]);
		}
	}
	for (int len = 1; len < n; len ++){
		for (int i = 1; i <= n - len; i++){
			int j = i + len;
			A[i][j] = max (A[i + 1][j], max (A[i][j - 1], A[i][j]));
		}
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		int l, r;
		cin >> l >> r;
		cout << A[l][r] << "\n";
	}
}