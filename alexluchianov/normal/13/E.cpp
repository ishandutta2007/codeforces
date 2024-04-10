#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 100000;
int const bucketsize = 300;
int v[1 + nmax];
int jump[1 + nmax][2];

int getbucket(int number) {
  return (number - 1) / bucketsize ;
}

void build(int start, int stop) {
  for(int i = stop; start <= i; i--) {
    if(i + v[i] <= stop) {
      jump[i][0] = jump[i + v[i]][0];
      jump[i][1] = jump[i + v[i]][1] + 1;
    } else {
      jump[i][0] = i;
      jump[i][1] = 0;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  for(int i = 1;i <= n; i++)
    std::cin >> v[i];
  for(int i = 1;i <= n; i += bucketsize) {
    build(i, std::min(n, i + bucketsize - 1));
  }
  for(int i = 1;i <= m; i++) {
    int op, a, b;
    std::cin >> op >> a;
    if(op == 0) {
      std::cin >> b;
      v[a] = b;
      build(getbucket(a) * bucketsize + 1, std::min(n, getbucket(a) * bucketsize + bucketsize));
    } else {
      int node = a, acc = 0;
      while(node + v[node] <= n) {
        acc++;
        node = node + v[node];
        acc += jump[node][1];
        node = jump[node][0];
      }
      std::cout << node << " " << acc + 1 << '\n';
    }
  }
  return 0;
}