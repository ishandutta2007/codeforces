/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("input.txt", "w", stdout);
#define ll long long
//#define x first
//#define y second
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	sync;

	//output;
	//cout << 100000 << endl;
	//for(int i = 1; i <= 3; i++){
	//	for(int j = i; j <= 100000; j++)
	//		cout << j << " ";
	//	cout << endl;
//	}

	//input;

	int n, m;
	cin >> n >> m;
	int ans = 0;
	while(n > 1 && m > 1){
		if (m > n)
			m -= 2, n -= 1;
		else
			n -= 2, m -= 1;
		ans++;
	}
	if(max(n, m) > 1 && min(n, m) > 0)
		ans++;
	cout << ans;

}