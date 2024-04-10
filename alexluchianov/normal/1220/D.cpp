#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
int const lgmax = 60;
vector<ll> v[1 + lgmax];

int lg(ll n){
  if(n % 2 == 0)
    return lg(n / 2) + 1;
  return 0;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 0;i < n; i++) {
    ll a;
    cin >> a;
    v[lg(a)].push_back(a);
  }
  int smax = 0;
  for(int i = 0; i < lgmax; i++)
    if(smax < v[i].size())
      smax = v[i].size();

  for(int i = 0; i < lgmax; i++)
    if(smax == v[i].size()){
      cout << n - smax << '\n';
      for(int j = 0; j < lgmax; j++)
        if(i != j) {
          for(int h = 0; h < v[j].size(); h++)
            cout << v[j][h] << " ";
        }
      return 0;
    }
  return 0;
}