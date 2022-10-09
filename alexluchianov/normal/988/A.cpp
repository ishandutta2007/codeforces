#include <iostream>
#include <map>
#include <vector>

using namespace std;

int const nmax = 100;

map<int,int> frec;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> sol;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    if(frec[val] == 0)
      sol.push_back(i);
    frec[val] = 1;
  }
  if(sol.size() < k)
    cout << "NO";
  else {
    cout << "YES\n";
    for(int i = 0; i < k; i++)
      cout << sol[i] << " ";
    cout << '\n';
  }
  return 0;
}