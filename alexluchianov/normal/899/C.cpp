#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  cout << (1LL * n * (n + 1) / 2 ) % 2 << '\n';

  vector<int> sol;
  while(4 <= n){
    sol.push_back(n - 3);
    sol.push_back(n);
    n -= 4;
  }
  if(n == 1)
    sol.push_back(1);
  else if(n == 2)
    sol.push_back(1);
  else if(n == 3) {
    sol.push_back(1);
    sol.push_back(2);
  }
  cout << sol.size() << " ";
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  return 0;
}