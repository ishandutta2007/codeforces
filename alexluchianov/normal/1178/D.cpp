#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int isprime(int n){
  for(int i = 2; i * i <= n; i++)
    if(n % i == 0)
      return 0;
  return 1;
}

vector<pair<int,int>> sol;

int main()
{
  int n;
  cin >> n;

  sol.push_back({1, n});
  for(int i = 1;i < n; i++)
    sol.push_back({i, i + 1});

  int edges = n;
  int st = 1, dr = n / 2 + 1;

  while(isprime(edges) == 0){
    sol.push_back({st, dr});
    st++;
    dr++;
    edges++;
  }


  cout << sol.size() << '\n';
  for(int i = 0;i < sol.size(); i++)
    cout << sol[i].first << " " << sol[i].second << '\n';

  return 0;
}