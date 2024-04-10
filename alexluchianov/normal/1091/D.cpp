//#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int const modulo = 998244353;

vector<int> v;
int sum[5 + nmax];

int fact[5 + nmax];

void precompute(){
  fact[0] = 1;
  for(int i = 1 ; i <= nmax ; i++){
    fact[i] = 1LL * fact[i - 1] * i % modulo;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  /*
  vector<int> temp;

  for(int i = 1 ; i <= n ; i++){
    temp.push_back(i);
  }
  v.push_back(0);

  vector<int> temp2 = temp;
  do{
    for(int i = 0 ; i < n ; i++)
      v.push_back(temp[i]);
    next_permutation(temp.begin() , temp.end());

  } while(!(temp == temp2));

  for(int i = 1 ; i < v.size() ; i++){
    sum[i] = sum[i - 1] + v[i];
  }

  int result = 0 , sumpart = 0;
  for(int i = 1 ; i < v.size() ; i++){
    cout << v[i] << " ";
    if(n <= i && sum[i] - sum[i - n] == n * (n + 1) / 2){
      result++;
      cout << ":";
      sumpart++;
    }
    if(i % n == 0) {
      cout << "     " <<sumpart - 1  << '\n';
      sumpart = 0;

      cout << '\n';
    }

  }
  cout << result;
  */
  if(n == 1)
    cout << 1 << '\n';
  else if(n == 2)
    cout << 2 << '\n';
  else {
    precompute();
    ll sol = 9;
    for(int i = 4 ; i <= n ; i++){
      sol = 1LL * i * (sol + fact[i - 1] - 1) % modulo;
    }
    cout << sol;
  }


  return 0;
}