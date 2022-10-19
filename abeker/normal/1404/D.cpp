#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int N;
int parity, same = -1;
vector <int> nums[MAXN];
int where[2 * MAXN], which[2 * MAXN];
int choice[MAXN];

void play_first() {
  puts("First");
  fflush(stdout);
  for (int i = 0; i < 2 * N; i++)
    printf("%d ", i % N + 1);
  puts("");
  fflush(stdout);
}

void dfs(int x, int c) {
  if (choice[x] != -1)
    return;
  choice[x] = c;
  parity ^= nums[x][c] % 2;
  if (nums[x][0] % N == nums[x][1] % N) {
    same = x;
    return;
  }
  int nxt = (nums[x][c] + N - 1) % (2 * N) + 1;
  dfs(where[nxt], which[nxt] ^ 1);
}

void play_second() {
  puts("Second");
  fflush(stdout);
  for (int i = 1; i <= 2 * N; i++) {
    scanf("%d", where + i);
    where[i]--;
    which[i] = nums[where[i]].size();
    nums[where[i]].push_back(i);
  }
  
  memset(choice, -1, sizeof choice);
  for (int i = 0; i < N; i++) 
    dfs(i, 0);
  
  if (parity) {
    if (same != -1)
      choice[same] ^= 1;
    else
      for (int i = 0; i < N; i++)
        choice[i] ^= 1;
  }
  
  for (int i = 0; i < N; i++)
    printf("%d ", nums[i][choice[i]]);
  puts("");
  fflush(stdout);
}

int main() {
  scanf("%d", &N);
  if (N % 2)
    play_second();
  else
    play_first();
  int verdict;
  scanf("%d", &verdict);
  assert(!verdict);  
  return 0;
}