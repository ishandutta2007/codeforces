#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) :(b))
#define MAX(a , b) (((a) < (b)) ? (b) :(a))

int const nmax = 1000;
int v[5 + nmax];
int x[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];

  vector<int> sol;

  for(int k = 1 ; k <= n ; k++){
    bool ok = 1;

    for(int i = 0 ; i < k ; i++)
      x[i] = 10000000;

    for(int i = 1 ; i <= n ; i++){
      if(x[(i - 1) % k] == 10000000)
        x[(i - 1) % k] = v[i] - v[i - 1];
      else if(x[(i - 1) % k] != v[i] - v[i - 1])
        ok = 0;
    }
    if(ok == 1)
      sol.push_back(k);
  }
  cout << sol.size() << '\n';
  for(int i = 0 ; i < sol.size() ; i++)
    cout << sol[i] << " " ;

  return 0;
}