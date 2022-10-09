#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

void solve(){
  int n, k;
  cin >> n >> k;
  vector<int> temp;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    temp.push_back(val);
  }
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  if(temp.size() <= k){
    cout << k * n << '\n';
    while(temp.size() < k)
      temp.push_back(1);

    for(int i = 1; i <= n; i++)
      for(int j = 0; j < temp.size(); j++)
        cout << temp[j] << " ";
    cout << '\n';
  } else
    cout << -1 << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}