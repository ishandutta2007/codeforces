#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int v[1 + nmax], sum[1 + nmax][3];
int target[1 + nmax][3];

int n;

pair<int,int> solve(int pos, int k, int &last){
  if(pos == n + 1)
    return {0, 0};
  else {
    int pos1 = target[sum[pos - 1][1] + k][1];
    int pos2 = target[sum[pos - 1][2] + k][2];
    if(pos1 == 0 && pos2 == 0)
      return {nmax, nmax};
    else if(pos1 != 0 && (pos2 == 0 || pos1 < pos2)){
      pair<int,int> sol = solve(pos1 + 1, k, last);
      if(last == 0)
        last = 1;
      sol.first++;
      return sol;
    } else {
      pair<int,int> sol = solve(pos2 + 1, k, last);
      if(last == 0)
        last = 2;
      sol.second++;
      return sol;
    }
  }
}

int main()
{
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    sum[i][1] += sum[i - 1][1];
    sum[i][2] += sum[i - 1][2];
    sum[i][v[i]]++;
    target[sum[i][v[i]]][v[i]] = i;
  }

  vector<pair<int,int>> sol;
  for(int i = 1; i <= n; i++){
    int last = 0;
    pair<int,int> result = solve(1, i, last);
    if(nmax <= result.first && nmax <= result.second )
      continue;
    else if((result.first < result.second && last == 2)  || (result.first > result.second && last == 1))
      sol.push_back({MAX(result.first, result.second), i});
  }

  cout << sol.size() << '\n';
  sort(sol.begin(), sol.end());
 // reverse(sol.begin(), sol.end());
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i].first << " " << sol[i].second << '\n';

  return 0;
}