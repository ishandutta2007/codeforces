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

struct fenwich {
  vector<int> count;

  fenwich(int n) {
    count = vector<int>(n + 1, 0);
  }

  int zrs(int x) {
    return (x & (x - 1)) ^ x;
  }

  void add(int pos, int v) {
    while (pos < count.size()) {
      count[pos] += v;
      pos += zrs(pos);
    }
  }

  int query(int pos) {
    int answer = 0;
    while (pos > 0) {
      answer += count[pos];
      pos -= zrs(pos);
    }
    return answer;
  }
};

typedef vector< pair<int, int> > spect_array;

int t, n, m;
spect_array spect;
fenwich seats(0);

ll solve_row(spect_array::iterator begin, spect_array::iterator end) {
  auto j = begin;
  for (auto i = begin; i != end; i = j) {
    for (j = i; (j != end) && (i->first == j->first); j++);
    reverse(i, j);
  }

  int answer = 0;
  for (auto i = begin; i != end; i++) {
    int pos = i->second + 1;
    answer += seats.query(pos);
    seats.add(pos, 1);
  }

  for (auto i = begin; i != end; i++) {
    int pos = i->second + 1;
    seats.add(pos, -1);
  }

  return answer;
}

int main()
{
  //freopen("test.in", "r", stdin);

  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    cin >> n >> m;
    spect.resize(n * m);
    for (int i = 0; i < n * m; i++) {
      cin >> spect[i].first;
      spect[i].second = i;
    }

    sort(spect.begin(), spect.end());

    ll answer = 0;
    seats = fenwich(n * m);
    for (int i = 0; i < n; i++) 
      answer += solve_row(spect.begin() + i * m, spect.begin() + (i + 1) * m);      

    cout << answer << '\n';
  }


  return 0;
}