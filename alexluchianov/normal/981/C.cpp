#include <iostream>
#include <vector>

using namespace std;

int const nmax = 100000;

vector < int > g[5 + nmax];

int main()
{
  int n ;
  cin >> n ;
  if(n == 2){
    cout << "Yes\n";
    cout << 1 << '\n';
    cout << 1 << " " << 2;
    return 0;
  }

  for(int i = 1 ; i < n ;i++){
    int x , y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int sum = 0  , point = 0;
  for(int i = 1 ; i <= n ;i++)
    if(2 < g[i].size()){
      sum++;
      point = i;
    }
  if(sum <= 1) {
    cout << "Yes\n";
    if(sum == 0)
      for(int i = 1 ; i <= n ;i++)
        if(g[i].size() == 2){
          point = i;
          break;
        }
    int sum2 = 0;
    for (int i = 1 ; i <= n ; i++)
      if(g[i].size() == 1)
        sum2 ++;
    cout << sum2 << '\n';
    for (int i = 1 ; i <= n ; i++)
      if(g[i].size() == 1)
        cout << point << " " << i << '\n';
  } else{
    cout << "No\n";
  }
  return 0;
}