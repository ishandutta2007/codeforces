#include <bits/stdc++.h>
using namespace std;

vector<int> operator + (vector<int> a, vector<int> b) {
  for (auto x : b) {
    a.push_back(x);
  }
  return a;
}

bool query(vector<int> S) {
  static char buf[10];
  printf("? %d", (signed) S.size());
  for (auto x : S) {
    printf(" %d", x);
  }
  putchar('\n');
  fflush(stdout);
  scanf("%s", buf);
  return buf[0] == 'Y';
}

bool answer(int x) {
  static char buf[10];
  printf("! %d\n", x);
  fflush(stdout);
  scanf("%s", buf);
  return buf[1] == ')';
}

void split(vector<int> &A, vector<int> &B, int sz) {
  B.resize(sz);
  copy(A.begin(), A.begin() + sz, B.begin());
  A.erase(A.begin(), A.begin() + sz);
}

int n;

int main() {
  scanf("%d", &n);
  vector<int> S, T(n);
  for (int i = 0; i < n; i++) {
    T[i] = i + 1;
  }
  vector<int> S0, T0, nS, nT;
  int t = 0;
  while (S.size() + T.size() > 2) {
    t++;
    int ns = S.size(), nt = T.size();
    if (ns == 1) {
      split(S, S0, 1);
      split(T, T0, 0);
    } else if (ns == 3 && nt == 6) {
      split(S, S0, 1);
      split(T, T0, 2);
    } else {
      split(S, S0, ns >> 1);
      split(T, T0, nt >> 1);
    }
    if (query(S0 + T0)) {
      S = T;
      T = S0 + T0;
    } else {
      T = T + S;
      S = T0;
    }
//     cerr << "size = " << S.size() << " " << T.size() << " " << 1.0 * S.size() / T.size() << endl;
  }
  S = S + T;
//  cerr << "times = " << t << endl;
  !answer(S[0]) && answer(S[1]);
  return 0;
}