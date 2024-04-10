#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const sigma = 60;
int f(ll number){
  for(int i = 60; 0 <= i; i--)
    if(0 < ((1LL << i) & number))
      return i;
  return 0;
}

vector<ll> v[1 + sigma];

vector<ll> mymerge(vector<ll> v1, vector<ll> v2, ll bit){
  ll result = 0;
  int ptr1 = 0, ptr2 = 0;

  vector<ll> sol;
  while(ptr1 < v1.size() || ptr2 < v2.size()){
    if(ptr2 < v2.size() && 0 == ((1LL << bit) & result)){
      result ^= v2[ptr2++];
      sol.push_back(v2[ptr2 - 1]);
    } else if(ptr1 < v1.size()){
      result ^= v1[ptr1++];
      sol.push_back(v1[ptr1 - 1]);
    } else {
      cout << "No";
      exit(0);
    }
  }
  return sol;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> sol;
  for(int i = 1;i <= n; i++){
    ll val;
    cin >> val;
    v[f(val)].push_back(val);
  }
  for(int i = 60; 0 <= i; i--)
    sol = mymerge(sol, v[i], i);
  cout << "Yes\n";
  for(int i = 0; i < sol.size(); i++)
    cout << sol[i] << " ";
  return 0;
}