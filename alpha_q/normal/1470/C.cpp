
#include <bits/stdc++.h>
 
using namespace std;
 
int n, k, rep;
 
int ask (int pos) {
  int rep;
  pos %= n; pos += n; pos %= n;
  cout << "? " << pos + 1 << endl;
  cin >> rep; return rep;
}
 
void answer (int pos) {
  pos %= n; pos += n; pos %= n;
  cout << "! " << pos + 1 << endl;
  exit(0);  
}
 
int main() {
  mt19937 rng(69);
  cin >> n >> k;
  for (int it = 0; it < 169; ++it) {
    rep = ask(0);
  }
  int lo = -1, hi = -1;
  while (lo == -1 or hi == -1) {
  	int cur = rng() % n, yo = ask(cur);
  	if (yo < k) lo = cur;
  	if (yo > k) hi = cur;
  }
  if (lo > hi) hi += n;
  while (lo < hi) {
  	int mid = lo + hi + 1 >> 1;
  	if (ask(mid) <= k) lo = mid;
  	else hi = mid - 1;
  }
  answer(lo);
  return 0;
}