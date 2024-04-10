#include <iostream>
#include <cstring>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000;
int sum[5 + nmax];

int main()
{
  int n , m , q;
  cin >> n >> m >> q;
  string a , b;
  cin >> a >> b;
  for(int i = 0 ; i <= n - m ; i++){
    if(a.substr(i , m) == b){
      sum[i]++;
    }
  }
  for(int i = 1 ; i <= n ;i++)
    sum[i] += sum[i - 1];

  for(int i = 1 ; i <= q ; i++){
    int x , y;
    cin >> x >> y;
    x--;
    y--;
    if(x + m - 1 <= y){
      cout << sum[y - m + 1] - sum[x - 1] << '\n';
    } else
      cout << 0 << '\n';
  }
  return 0;
}