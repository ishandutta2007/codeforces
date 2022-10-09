#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int const nmax = 100000;

void solve(){
  int n, r;
  cin >> n >> r;
  vector<int> v;
  for(int i = 1; i <= n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int hits = 0;
  for(int i = v.size() - 1;0 <= i; i--){
    if(hits * r < v[i]){
      hits++;
    } else
      break;
  }
  cout << hits << '\n';
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