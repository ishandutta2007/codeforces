#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
ll frec[5 + nmax];

ll a , b;

bool test(ll val){
  for(int i = 1 ; i <= val ; i++)
    frec[i] = 0;

  ll sum = a , sum2 = b;

  for(int i = val ; 1 <= i ; i--){
    if(i <= sum){
      sum -= i;
      frec[i] = 1;
    } else {
      frec[i] = 2;
      sum2 -= i;
    }
  }

  return 0 <= sum && 0 <= sum2;
}

ll binarysearch(ll from , ll to){
  if(from < to){
    ll mid = (from + to + 1) / 2;
    if(test(mid) == 1)
      return binarysearch(mid , to);
    else
      return binarysearch(from ,mid - 1);
  } else
    return from;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;

  test(3);

  ll val = binarysearch(0 , nmax);

  test(val);

  int n = 0 , m = 0;

  for(int i = 1 ; i <= val ; i++)
    if(frec[i] == 1)
      n++;

  cout << n << '\n';
  for(int i = 1 ; i <= val ; i++)
    if(frec[i] == 1)
      cout << i << " ";
  cout << '\n' << val - n << '\n';
  for(int i = 1 ; i <= val ; i++)
    if(frec[i] == 2)
      cout << i << " ";
  for(int i = 1 ; i <= val ; i++)
    if(frec[i] == 0) {
      cout << "ERROR";
      return 0;
  }

  return 0;
}