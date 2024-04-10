#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<ll> divisors;
vector<int> nxt[1 + nmax];

int printed = 0;

void print(int id, ll k){
  if(id == 0 || k == 0){
    cout << divisors[id] << " ";
    ++printed;
    if(printed == nmax)
      exit(0);
  } else {
    for(int i = 0; i < nxt[id].size(); i++)
      print(nxt[id][i], k - 1);
  }
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n, k;
  cin >> n >> k;
  for(int i = 1; 1LL * i * i <= n; i++){
    if(n % i == 0) {
      divisors.push_back(i);
      if(i != n / i)
        divisors.push_back(n / i);
    }
  }


  sort(divisors.begin(), divisors.end());
  for(int i = 0; i < divisors.size(); i++){
    for(int j = 0; j < divisors.size(); j++){
      if(divisors[i] % divisors[j] == 0)
        nxt[i].push_back(j);
    }
  }

  print(divisors.size() - 1, k);
  return 0;
}
///1000000000000