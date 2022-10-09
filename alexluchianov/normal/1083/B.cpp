#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
char v[5 + nmax];
char v2[5 + nmax];


int main()
{
  int n , k ;
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++)
    cin >> v[i];
  for(int i = 1 ; i <= n ; i++)
    cin >> v2[i];

  ll result = 0;

  ll calc = 1;
  ll used = 0;

  for(int i = 1 ; i <= n ; i++){
    if(0 < k){
      calc = calc * 2 - (v[i] - 'a') - ('b' - v2[i]);
      result += MIN(k , calc - used) * (n - i + 1);
      ll used2 = used + MIN(k , calc - used);
      k -= MIN(k , calc - used);
      used = used2;

      //cout << result << " " << k << '\n';
    }
  }
  cout << result;

  return 0;
}