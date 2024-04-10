/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

bool prime(int g){
	if (g == 1)
		return false;
	for(int i = 2; i <= sqrt(g); i++){
		if (g % i == 0)
			return false;
	}
	return true;
}

int nextPrime(int g){
	if (prime(g))
		return g;
	else
		return nextPrime(g + 1);
}



int main(){

	int prime[100000];
	for(int i = 1; i <= 100000; i++){
		prime[i] = nextPrime(i);
	}
	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for(int i = 0; i < n; i++)
		a[i] = 0;
	for(int j = 0; j < m; j++)
		b[j] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int c;
			cin >> c;
			int d = prime[c];
			//cout << " c = " << c << " d = " << d << " i = " << i << " j = " << j << endl;
			a[i] += d - c;
			b[j] += d - c;
		}
	}

	int ans = a[0];

	for(int i = 0; i < n; i++){
		ans = min(ans, a[i]);
		//cout << a[i] << " i = " << i << endl;
	}
	for(int j = 0; j < m; j++){
		ans = min(ans, b[j]);
		//cout << b[j] << " j = " << j << endl;
	}

	cout << ans;
}