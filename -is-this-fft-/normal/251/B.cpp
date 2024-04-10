#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

void success () {
  cout << "YES" << endl;
  exit(0);
}

vector<int> apply (const vector<int> &P, const vector<int> &Q) {
  int n = P.size();
  vector<int> ans (n);
  for (int i = 0; i < n; i++) {
    ans[i] = P[Q[i]];
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, K;
  cin >> n >> K;

  vector<int> Q (n);
  vector<int> iQ (n);
  for (int i = 0; i < n; i++) {
    cin >> Q[i];
    Q[i]--;

    iQ[Q[i]] = i;
  }

  vector<int> S (n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
    S[i]--;
  }

  vector<int> iota (n);
  for (int i = 0; i < n; i++) {
    iota[i] = i;
  }

  if (iota == S) {
    failure();
  }

  int pmatch = K + 1;
  vector<int> pos = iota;
  for (int i = 1; i <= K; i++) {
    pos = apply(pos, Q);
    if (pos == S) {
      pmatch = i;
      break;
    }
  }

  if (1 < pmatch && pmatch <= K && pmatch % 2 == K % 2) {
    success();
  }

  int nmatch = K + 1;
  vector<int> neg = iota;
  for (int i = 1; i <= K; i++) {
    neg = apply(neg, iQ);
    if (neg == S) {
      nmatch = i;
      break;
    }
  }

  if (1 < nmatch && nmatch <= K && nmatch % 2 == K % 2) {
    success();
  }

  if (pmatch == 1 && pmatch % 2 == K % 2 && nmatch > 1) {
    success();
  }

  if (nmatch == 1 && nmatch % 2 == K % 2 && pmatch > 1) {
    success();
  }

  if (pmatch == 1 && nmatch == 1 && K == 1) {
    success();
  }

  failure();
}