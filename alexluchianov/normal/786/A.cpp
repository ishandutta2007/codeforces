#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 14000;
vector<int> g[1 + nmax], invg[1 + nmax];
vector<int> s[3];

int counted[1 + nmax];
int dp[1 + nmax];

int main()
{
  int n;
  cin >> n;
  int m;
  cin >> m;
  for(int i = 1;i <= m; i++){
    int val;
    cin >> val;
    s[1].push_back(val);
    for(int j = 1;j <= n; j++){
      int to = (j + val - 1) % n + 1;
      counted[j * 2 - 1]++;
    }
  }
  cin >> m;
  for(int i = 1;i <= m; i++){
    int val;
    cin >> val;
    s[2].push_back(val);
    for(int j = 1;j <= n; j++){
      int to = (j + val - 1) % n + 1;
      counted[j * 2]++;
    }
  }

  queue<int> q;
  dp[1] = 2;
  dp[2] = 1;

  q.push(1);
  q.push(2);
  while(0 < q.size()){
    int node = q.front();
    q.pop();
    int turn = 2 - node % 2;

    for(int h = 0; h < s[3 - turn].size(); h++){
      int to = (n + (node + 1) / 2 - s[3 - turn][h]) % n;
      if(to <= 0)
        to += n;
      if(turn == 1)
        to = to * 2;
      else
        to = to * 2 - 1;
      counted[to]--;
      if(dp[node] == turn && counted[to] == 0){
        if(dp[to] == 0){
          dp[to] = dp[node];
          q.push(to);
        }
      } else if(dp[node] == 3 - turn){
        if(dp[to] == 0){
          dp[to] = dp[node];
          q.push(to);
        }
      }
    }
  }

  for(int i = 2;i <= n; i++)
    if(dp[i * 2 - 1] == 1)
      cout << "Win ";
    else if(dp[i * 2 - 1] == 2)
      cout << "Lose ";
    else
      cout << "Loop ";

  cout << '\n';

  for(int i = 2;i <= n; i++)
    if(dp[i * 2] == 2)
      cout << "Win ";
    else if(dp[i * 2] == 1)
      cout << "Lose ";
    else
      cout << "Loop ";
  return 0;
}