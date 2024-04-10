#ifndef LOCAL
#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#endif
#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a < b) ? b : a

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
  for (auto &el : arr) {
    in >> el;
  }
  return in;
}

template<typename T1, typename T2> 
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
  for (auto &el : arr) {
    out << el << " ";
  }
  return out;
}

template<typename T1, typename T2> 
ostream &operator>>(ostream &out, pair<T1, T2> &p) {
  out << p.first << " " << p.second;
  return out;
}

bool cmp(string a, string b) {
  return a.size() < b.size();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  cout << "? 1 1" << endl;
  char s0;
  cin >> s0;
  if (n == 1) {
    cout << "! ";
    cout << s0 << endl;
    return 0;
  }
  multiset<string> s1;
  cout << "? 1 " << n << endl;
  for (int i = 0; i < n * (n + 1) / 2; i++) {
    string sss;
    cin >> sss;
    sort(sss.begin(), sss.end());
    s1.insert(sss);
  }
  cout << "? 2 " << n << endl;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    string sss;
    cin >> sss;
    sort(sss.begin(), sss.end());
    s1.erase(s1.find(sss));
  }
  vector<string> ss;
  for (auto & el : s1) {
    ss.push_back(el);
  }
  sort(ss.begin(), ss.end(), cmp);
  cout << "! ";
  cout << s0;
  assert((int) ss.size() == n);
  for (int i = 1; i < n; i++) {
    multiset<char> ms;
    for (auto &el : ss[i]) {
      ms.insert(el);
    }
    for (auto &el : ss[i - 1]) {
      ms.erase(ms.find(el));
    }
    assert(ms.size() == 1);
    cout << *ms.begin();
  }
  cout << endl;
}