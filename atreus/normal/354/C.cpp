#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<long double> point;

const int maxn = 2e6 + 10;

int a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[x] ++;
	}
	int m = 1000*1000;
	for (int i = 1; i <= 2*m; i++)
		a[i] += a[i-1];
	for (int i = m; i >= 1; i--){
		int cnt = 0;
		for (int j = i; j <= m; j += i){
			int nex = min(j+k, j+i-1);
			cnt += a[nex] - a[j-1];
		}
		if (cnt == n)
			return cout << i << endl, 0;
	}
}