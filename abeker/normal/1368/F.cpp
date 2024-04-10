#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

int N;
bool gap[MAXN], on[MAXN];
bool overflow;

void play(const vector <int> &v) {
  int k = v.size();
  printf("%d", k);
  for (auto it : v) {
    printf(" %d", it + 1);
    on[it] = true;
  }
  puts("");
  fflush(stdout);
  int x;
  scanf("%d", &x);
  for (int i = 0; i < k; i++)
    on[(x + i - 1) % N] = false;
}

void finish() {
  puts("0");
  fflush(stdout);
  exit(0);
}

int main() {
  scanf("%d", &N);
  
  if (N <= 3) 
    finish();
  
  int blocks = sqrt(N), curr = 0;
  for (int i = 0; i < blocks; i++) {
    gap[curr] = true;
    curr += N / blocks;
    if (i < N % blocks)
      curr++;
  }
  assert(curr == N);
  
  int K = (N - 1) / blocks + 1;
  do {
    overflow = false;
    vector <int> moves;
    for (int i = 0; i < N; i++)
      if (!gap[i] && !on[i]) {
        if (moves.size() < K)
          moves.push_back(i);
        else
          overflow = true;
      }
    play(moves);
  } while (overflow);
  
  finish();
  
  return 0;
}