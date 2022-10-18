#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int64_t, int64_t> num[30];
int N, K, Ff[20], Ss[20], f, s;
int64_t S, fact[20], ans;
unordered_set<int64_t> sum;
void First(int pos, int k, int64_t currSum) {
  if (k > K || currSum > S) return;
  if (pos == f) {
    num[k][currSum]++;
    sum.insert(currSum);
    return;
  }
  First(pos + 1, k, currSum);
  First(pos + 1, k, currSum + Ff[pos]);
  if (Ff[pos] <= 18) First(pos + 1, k + 1, currSum + fact[Ff[pos]]);
}
void Second(int pos, int k, int64_t currSum) {
  if (k > K || currSum > S) return;
  if (pos == s) {
    ans += num[K - k][S - currSum];
    return;
  }
  Second(pos + 1, k, currSum);
  Second(pos + 1, k, currSum + Ss[pos]);
  if (Ss[pos] <= 18) Second(pos + 1, k + 1, currSum + fact[Ss[pos]]);
}

int main() {
  fact[0] = 1;
  for (int i = 1; i <= 18; i++) fact[i] = fact[i - 1] * i;
  cin >> N >> K >> S;
  f = N / 2;
  s = N - f;
  for (int i = 0; i < f; i++) cin >> Ff[i];
  for (int i = 0; i < s; i++) cin >> Ss[i];
  First(0, 0, 0);
  for (auto &it : sum)
    for (int k = 1; k <= K; k++) num[k][it] += num[k - 1][it];
  Second(0, 0, 0);
  cout << ans << endl;
  return 0;
}