/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
//#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

const int MAX = 100000;

int main() {

	int n, m, k;
	cin >> n >> m >> k;

	ll ans = 0;

	int a[MAX + 1], b[MAX + 1];

	ms(a);
	ms(b);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[a[i]] = i;
	}

	for(int i = 0; i < m; i++){
		int c;
		cin >> c;
		ans += b[c] / k + 1;
		if(b[c] != 0){
			int g = c, e = a[b[c] - 1];
			b[a[b[c] - 1]]++;
			b[c]--;
			swap(a[b[g]], a[b[e]]);
		}
	}

	//for(int i = 0; i < n; i++){
	//	cout << a[i] <<  " ";
	//}

	cout << ans << endl;

}