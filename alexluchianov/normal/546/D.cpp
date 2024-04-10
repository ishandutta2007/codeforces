#include <iostream>

using namespace std;

int const nmax = 5000000;
int ciur[5 + nmax];

void computeciur(int n){
  for(int i = 2 ; i <= n ; i++){
    if(ciur[i] == 0) {
      int i2 = i;
      while(true) {
        for(int j = i2 ; j <= n ; j += i2)
          ciur[j]++;
        if(1LL * i2 * i <= n)
          i2 *= i;
        else
          break;
      }
    }
  }
  for(int i = 1 ; i <= n ; i++)
    ciur[i] += ciur[i - 1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  computeciur(nmax);
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++){
    int a , b;
    cin >> a >> b;
    if(b < a)
      swap(a , b);

    cout << ciur[b] - ciur[a] << '\n';
  }
  return 0;
}