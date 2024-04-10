#include <bits/stdc++.h>

using namespace std;
using lint = long long;

const int N_ = int(2.1e5);
int N;
lint R;
lint L[N_], T[N_];

void wrong() {
  puts("-1");
  exit(0);
}

lint ans;
vector<lint> pos;
const int SZ = 100000;


int main() {
  scanf("%d%lld", &N, &R);
  for(int i = 1; i <= N; i++) {
    scanf("%lld", &L[i]);
  }
  for(int i = 1; i <= N; i++) {
    scanf("%lld", &T[i]);
  }

  for(int i = 1; i <= N; i++) {
    if(T[i] < L[i]) {
      wrong();
    }
  }

  lint x = 0;
  lint t = 0;
  for(int i = 1; i <= N; i++) {
    if(x >= L[i]) {
      x -= L[i];
      t += L[i];
    }else {
      L[i] -= x; T[i] -= x; t += x; x = 0;
      
      // s * 2 + (L[i] - s) * 1 = T[i]
      // s = T[i] - L[i]
      if(L[i] * 2 > T[i]) {
        lint u = 2 * L[i] - T[i];
        ans += (u - 1) / R + 1;
        if(ans <= SZ) {
          for(lint y = t + T[i] - u; y < t + T[i]; y += R) {
            pos.push_back(y);
          }
        }
        x = (R - u % R) % R;
        t += T[i];
      }else {
        t += 2 * L[i];
      }
    }
  }

  printf("%lld\n", ans);
  if(ans <= SZ) {
    for(lint y : pos) printf("%lld ", y);
    puts("");
  }
  return 0;
}