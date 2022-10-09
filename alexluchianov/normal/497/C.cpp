#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 100000;

struct Item{
  int type;
  int x;
  int y;
  int id;
  int pow;
  bool operator < (Item const &a) const{
    if(y != a.y)
      return y < a.y;
    else
      return type < a.type;
  }
};
int sol[1 + nmax];

set<pair<int,int>> myset;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n;
  vector<Item> v;
  for(int i = 1;i <= n; i++){
    int x, y;
    cin >> x >> y;
    v.push_back({0, x, y, i, 1});
  }
  cin >> m;
  for(int i = 1;i <= m; i++){
    int x, y, k;
    cin >> x >> y >> k;
    v.push_back({1, x, y, i, k});
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < v.size(); i++){
    Item item = v[i];
    if(item.type == 0)
      myset.insert({item.x, item.id});
    else {
      for(int h = 0; h < item.pow; h++){
        set<pair<int,int>>::iterator it = myset.lower_bound({item.x, 0});
        if(it == myset.end())
          break;
        else {
          sol[it->second] = item.id;
          myset.erase(it);
        }
      }
    }
  }
  if(myset.size() == 0){
    cout << "YES\n";
    for(int i = 1;i <= n; i++)
      cout << sol[i] << " ";
  } else
    cout << "NO\n";
  return 0;
}