#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200005;
int const inf = 1000000001;
int v[1 + nmax];

bool compare(int x, int y){
  return v[x] < v[y];
}

int ind[1 + nmax];
int farmax[1 + nmax];
int farmin[1 + nmax];
int dp[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    v[i + n] = v[i];

  vector<int> stmax;
  vector<int> stmin;
  v[2 * n + 1] = inf + 1;
  stmax.push_back(2 * n + 1);
  stmin.push_back(2 * n + 2);

  for(int i = 2 * n; 1 <= i; i--) {
    while(0 < stmax.size() && v[stmax.back()] <= v[i])
      stmax.pop_back();
    stmax.push_back(i);
    while(0 < stmin.size() && v[i] <= v[stmin.back()])
      stmin.pop_back();
    stmin.push_back(i);

    int x = stmin.size() - 1;
    for(int jump = (1 << 20); 0 < jump; jump /= 2)
      if(jump <= x && v[i] / 2.0 <= v[stmin[x - jump]] )
        x -= jump;
    x--;
    farmin[i] = stmin[x];
    farmax[i] = stmax[stmax.size() - 2];
  }

  for(int i = 1;i <= n; i++)
    ind[i] = i;
  sort(ind + 1, ind + n + 1, compare);
  for(int i = n; 1 <= i; i--){
    int node = ind[i];
    if(farmax[node] <= 2 * n && farmax[node] < farmin[node]){
      int to = farmax[node];
      if(n < to)
        to -= n;
      if(node < to)
        dp[node] = dp[to] + to - node;
      else
        dp[node] = dp[to] + n - node + to;
      //cout << "|";
    } else if(farmin[node] <= 2 * n){
      int to = farmin[node];
      if(n < to)
        to -= n;
      if(node < to)
        dp[node] = to - node;
      else
        dp[node] = n - node  + to;
      //cout << ":";
    } else
      dp[node] = inf;
    //cout << node << " " << farmin[node] << " " << farmax[node] << " " << dp[node] <<  '\n';
  }

  for(int i = 1;i <= n; i++)
    if(dp[i] < nmax)
      cout << dp[i] << " ";
    else
      cout << -1 << " ";
  cout << '\n';
  return 0;
}