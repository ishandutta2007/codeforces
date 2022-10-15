/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	int m, n;
	cin >> m >> n;

	int ar[m];
	ms(ar);

	while(n--){
		int a;
		cin >> a;
		for(int i = a; i <= m; i++)
			if(ar[i - 1] == 0)
				ar[i - 1] = a;
	}
	for(int i = 0; i < m; i++)
		cout << ar[i] << " ";
}