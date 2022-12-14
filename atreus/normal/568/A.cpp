/**
 *    author:  Atreus
 *    created: 21.01.2019
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 2e5 + 10;
int rub[maxn], pri[maxn];

bool palindromic(int x){
	int cop = x;
	int y = 0;
	while (cop){
		y *= 10;
		y += cop % 10;
		cop /= 10;
	}
	return x == y;
}

bool isprime(int x){
	if (x == 1)
		return 0;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	int p, q;
	cin >> p >> q;
	int n = maxn - 10;
	for (int i = 1; i <= n; i++){
		rub[i] = rub[i - 1] + palindromic(i);
		pri[i] = pri[i - 1] + isprime(i);
	}
	for (int i = n; i >= 1; i--){
		if (pri[i] <= 1. * p * rub[i] / q)
			return cout << i << endl, 0;
	}
	cout << "Palindromic tree is better than splay tree" << endl;
}