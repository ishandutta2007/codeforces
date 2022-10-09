#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

using ll = long long;
using ld = long double;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
ld const inf = 100000000000;

ld v[1 + nmax], pref[1 + nmax];

struct Line{
  ld a;
  ld b;
  ld eval(ld x){
    return a * x + b;
  }
  bool operator < (Line const &oth) const{
    return a < oth.a;
  }
};

ld intersect(Line a, Line b){
  return (b.b - a.b) / (a.a - b.a);
}

class CHT{
private:
  int format;
  /*
  is 0 if we want the minimum
  is 1 if we want the maximum
  */
  vector<Line> v;
public:
  vector<ld> points;
  vector<Line> st;
  CHT(int format, vector<Line> v){
    this->format = format;
    this->v = v;
  }

  void precompute(){
    sort(v.begin(), v.end());
    if(format == 0)
      reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
      while(1 < st.size() && intersect(st[st.size() - 1], v[i]) <= points.back()) {
        st.pop_back();
        points.pop_back();
      }
      if(0 < st.size())
        points.push_back(intersect(st.back(), v[i]));
      else
        points.push_back(-inf);
      st.push_back(v[i]);
    }
  }

  ld query(ld x){
    int pos = 0;
    for(int step = (1 << 20); 0 < step; step /= 2)
      if(pos + step < st.size() && points[pos + step] <= x)
        pos += step;
    return st[pos].eval(x);
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= n; i++)
    pref[i] = pref[i - 1] + v[i];
  vector<Line> myfunctions;
  for(int i = 0; i <= n; i++) {
    myfunctions.push_back({-i, pref[i]});
  }

  CHT fmin(0, myfunctions);
  CHT fmax(1, myfunctions);

  fmin.precompute();
  fmax.precompute();
  vector<ld> samples;
  for(int i = 0; i < fmin.points.size(); i++)
    samples.push_back(fmin.points[i]);
  for(int i = 0; i < fmax.points.size(); i++)
    samples.push_back(fmax.points[i]);

  ld result = inf;

  for(int i = 0; i < samples.size(); i++) {
    ld result2 = fmax.query(samples[i]) - fmin.query(samples[i]);
    result = MIN(result, result2);
  }
  cout << setprecision(6) << fixed << result;
  //*/
  return 0;
}