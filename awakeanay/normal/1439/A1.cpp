#include <iostream>
#include <vector>

std::vector<std::vector<int> > ans;
std::vector<std::vector<int> > mat;

void add(std::vector<int> op) {
  ans.push_back(op);
  int minx = 1000, miny = 1000;
  for(int i = 0; i < 3; i++) {
    mat[op[2*i]][op[2*i+1]] ^= 1;
    if(op[2*i] - minx > 1 || op[2*i+1] - miny > 1) {
      ;
    }
    minx = std::min(minx, op[2*i]);
    miny = std::min(miny, op[2*i+1]);
  }
}

void solve(int i, int j, int x, int y) {
  if(x == 2 && y == 2) {
    int cur = 0;
    cur += mat[i][j] + mat[i+1][j] + mat[i][j+1] + mat[i+1][j+1];
    if(cur == 0) {
      return;
    }
    else if(cur == 1) {
      std::vector<int> op;
      int rem = 2;
      for(int p = 0; p < 2; p++)
        for(int q = 0; q < 2; q++) {
          if(mat[i+p][j+q] || rem) {
            op.push_back(i+p);
            op.push_back(j+q);
            if(!mat[i+p][j+q])
              rem--;
          }
        }
      add(op);
      solve(i, j, x, y);
    }
    else if(cur == 2) {
      std::vector<int> op;
      int rem = 1;
      for(int p = 0; p < 2; p++)
        for(int q = 0; q < 2; q++) {
          if((!mat[i+p][j+q]) || rem) {
            op.push_back(i+p);
            op.push_back(j+q);
            if(mat[i+p][j+q])
              rem--;
          }
        }
      add(op);
      solve(i, j, x, y);
    }
    else if(cur == 3) {
      std::vector<int> op;
      for(int p = 0; p < 2; p++)
        for(int q = 0; q < 2; q++) {
          if(mat[i+p][j+q]) {
            op.push_back(i+p);
            op.push_back(j+q);
          }
        }
      add(op);
    }
    else if(cur == 4) {
      std::vector<int> op;
      int rem = 3;
      for(int p = 0; p < 2; p++)
        for(int q = 0; q < 2; q++) {
          if(mat[i+p][j+q] && rem) {
            op.push_back(i+p);
            op.push_back(j+q);
            rem--;
          }
        }
      add(op);
      solve(i, j, x, y);
    }
  }
  else if(x == 2 && y == 3) {
    int rem = 3;
    std::vector<int> op;
    if(mat[i][j]) {
      op.push_back(i);
      op.push_back(j);
      rem--;
    }
    if(mat[i+1][j]) {
      op.push_back(i+1);
      op.push_back(j);
      rem--;
    }

    if(rem < 3) {
      for(int p = 0; p < 2; p++) {
          if(rem) {
            op.push_back(i+p);
            op.push_back(j+1);
            rem--;
          }
          else
            break;
      }
      add(op);
    }
    solve(i, j+1, 2, 2);
  }
  else if(x == 3 && y == 2) {
    int rem = 3;
    std::vector<int> op;
    if(mat[i][j]) {
      op.push_back(i);
      op.push_back(j);
      rem--;
    }
    if(mat[i][j+1]) {
      op.push_back(i);
      op.push_back(j+1);
      rem--;
    }

    if(rem < 3) {
      for(int q = 0; q < 2; q++) {
        if(rem) {
          op.push_back(i+1);
          op.push_back(j+q);
          rem--;
        }
        else
          break;
      }
      add(op);
    }
    solve(i+1, j, 2, 2);
  }
  else if(x == 3 && y == 3) {
    int rem = 3;
    std::vector<int> op;
    if(mat[i][j]) {
      op.push_back(i);
      op.push_back(j);
      rem--;
    }
    if(mat[i][j+1]) {
      op.push_back(i);
      op.push_back(j+1);
      rem--;
    }
    if(rem < 3) {
      for(int q = 0; q < 2; q++) {
        if(rem) {
          op.push_back(i+1);
          op.push_back(j+q);
          rem--;
        }
      }
      add(op);
    }
    rem = 3;
    op.clear();
    if(mat[i][j+2]) {
      op.push_back(i);
      op.push_back(j+2);
      rem--;
    }
    if(rem < 3) {
      for(int q = 0; q < 2; q++) {
        if(rem) {
          op.push_back(i+1);
          op.push_back(j+1+q);
          rem--;
        }
        else
          break;
      }
      add(op);
    }
    solve(i+1, j, 2, 3);
  }
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n, m;
    std::cin >> n >> m;

    mat.clear();
    ans.clear();

    mat = std::vector<std::vector<int> >(n, std::vector<int>(m, 0));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        char c;
        std::cin >> c;
        mat[i][j] = (c == '1');
      }

    for(int i = 0; i < n-1; i += 2) {
      for(int j = 0; j < m-1; j += 2) {
        int x = 2, y = 2;
        if(i + x == n-1)
          x++;
        if(j + y == m-1)
          y++;
        solve(i, j, x, y);
      }
    }

    std::cout << ans.size() << std::endl;
    for(std::vector<int> j : ans) {
      for(int k : j)
        std::cout << k+1 << " ";
      std::cout << std::endl;
    }
  }

  return 0;
}