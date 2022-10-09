#include <iostream>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) :(b))
#define MAX(a , b) (((a) < (b)) ? (b) :(a))

int const nmax = 100;
int v[5 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int k = 0;
  for(int i = 1 ; i <= n ; i++){
    cin >> v[i];
    k = MAX(k ,v[i]);
  }

  while(true){
    int sum = 0;
    int sum2 = 0;

    for(int i = 1 ; i <= n ;i++){
      sum += v[i];
      sum2 += k - v[i];
    }

    if(sum < sum2)
      break;
    k++;
  }
  cout << k;
  return 0;
}