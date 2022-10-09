#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector<ll> sol;

int main()
{
  ll n, d;
  cin >> n >> d;
  ll start = 1;
  while(0 < n){
    for(int h = 30; 1 <= h; h--){
      if((1 << h) - 1 <= n){
        n -= (1 << h) - 1;
        for(int j = 1; j <= h; j++)
          sol.push_back(start);
        start += d + 1;
      }
    }
  }
  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  return 0;
}