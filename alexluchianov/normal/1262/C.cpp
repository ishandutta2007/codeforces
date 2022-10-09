#include <iostream>
#include <vector>

using namespace std;

int const nmax = 2000;

char v[1 + nmax];
char sol[1 + nmax];

void solve(){
  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  int lim = n - 2 * (k - 1);
  for(int i = 1; i <= lim / 2; i++)
    sol[i] = '(';
  for(int i = lim / 2 + 1; i <= lim; i++)
    sol[i] = ')';
  for(int i = lim + 1;i <= n; i += 2){
    sol[i] = '(';
    sol[i + 1] = ')';
  }
  vector<pair<int,int>> result;
  for(int i = 1;i <= n;i++)
    for(int j = i + 1; j <= n; j++)
      if(v[i] != v[j] && sol[i] != v[i] && v[j] != sol[j]) {
        if(i + 1 < j - 1)
          result.push_back({i + 1, j - 1});
        result.push_back({i, j});
        swap(v[i], v[j]);
      }

  cout << result.size() << '\n';
  for(int i = 0; i < result.size(); i++)
    cout << result[i].first << " " << result[i].second << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}