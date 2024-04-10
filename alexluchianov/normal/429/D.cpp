#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

using ll = long long;

int const nmax = 100000;
ll const inf = 1000000000000000000;
struct Point {
  ll x;
  ll y;
  bool operator < (Point const &a) const{
    if(y != a.y)
      return y < a.y;
    else
      return x < a.x;
  }
};

ll dist(Point a, Point b){

  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool compare(Point const &a, Point const &b){
  if(a.x != b.x)
    return a.x < b.x;
  else
    return a.y < a.y;
}

class NearestTwo{
public:
  vector<Point> v;
  void insertPoint(Point a){
    v.push_back(a);
  }
  ll solve(){
    sort(v.begin(), v.end(), compare);
    if(v.size() < 2)
      return 0;

    ll result = dist(v[0], v[1]);
    set<Point> st;


    for(int i = 0; i < v.size(); i++){

      //cout << v[i].x << " " << v[i].y << '\n';

      set<Point>::iterator it;
      it = st.lower_bound(v[i]);
      while(it != st.end()){
        if(result < (it->x - v[i].x) * (it->x - v[i].x)) {
          st.erase(it++);
        } else {
          result = min(result, dist(v[i], *it));
          if(result < (v[i].y - it->y) * (v[i].y - it->y))
            break;
          it++;
        }
      }
      it = st.lower_bound(v[i]);
      if(it != st.begin())
        it--;

      while(it != st.begin()){
        if(result < (it->x - v[i].x) * (it->x - v[i].x)) {
          st.erase(it--);
        } else {
          result = min(result, dist(v[i], *it));
          if(result < (v[i].y - it->y) * (v[i].y - it->y))
            break;
          it--;
        }
      }
      if(it == st.begin() && 0 < st.size())
        result = min(result, dist(v[i], *it));

      st.insert(v[i]);
    }
    return result;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  NearestTwo solver;
  int sum = 0;
  for(int i = 1;i <= n; i++){
    int x;
    cin >> x;
    sum += x;
    solver.insertPoint({i, sum});
  }

  ll result;
  result = solver.solve();
  //cout << setprecision(6) << fixed << result << " " << result * result << '\n';

  cout << result;
  return 0;
}