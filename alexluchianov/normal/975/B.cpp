#include <iostream>

using namespace std;

#define MAX(a , b) (((a) < (b)) ? (b) : (a))
#define ll long long

ll v[20];

int const n = 14;

ll solve(int k){
  ll result = 0;

  for(int i = 1 ; i <= 14 ;i++){
    int pos = (k + i) % n;
    int a = v[pos] + v[k] / 14;
    if(i <= v[k] % 14){
      a++;
    }
    if(a % 2 == 0){
      if(i < 14)
        result += a;
    }
    if(i == 14 && (a - v[pos]) % 2 == 0)
      result += a - v[pos];
  }
  return result;
}
int main()
{
  for(int i = 0 ; i < n ;i++)
    cin >> v[i];
  ll smax = 0;
  for(int i = 0 ; i < n ;i++)
    if(0 < v[i])
      smax = MAX(smax , solve(i));
  cout << smax;
  return 0;
}