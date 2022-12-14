#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int m = 200000 + 10;

bool notprime[m + 10];

vector <int> primes;

void Sieve(){
	for (int i = 2; i <= m; i++){
		if (!notprime[i]){
			primes.push_back(i);
			for (int j = i + i; j <= m; j += i){
				notprime[j] = 1;
			}
		}
	}
}

bitset <m> bs[100];

int gn[m];

int main(){
	ios_base::sync_with_stdio(false);
	Sieve();
	int Q = primes.size();
	for (int i = 0; i < Q; i++){
		for (int j = i; j < Q; j++){
			if (1ll * primes[i] * primes[j] >= m)
				break;
			primes.push_back(primes[i] * primes[j]);
		}
	}
	bitset <m> ps; // primes and semi primes
	for (auto it : primes)
		ps[it] = 1;

	int n, f;
	cin >> n >> f;
	ps[f] = 0;
	bs[0] = ps;
	for (int i = 1; i < m; i++){
		while (bs[gn[i]][i] == 1)
			gn[i] ++;
		bs[gn[i]] |= (ps << i);
	}

	int answer = 0;
	for (int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		int fi = b - a - 1, se = c - b - 1;
		answer ^= gn[fi];
		answer ^= gn[se];
	}
	if (!answer)
		cout << "Bob \nAlice \n";
	else
		cout << "Alice \nBob \n";
}