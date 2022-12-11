#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

vector<int> decomp(int v) {
	int d = 2;
	vector<int> res;
	while(d * d <= v) {
		while(v % d == 0) {
			v /= d;
			if(res.empty() || res.back() != d)
				res.push_back(d);
		}
		d++;
	}
	if(v != 1)
		res.push_back(v);
	return res;
}

int p2mod(int v) {
	if(v == 0)
		return 1;
	int div2 = p2mod(v / 2);
	int sq = ((long long)div2 * (long long)div2) % MOD;
	if(v % 2 == 1)
		sq = (sq * 2) % MOD;
	return sq;
}

int main() {
	int x, y;
	cin >> x >> y;
	
	if(y % x != 0) {
		cout << 0 << endl;
		return 0;
	}
	
	y /= x;
	x = 1;
	
	vector<int> primes = decomp(y);
	
	int nbCombis = 0;
	for(int mask = 0;mask < (1 << (int)primes.size());mask++) {
		bitset<32> m(mask);
		int diviseur = 1;
		for(int i = 0;i < (int)primes.size();i++) {
			if(m[i] == 1) {
				diviseur *= primes[i];
			}
		}
		
		int nbUns = m.count();
		
		if(nbUns % 2 == 0)
			nbCombis += p2mod(y / diviseur - 1);
		else
			nbCombis -= p2mod(y / diviseur - 1);
		nbCombis = ((nbCombis % MOD) + MOD) % MOD;
	}
	
	cout << nbCombis << endl;
	
	return 0;
}