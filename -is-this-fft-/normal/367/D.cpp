#include <iostream>

using namespace std;

const int MAX_M = 20;
const int MAX_N = 100005;

int arr [MAX_N];
int cnt [MAX_N];
bool marked [(1 << MAX_M) + 5];

void mark_subs (int bits) {
  if (marked[bits]) {
    return;
  }
  marked[bits] = 1;
  for (int i = 0; i < MAX_M; i++) {
    if (bits & 1 << i) {
      mark_subs(bits - (1 << i));
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  
  int length, colorc, D;
  cin >> length >> colorc >> D;

  for (int i = 0; i < colorc; i++) {
    int cnt;
    cin >> cnt;

    for (int j = 0; j < cnt; j++) {
      int x;
      cin >> x;

      arr[x] = i;
    }
  }
  
  for (int i = 1; i <= length; i++) {
    if (i - D > 0) {
      cnt[arr[i - D]]--;
    }
    cnt[arr[i]]++;
    if (i >= D) {
      int cur_bits = 0;
      for (int j = 0; j < colorc; j++) {
        cur_bits <<= 1;
        if (cnt[j] == 0) {
          cur_bits++;
        }
      }
      mark_subs(cur_bits);
    }
  }

  int ans = 100;
  for (int i = 0; i < 1 << colorc; i++) {
    if (!marked[i]) {
      ans = min(ans, __builtin_popcount(i));
    }
  }
  cout << ans << endl;
}