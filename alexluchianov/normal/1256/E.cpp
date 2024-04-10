#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const inf = 1000000000;
struct Person{
  int val;
  int id;
  bool operator < (Person const &a) const{
    return val < a.val;
  }
};
Person v[1 + nmax];
int dp[1 + nmax], last[1 + nmax];
int sol[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    cin >> v[i].val;
    v[i].id = i;
  }
  sort(v + 1, v + n + 1);

  for(int i = 1;i <= n; i++)
    dp[i] = inf;
  for(int i = 3;i <= n; i++){
    for(int j = 3; j <= MIN(5, i); j++) {
      if(dp[i - j] + v[i].val - v[i - j + 1].val < dp[i]) {
        dp[i] = dp[i - j] + v[i].val - v[i - j + 1].val;
        last[i] = i - j;
      }
    }
  }
  int pos = n, teams = 0;
  while(0 < pos){
    teams++;
    for(int j = last[pos] + 1; j <= pos; j++)
      sol[v[j].id] = teams;
    pos = last[pos];
  }

  cout << dp[n] << " " << teams << '\n';
  for(int i = 1;i <= n; i++)
    cout << sol[i] << " ";
  cout << '\n';

  return 0;
}