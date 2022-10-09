#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 100;
int const kmax = 2000;

struct Item{
  int t;
  int price;
  int lim;
  int id;
  bool operator < (Item const &a) const {
    return lim < a.lim ;
  }
} v[1 + nmax];
int dp[1 + nmax][1 + kmax], taken[1 + nmax][1 + kmax];
vector<int> sol;

void extract(int i, int time){
  if(i == 0)
    return ;
  if(taken[i][time] == 1){
    extract(i - 1, time - v[i].t);
    sol.push_back(v[i].id);
  } else
    extract(i - 1, time);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i].t >> v[i].lim >> v[i].price;
    v[i].id = i;
  }
  sort(v + 1, v + n + 1);
  for(int i = 1;i <= n; i++) {
    for(int j = 0; j <= kmax; j++)
      dp[i][j] = dp[i - 1][j];
    for(int j = 0; j < v[i].lim - v[i].t; j++) {
      if(dp[i][j + v[i].t] < dp[i - 1][j] + v[i].price) {
        dp[i][j + v[i].t] = dp[i - 1][j] + v[i].price;
        taken[i][j + v[i].t] = 1;
      }
    }
  }
  int idmax = 0;
  for(int i = 1;i <= kmax; i++)
    if(dp[n][idmax] < dp[n][i])
      idmax = i;
  cout << dp[n][idmax] << '\n';
  extract(n, idmax);
  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  return 0;
}