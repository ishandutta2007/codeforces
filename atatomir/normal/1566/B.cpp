#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

int n;
string s;

int main()
{
  //freopen("test.in", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;

    int cnt = 0;
    bool group = false;

    for (char c : s) {
      if (c == '0') {
        cnt += !group;
        group = true;
      } else {
        group = false;
      }
    }

    cout << min(2, cnt) << '\n';
  }


  return 0;
}