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

	bool ar[3][3];
	ms(ar);

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			int a;
			cin >> a;
			if(a % 2){
				ar[i][j] = !ar[i][j];
				if(i != 0)
					ar[i - 1][j] = !ar[i - 1][j];
				if(j != 0)
					ar[i][j - 1] = !ar[i][j - 1];
				if(i != 2)
					ar[i + 1][j] = !ar[i + 1][j];
				if(j != 2)
					ar[i][j + 1] = !ar[i][j + 1];
			}

		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			cout << !ar[i][j];
		cout << endl;
	}

}