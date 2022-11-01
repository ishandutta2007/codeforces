#include <bits/stdc++.h> 

using namespace std;

int n, t, k, d;

int main (int argc, char const *argv[]) {
  cin >> n >> t >> k >> d;
  int one = t * ((n + k - 1)/k);
  int tot = 0, two;
  for (int i = 1; i <= 1000000; ++i) {
  	int now = k * (i/t);
  	if (i >= d) now += k * ((i - d)/t);
  	if (now >= n) {
  		two = i;
  		break;
  	}
  }
  // cout << one << " " << two  << endl;
  if (one <= two) puts("NO");
  else puts("YES");
  return 0;
}