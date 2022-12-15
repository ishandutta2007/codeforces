#include <bits/stdc++.h>

using namespace std;
using lint = long long;

const int N_ = int(5.1e5);
int N, A[N_];
long long S[N_];

lint lower[N_], upper[N_];

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  sort(A+1, A+N+1, greater<int>());
  for(int i = 1; i <= N; i++) {
    S[i] = S[i-1] + A[i];
  }

  int parity = S[N] % 2;

  for(int i = 1; i <= N; i++) {
    int j = upper_bound(A+i+1, A+N+1, i, greater<int>()) - A;
    lower[i] = S[i] - (lint)i * (j - 2) - (S[N] - S[j-1]);

    int k = upper_bound(A+i, A+N+1, i, greater<int>()) - A;
    upper[i] = -S[i-1] + (lint)i * (k - 1) + (S[N] - S[k-1]);
  }

  for(int i = 1; i <= N; i++) {
    if(lower[i] > i) {
      lower[i] = 1e18;
    }
    lower[i] = max(lower[i], lower[i-1]);
  }

  upper[N+1] = 1e18;
  for(int i = N; i > 0; i--) {
    upper[i] = min(upper[i], upper[i+1]);
  }

  vector<lint> ans;

  for(int i = 0; i <= N; i++) {
    lint low = max(lower[i], (lint)A[i+1]);
    lint high = min(upper[i+1], (lint)(i == 0 ? N : (A[i] - 1)));
    for(lint x = low; x <= high; x++) {
      ans.push_back(x);
    }
  }

  sort(ans.begin(), ans.end());

  bool printed = false;
  for(lint x : ans) {
    if(x % 2 == parity) printf("%lld ", x), printed = true;
  }
  if(!printed) printf("-1");
  puts("");

  return 0;
}