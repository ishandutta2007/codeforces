#include <bits/stdc++.h> 

using namespace std;

const int M = 1010;
const int N = 1000010;
const int INF = 1e9 + 10;

set <int> s;
int n, k, a[M], b[M], u, v;
long long da[N + 2000], db[N + 2000];

int main (int argc, char const *argv[]) {
  scanf("%d %d", &n, &k);
  while (k--) {
  	int x; 
  	scanf("%d", &x);
  	x -= n;
  	if (s.count(x)) continue;
  	s.insert(x);
  	if (x == 0) {
  		puts("1");
  		return 0;
  	}
  	else if (x > 0) a[++u] = x;
  	else b[++v] = -x;
  }
  for (int i = 1; i < N; ++i) {
  	da[i] = INF;
  	for (int j = 1; j <= u; ++j) {
  		if (a[j] <= i) {
  			da[i] = min(da[i], da[i - a[j]] + 1);
  		}
  	}
  }
  for (int i = 1; i < N; ++i) {
  	db[i] = INF;
  	for (int j = 1; j <= v; ++j) {
  		if (b[j] <= i) {
  			db[i] = min(db[i], db[i - b[j]] + 1);
  		}
  	}
  }
  long long res = INF;
  for (int i = 1; i < N; ++i) {
  	res = min(res, da[i] + db[i]);
  }
  if (res >= INF) res = -1;
  cout << res << '\n';
  return 0;
}