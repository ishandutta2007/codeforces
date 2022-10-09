#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

vector<int> v;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++){
    int a;
    cin >> a;
    v.push_back(a);
  }
  v.push_back(0);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 1; i < v.size(); i++){
    if(0 < k){
      cout << v[i] - v[i - 1] << '\n';
      k--;
    }
  }
  while(0 < k){
    cout << 0 << '\n';
    k--;
  }
  return 0;
}