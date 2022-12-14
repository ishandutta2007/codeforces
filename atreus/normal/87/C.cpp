/**
 *    author:  Atreus
 *    created: 24.01.2019 15:30
 **/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 10;
int par[maxn], gn[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	gn[1] = 0;
	gn[2] = 0;
	for (int i = 3; i <= n; i++){
		bitset<20> bs;
		for (int j = 2; j * (j + 1) / 2 <= i; j++){
			int x = i - j * (j + 1) / 2;
			if (x % j != 0)
				continue;
			x /= j;
			// x + 1, x + 2, x + 3, ..., x + j = i
			if ((par[x + j] ^ par[x]) < 20)
				bs[par[x + j] ^ par[x]] = 1;
		}
		for (int j = 0; ; j++){
			if (bs[j] == 0){
				gn[i] = j;
				break;
			}
		}
		par[i] = par[i - 1] ^ gn[i];
	}
	if (gn[n] == 0)
		return cout << -1 << endl, 0;
	for (int j = 2; j * (j + 1) / 2 <= n; j++){
		int x = n - j * (j + 1) / 2;
		if (x % j != 0)
			continue;
		x /= j;
		if ((par[x + j] ^ par[x]) == 0)
			return cout << j << endl, 0;
	}
}