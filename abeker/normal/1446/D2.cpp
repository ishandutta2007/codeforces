#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int SQRT = 400;

int N;
int a[MAXN];
int freq[MAXN];
int largest;

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

void change(int x, int v) {
  freq[a[x]] += v;
}

int calc(int val) {
  vector <int> left(2 * N + 1, N + 1);
  vector <int> right(2 * N + 1, -1);
  left[N] = right[N] = 0;
  int pref = N;
  for (int i = 1; i <= N; i++) {
    if (a[i] == largest)
      pref--;
    else if (a[i] == val)
      pref++;
    left[pref] = min(left[pref], i);
    right[pref] = max(right[pref], i);
  }
  int res = 0;
  for (int i = 0; i <= 2 * N; i++)
    res = max(res, right[i] - left[i]);
  return res;
}

int solve() {
  for (int i = 1; i <= N; i++)
    change(i, 1);
  int ans = 0;
  largest = max_element(freq + 1, freq + N + 1) - freq;  
  for (int i = 1; i <= N; i++) 
    if (i != largest && freq[i] > SQRT) 
      ans = max(ans, calc(i));
  for (int i = 1; i <= N; i++)
    change(i, -1);
  a[0] = largest;
  for (int i = 1; i <= N; i++) 
    if (a[i - 1] == largest) {
      int maks = 0;
      vector <int> todo;
      for (int j = i; j <= N && freq[largest] <= SQRT; j++) {
        change(j, 1);
        todo.push_back(j);
        if (a[j] != largest)
          maks = max(maks, freq[a[j]]);
        if (maks >= freq[largest])
          ans = max(ans, j - i + 1);
      }
      for (auto it : todo)
        change(it, -1);
    }
  return ans;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}