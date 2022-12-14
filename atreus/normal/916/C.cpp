#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const int inf = 1e8;

bool isprime(ll p){
	if (p == 1)
		return false;
	for (int i = 2; i <= sqrt(p); i++)
		if (p % i == 0)
			return false;
	return true;
}

int main(){
	int n, m;
	cin >> n >> m;
	ll k = 0;
	for (int i = 1; i < n - 1; i++){
		m --;
		k += 2;
	}
	ll l = k;
	while (true){
		k ++;
		if (isprime(k)){
			m--;
			break;
		}
	}
	cout << k << " " << k << endl;
	for (int i = 1; i < n - 1; i++){
		cout << i << " " << i + 1 << " " << 2 << endl;
	}
	cout << n - 1 << " " << n << " " << k - l << endl;
	for (int len = 2; len < n; len++){
		for (int i = 1; i <= n - len; i++){
			if (m == 0)
				return 0;
			cout << i << " " << i + len << " " << inf << endl;
			m --;
		}
	}
}