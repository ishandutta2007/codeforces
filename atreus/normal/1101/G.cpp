/**
 *    author:  Atreus
 *    created: 11.01.2019 18:45:32      
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int m = 0;

int a[maxn], par[maxn], b[33], lb[33];

void add(int x){
	for (int i = 0; i < m; i++)
		if ((1 << lb[i]) & x)
			x ^= b[i];
	if (x == 0)
		return;
	b[m] = x;
	lb[m] = log2(x & -x);
	for (int i = 0; i < m; i++)
		if ((1 << lb[m]) & b[i])
			b[i] ^= x;
	m ++;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		par[i] = a[i] ^ par[i - 1];
	}
	if (par[n] == 0)
		return cout << -1 << endl, 0;
	add(par[n]);
	for (int i = n - 1; i >= 1; i--)
		add(par[i]);
	cout << m << endl;
}