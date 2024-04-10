#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

vector<int> sol;

int main()
{
  ll sum = 0, sum2 = 0;
  int n;
  cin >> n;

  int init = 0;
  cin >> init;
  sum2 = init;
  sol.push_back(1);

  for(int i = 2;i <= n; i++){
    int a;
    cin >> a;
    if(a * 2 <= init) {
      sum2 += a;
      sol.push_back(i);
    } else
      sum += a;
  }
  if(sum < sum2) {
    cout << sol.size() << '\n';
    for(int i = 0; i < sol.size(); i++)
      cout << sol[i] << " " ;
  } else
    cout << 0;

  return 0;
}