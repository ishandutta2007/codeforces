#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

vector<vector<int>> v;

void initialize(vector<vector<int>> &mat, int n, int m){
  mat.resize(2 + n);
  for(int i = 0;i <= 1 + n; i++)
    mat[i].resize(2 + m);
}

vector<vector<int>> sum;
vector<vector<int>> sol;
vector<vector<int>> sum2;

int n, m;

bool valid(int x, int y, int k){
  return (1 <= x - k && x + k <= n) &&
         (1 <= y - k && y + k <= m);
}

int getsum(int x, int y, int x2, int y2){
  return sum[x2][y2] - sum[x2][y - 1] - sum[x - 1][y2] + sum[x - 1][y - 1];
}

int test(int k){

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      sol[i][j] = sum2[i][j] = 0;
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(valid(i, j, k)){
        int x, y, x2, y2;
        x = i - k;
        y = j - k;
        x2 = i + k;
        y2 = j + k;
        if(getsum(x, y, x2, y2) == (x2 - x + 1) * (y2 - y + 1)) {
          sol[i][j] = 1;
          sum2[x][y]++;
          sum2[x2 + 1][y]--;
          sum2[x][y2 + 1]--;
          sum2[x2 + 1][y2 + 1]++;
        }
      }
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      sum2[i][j] += sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1];
  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      if(v[i][j] == 1 && sum2[i][j] == 0)
        return 0;
  return 1;
}

int binarysearch(int from, int to){
  if(from < to){
    int mid = (from + to + 1) / 2;
    if(test(mid) == 1)
      return binarysearch(mid, to);
    else
      return binarysearch(from, mid - 1);
  } else
    return from;
}

int main()
{
  //*
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //*/

  cin >> n >> m;
  initialize(v, n, m);
  initialize(sum, n, m);
  initialize(sol, n, m);
  initialize(sum2, n, m);

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++){
      char val;
      cin >> val;
      if(val == 'X')
        v[i][j] = 1;
      else
        v[i][j] = 0;
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i][j];
    }
  int result = binarysearch(0, min(n, m));
  test(result);

  cout << result << '\n';
  for(int i = 1;i <= n; i++) {
    for(int j = 1;j <= m; j++)
      if(sol[i][j] == 1)
        cout << 'X';
      else
        cout << '.';
    cout << '\n';
  }
  return 0;
}