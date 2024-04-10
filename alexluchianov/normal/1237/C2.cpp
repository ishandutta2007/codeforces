#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 50000;
struct Point{
  int x;
  int y;
  int z;
  int ind;
  bool operator < (Point const &a) const{
    if(x != a.x)
      return x < a.x;
    else if(y != a.y)
      return y < a.y;
    else if(z != a.z)
      return z < a.z;
  }
};
vector<Point> v;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    v.push_back({x, y, z, i});
  }
  sort(v.begin(), v.end());
  vector<Point> v2;

  for(int i = 0; i < v.size(); i++){
    if(0 < v2.size() && v2.back().x == v[i].x && v2.back().y == v[i].y) {
      cout << v2.back().ind << " " << v[i].ind << '\n';
      v2.pop_back();
    } else
      v2.push_back(v[i]);
  }
  vector<Point> v3;
  for(int i = 0; i < v2.size(); i++){
    if(0 < v3.size() && v3.back().x == v2[i].x) {
      cout << v3.back().ind << " " << v2[i].ind << '\n';
      v3.pop_back();
    } else
      v3.push_back(v2[i]);
  }
  for(int i = 0; i < v3.size(); i += 2)
    cout << v3[i].ind << " " << v3[i + 1].ind << '\n';

  return 0;
}