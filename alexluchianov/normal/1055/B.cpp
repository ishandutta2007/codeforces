#include <iostream>
#include <fstream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
ll v[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie();

  int n , q ,  l;
  cin >> n >> q >> l;
  int result = 0;

  for(int i = 1 ; i <= n ; i++){
    cin >> v[i];
    if(v[i - 1] <= l && l < v[i])
      result++;
  }
  for(int i = 1 ; i <= q ; i++){
    int op;
    cin >> op;
    if(op == 0)
      cout << result << '\n';
    else{
      int p , d;
      cin >> p >> d;
      v[p] += d;
      if(l < v[p] && v[p] - d <= l){
        if(l < v[p - 1] && l < v[p + 1])
          result--;
        else if(v[p - 1] <= l && v[p + 1] <= l)
          result++;
      }
    }
  }
  return 0;
}