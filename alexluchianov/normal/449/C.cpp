#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

int prime[1 + nmax];
int seen[1 + nmax];
vector<pair<int,int>> sol;

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    prime[i] = 1;

  prime[1] = 0;
  for(int i = 2; i <= n; i++){
    for(int j = 2 * i; j <= n; j += i)
      prime[j] = 0;
  }
  for(int i = n; 2 <= i; i--){
    if(prime[i] == 1 && i * 2 <= n){

      int x = 0;
      for(int j = 3 * i; j <= n; j+= i){
        if(seen[j] == 0){
          if(x == 0){
            x = j;
          } else {
            seen[j] = seen[x] = 1;
            sol.push_back({j, x});
            x = 0;
          }
        }
      }

      if(0 < x){
        if(0 == seen[i] && 0 == seen[x]){
          seen[i] = seen[x] = 1;
          sol.push_back({i, x});
        }
      } else{
        if(seen[i] == 0 && seen[i * 2] == 0){
          seen[i] = seen[i * 2] = 1;
          sol.push_back({i, i * 2});
        }
      }

    }
  }

  cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i].first << " " << sol[i].second << '\n';

  return 0;
}