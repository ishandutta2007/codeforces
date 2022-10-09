#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;

int ask(int n, int pos){
  cout << "? ";
  for(int i = 1;i <= n; i++)
    if(pos != i)
      cout << i << " ";
  cout << '\n';
  cout << flush;
  int posp, val;
  cin >> posp >> val;
  return val;
}

int main()
{
  int n, k;
  cin >> n >> k;
  n = k + 1;
  int smax = -1, scount = 0;
  for(int i = 1;i <= n; i++){
    int result = ask(n, i);
    if(smax < result){
      smax = result;
      scount = 1;
    } else if(smax == result){
      scount++;
    }
  }

  cout << "! " << scount;
  return 0;
}