#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int const inf = 1000000000;

int v[1 + nmax];
bitset<5 + nmax> dp[5 + nmax];

struct Move{
  int cnt;
  int x;
  int y;
};

vector<Move> sol;

int n, k, target, sum = 0;

void mv(int x, int y){
  if(x != y && 0 < v[x]){
    sol.push_back({v[x] / k + (0 < (v[x] % k)), x, y});
    v[y] += v[x];
    v[x] = 0;
  }
}

void mv2(int x, int y, int exact){
  if(x != y && 1 <= exact){
    sol.push_back({exact, x, y});
    v[y] += k * exact;
    v[x] -= k * exact;
  }
}

int main()
{
  cin >> n >> k >> target;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  if(sum < target) {
    cout << "NO";
    return 0;
  }
  dp[0][0] = 1;

  for(int i = 1;i <= n; i++){
    for(int j = 0;j < k; j++) {
      dp[i][j] = dp[i - 1][j] | dp[i - 1][(j - v[i] % k + k) % k];
    }
  }
  if(dp[n][target % k] == 0){
    cout << "NO";
    return 0;
  }

  if(target % k == 0){
    for(int i = 1;i <= n; i++)
      mv(i, 2);
    mv2(2, 1, target / k);
    cout << "YES\n";
    for(int i = 0; i < sol.size(); i++)
      cout << sol[i].cnt << " " << sol[i].x << " " << sol[i].y << '\n';
    return 0;
  }
  int current = target % k, last = 1;
  for(int i = n; 1 <= i; i--){
    if(dp[i - 1][(current - v[i] % k + k) % k] == 1){
      current = (current - v[i] % k + k) % k;
      if(last != 1)
        mv(i, last);
      else
        last = i;
    }
  }

  int oth = 1;
  if(last == 1)
    oth = 2;

  for(int i = 1;i <= n; i++)
    if(last != i && 0 < v[i])
      mv(i, oth);

  if(v[last] < target)
    mv2(oth, last, (target - v[last]) / k);
  else
    mv2(last, oth, (v[last] - target) / k);

  cout << "YES\n";
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i].cnt << " " << sol[i].x << " " << sol[i].y << '\n';

  return 0;
}
/*
1
2 6 1

*/