#include <iostream>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    int h, w;
    std::cin >> h >> w;

    std::vector<std::vector<int> > mat(h, std::vector<int>(w, 0));

    int a = h%2, b = w%2;

    if(a && b) {
      for(int i = 0; i < h; i += 2)
        mat[i][0] = mat[i][w-1] = 1;
      for(int i = 0; i < w; i += 2)
        mat[0][i] = mat[h-1][i] = 1;
    }
    else if(a & (!b)) {
      for(int i = 0; i+1 < h; i += 2)
        mat[i][0] = mat[h-1-i][w-1] = 1;
      for(int j = 0; j < w; j += 2)
        mat[0][j] = mat[h-1][w-1-j] = 1;
    }
    else if(b & (!a)) {
      for(int i = 0; i+1 < w; i += 2)
        mat[0][i] = mat[h-1][w-1-i] = 1;
      for(int j = 0; j < h; j += 2)
        mat[j][0] = mat[h-1-j][w-1] = 1;
    }
    else {
      for(int i = 1; i+1 < w; i += 2)
        mat[0][i] = mat[h-1][w-1-i] = 1;
      for(int i = 1; i+1 < h; i += 2)
        mat[h-1-i][0] = mat[i][w-1] = 1;
    }

    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++)
        std::cout << mat[i][j];
      std::cout << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}