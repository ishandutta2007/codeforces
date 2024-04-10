#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 500;
int const idmax = 600000;
char v[1 + nmax][1 + nmax];
int sol[1 + idmax];

struct Query{
  int x;
  int y;
  int x2;
  int y2;
  int id;
};

int n, m;
bitset<1 + 2 * nmax> emptybitset;
bitset<1 + 2 * nmax> dp[5 + nmax][5 + nmax];

int antidiag(int i, int j){
  return n - i + j;
}

int valid(int i, int j){
  return (1 <= i && i <= n) && (1 <= j && j <= m);
}

void divide(int from, int to, vector<Query> queries){
  if(queries.size() == 0)
    return ;
  int mid = (from + to) / 2;
  vector<Query> queriesleft, queriesright, queriesnow;
  for(int i = 0; i < queries.size(); i++){
    int l = queries[i].x + queries[i].y;
    int r = queries[i].x2 + queries[i].y2;
    if(l < mid && r < mid)
      queriesleft.push_back(queries[i]);
    else if(mid + 1 <= l && mid + 1 <= r)
      queriesright.push_back(queries[i]);
    else
      queriesnow.push_back(queries[i]);
  }

  divide(from, mid - 1, queriesleft);
  divide(mid + 1, to, queriesright);

  for(int i = 1; i <= n; i++)
    for(int j = from - i; j <= to - i; j++)
      if(valid(i, j))
        dp[i][j] = emptybitset;

  for(int i = 1; i <= mid; i++) {
    int j = mid - i;
    if(valid(i, j) == 1 && v[i][j] == '.')
      dp[i][j][antidiag(i, j)] = 1;
  }

  for(int sum = mid - 1; from <= sum; sum--)
    for(int i = 1; i <= sum; i++){
      int j = sum - i;
      if(valid(i, j) == 1 && v[i][j] == '.')
        dp[i][j] = dp[i + 1][j] | dp[i][j + 1];
    }

  for(int sum = mid + 1; sum <= to; sum++)
    for(int i = 1; i <= sum; i++){
      int j = sum - i;
      if(valid(i, j) == 1 && v[i][j] == '.')
        dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
    }

  for(int i = 0; i < queriesnow.size(); i++){
    int x = queriesnow[i].x;
    int y = queriesnow[i].y;
    int x2 = queriesnow[i].x2;
    int y2 = queriesnow[i].y2;
    sol[queriesnow[i].id] = (0 < (dp[x][y] & dp[x2][y2]).count());
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;

  for(int i = 1;i <= n; i++)
    for(int j = 1;j <= m; j++)
      cin >> v[i][j];
  int q;
  cin >> q;
  vector<Query> queries;
  for(int i = 1; i <= q; i++){
    int x, y, x2, y2;
    cin >> x >> y >> x2 >> y2;
    queries.push_back({x, y, x2, y2, i});
  }
  divide(2, n + m, queries);
  for(int i = 1; i <= q; i++)
    if(sol[i] == 0)
      cout << "No\n";
    else
      cout << "Yes\n";

  return 0;
}