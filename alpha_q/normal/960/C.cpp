#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll x, d;
vector <ll> v;

int main() {
  cin >> x >> d;
  for (int i = 1; i; ++i) {
  	ll y = x + i;
  	if (__builtin_popcount(y) > i) {
  		continue;
  	}
  	if (y & 1) {
  		continue;
  	}
  	int n = 0;
  	priority_queue <int> pq;
  	for (int j = 1; j < 31; ++j) {
  		if (y & 1LL << j) {
  			pq.push(j);
  		}
  	}
  	while (pq.size() < i) {
  		int z = pq.top();
  		pq.pop();
  		pq.push(z - 1);
  		pq.push(z - 1);
  	}
  	ll at = 1;
  	while (!pq.empty()) {
  		n += pq.top();
  		for (int j = 0; j < pq.top(); ++j) {
  			v.push_back(at);
  		}
  		at += d;
  		pq.pop();
  	}
  	assert(n <= 10000);
  	cout << n << '\n';
  	for (int j = 0; j < n; ++j) {
  		cout << v[j] << " ";
  	}
  	cout << '\n';
  	return 0;
  }
  cout << "-1\n";
  return 0;
}