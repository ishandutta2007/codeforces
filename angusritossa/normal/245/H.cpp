#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 5010
char s[MAXN];
bool is_palindrome[MAXN][MAXN];
int dp[MAXN][MAXN], N, Q;
int main() {
  scanf(" %s", s+1); // str+1 1-indexes the string
  N = strlen(s+1);
  // Calculate is_palindrome
  // We need to process substrings in order of length
  for (int len = 0; len < N; len++) {
    for (int i = 1; i <= N-len; i++) {
      int j = i+len;
      if (!len) is_palindrome[i][i] = true;
      else if (len == 1) is_palindrome[i][j] = s[i] == s[j];
      else is_palindrome[i][j] = s[i] == s[j] && is_palindrome[i+1][j-1];
    }
  }
  // Calculate dp
  // We need to process substrings in order of length
  for (int len = 0; len < N; len++) {
    for (int i = 1; i <= N-len; i++) {
      int j = i+len;
      dp[i][j] = is_palindrome[i][j] + dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
    }
  }

  // Print answers to queries
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", dp[l][r]);
  }
}