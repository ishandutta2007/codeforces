#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

bool iseven(int n, int result, int x, int y){
  if(n % 2 == 0)
    return result == 0;
  else
    return result == x;
}

int n, x, y;

bool ask(int bit, int requiered = -1){
  vector<int> sol;
  for(int i = 1; i <= n; i++)
    if(0 < (i & (1 << bit)) && (requiered == -1 || (0 < (i & (1 << requiered))) ) )
      sol.push_back(i);

  if(0 < sol.size()) {
    cout << "? " << sol.size() << " ";
    for(int i = 0; i < sol.size(); i++)
      cout << sol[i] << " ";
    cout << '\n';
    cout << flush;
    int ans;
    cin >> ans;
    return iseven(sol.size() ,ans, x, y);
  }
  return 1;
}

int isdif[20];
int main()
{
  cin >> n >> x >> y;
  for(int bit = 0; bit < 10; bit++)
    isdif[bit]= !ask(bit);

  int sol1 = 0, bitspec = 0;

  for(int bit = 0; bit < 10; bit++){
    if(isdif[bit] == 1) {
      sol1 = (1 << bit);
      bitspec = bit;
      break;
    }
  }
  for(int bit = 0; bit < 10; bit++){
    if(bit != bitspec)
      if(ask(bit, bitspec) == 0)
        sol1 |= (1 << bit);
  }

  int sol2 = sol1;
  for(int bit = 0; bit < 10; bit++)
    sol2 ^= (isdif[bit] << bit);

  if(sol2 < sol1)
    swap(sol1, sol2);
  cout << "! " << sol1 << " " << sol2 << '\n';
  cout << flush;
  return 0;
}