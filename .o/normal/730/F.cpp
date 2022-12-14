#include <bits/stdc++.h>

using namespace std;

const int N_ = 5050;
const int B_ = 10050;

int B, N;
int A[N_];
int S[N_];

int tb[N_][B_];
short revx[N_][B_], revj[N_][B_];
int ans[N_];

int main() {
  scanf("%d%d", &N, &B);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    S[i] = S[i-1] + A[i];
  }

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j < B_; j++) {
      revx[i][j] = revj[i][j] = -1;
      tb[i][j] = 1e9;
    }
  }

  {
    int mil = 0;
    tb[0][0] = 0;

    for(int i = 1; i <= N; i++) {
      for(int j = 0; j * 10 <= S[i-1]; j++) {
        // B+j 
        int max_bonus = min(A[i] / 2, B + j - (S[i-1] - tb[i-1][j]));
        for(int x = 0; x <= max_bonus; x++) {
          int nxt_j = j + (A[i] - x) / 10;
          if(tb[i][nxt_j] > tb[i-1][j] + (A[i] - x)) {
            tb[i][nxt_j] = tb[i-1][j] + A[i] - x;
            revx[i][nxt_j] = x;
            revj[i][nxt_j] = j;
          }
        }
      }
    }
  }

  {
    int j = min_element(tb[N], tb[N]+B_) - tb[N];
    printf("%d\n", tb[N][j]);
    for(int i = N; i > 0; ) {
      assert(revx[i][j] >= 0);
      ans[i] = revx[i][j];
      j = revj[i--][j];
    }

    for(int i = 1; i <= N; i++) {
      printf("%d ", ans[i]);
    }
    puts("");
  }

  return 0;
}