#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, cnt[N];

int main() {
  scanf("%d", &n);
  ++cnt[0];
  int ans = 1;
  for (int i = 1; i <= n; ++i) {
  	int t;
  	scanf("%d", &t);
  	if (cnt[t]) {
  		--cnt[t];
  	} else {
  		++ans;
  	}
  	++cnt[i];
  }
  printf("%d\n", ans);
  return 0;
}