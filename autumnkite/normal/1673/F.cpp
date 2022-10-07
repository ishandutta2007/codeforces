#include <bits/stdc++.h>

const int L = 5;

int label[1 << L], trans[1 << L];

void init() {
  for (int i = 0; i < (1 << L); ++i) {
    label[i] = i ^ (i >> 1);
    trans[label[i]] = i;
  }
}

int get_label(int x, int y) {
  x = label[x], y = label[y];
  int res = 0;
  for (int i = 0; i < L; ++i) {
    res |= (x >> i & 1) << (2 * i);
    res |= (y >> i & 1) << (2 * i + 1);
  }
  return res;
}

std::pair<int, int> trans_from(int S) {
  int x = 0, y = 0;
  for (int i = 0; i < L; ++i) {
    x |= (S >> (2 * i) & 1) << i;
    y |= (S >> (2 * i + 1) & 1) << i;
  }
  x = trans[x], y = trans[y];
  return std::make_pair(x, y);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  init();

  int n, q;
  std::cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < n; ++j) {
      std::cout << (get_label(i, j) ^ get_label(i, j + 1)) << " ";
    }
    std::cout << "\n";
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << (get_label(i, j) ^ get_label(i + 1, j)) << " ";
    }
    std::cout << "\n";
  }
  std::cout.flush();

  int now = 0;
  while (q--) {
    int S;
    std::cin >> S;
    now ^= S;
    auto [x, y] = trans_from(now);
    std::cout << x + 1 << " " << y + 1 << std::endl;
  }
}