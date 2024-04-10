#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    T query(int index) {
      T sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<long long> s(n+1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s[i+1] = s[i]+x;
    if (s[i+1] < 0) {
      cout << "-1\n";
      return 0;
    }
  }
  if (*max_element(s.begin(), s.end()) != s[n]) {
    cout << "-1\n";
    return 0;
  }
  vector<long long> _s = s; 
  sort(_s.begin(), _s.end());
  _s.resize(unique(_s.begin(), _s.end())-_s.begin());
  fenwick<int> fen(n+5);
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    int k = lower_bound(_s.begin(), _s.end(), s[i])-_s.begin()+1;
    //cout << s[i] << ' '<< k << '\n';
    ans += i-fen.query(k);
    fen.add(k, 1);
  }
  cout << ans << '\n';
}