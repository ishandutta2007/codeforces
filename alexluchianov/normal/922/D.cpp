#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;

struct str{
  int s;
  int h;
  bool operator < (str const &a) const{
    return 1LL * a.s * h < 1LL * s * a.h;
  }
};

vector<str> v;


int main()
{
  int n;
  cin >> n;
  ll result = 0;

  for(int i = 1 ; i <= n ; i++){
    string s;
    cin >> s;
    str a = {0 , 0};

    for(int i = 0 ; i < s.size() ; i++){
      if(s[i] == 's')
        a.s++;
      else {
        a.h++;
        result += a.s;
      }
    }
    v.push_back(a);
  }
  sort(v.begin() , v.end());
  int totals = 0;
  for(int i = 0 ; i < v.size() ;i++){
    result += 1LL * totals * v[i].h;
    totals += v[i].s;
  }
  cout << result;
  return 0;
}