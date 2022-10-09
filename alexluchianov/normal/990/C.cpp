#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <map>

using namespace std;

#define ll long long
#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;

struct Bracket{
  int stmin;
  int st;
  bool operator < (Bracket const &a) const {
    if(stmin != a.stmin)
      return stmin < a.stmin;
    else
      return st < a.st;
  }
  bool operator == (Bracket const &a) const {
    return ((stmin == a.stmin) && (st == a.st));
  }
};
Bracket v[5 + nmax];
map<Bracket , int> frec;

char line[5 + nmax];
Bracket computeBracket(){
  cin >> line;
  int n = strlen(line);
  Bracket a = {0 , 0};
  for(int i = 0 ; i < n ;i++){
    if(line[i] == '(')
      a.st++;
    else
      a.st--;
    a.stmin = MIN(a.stmin , a.st);
  }
  return a;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1 ; i <= n ;i++){
    v[i] = computeBracket();
    frec[v[i]]++;
  }
  ll result = 0;
  for(int i = 1; i <= n ;i++){
    if(0 == v[i].stmin){
      result += frec[{-v[i].st , -v[i].st}];
    }
  }
  cout << result;
  return 0;
}