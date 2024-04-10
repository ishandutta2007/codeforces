#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

using ll = long long;
int const nmax = 200000;

struct Person{
  int cost;
  int number;
  bool operator < (Person const &a) const{
    return number < a.number;
  }
};
Person v[1 + nmax];

void solve(){
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i].number >> v[i].cost;
  sort(v + 1, v + n + 1);
  ll result = 0;
  int votes = 0;

  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = n; 1 <= i; i--){
    pq.push(v[i].cost);
    if(v[i].number <= i - 1 + votes)
      continue;
    else{
      result += pq.top();
      votes++;
      pq.pop();
    }
  }
  cout << result << '\n';
}

int main()
{
  int t;
  cin >> t;
  for(int testcase = 1; testcase <= t; testcase++)
    solve();
  return 0;
}