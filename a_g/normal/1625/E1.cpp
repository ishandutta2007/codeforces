#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;
const int K = 22;
bool s[N];
int partner[N];
int parent[N];
int children[N];

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

long long c2(int k) {
  return 1LL * k * (k-1)/2;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  string str;
  cin >> n >> q >> str;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(') s[i+1] = 1;
  }

  vector<int> left_parens;
  partner[0] = n+1;
  partner[n+1] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i]) {
      parent[i] = (left_parens.size() ? left_parens.back() : 0);
      children[parent[i]]++;
      left_parens.push_back(i);
    }
    else {
      if (left_parens.size()) {
        int l = left_parens.back();
        partner[l] = i;
        partner[i] = l;
        left_parens.pop_back();
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] && !partner[parent[i]]) parent[i] = 0;
  }

  fenwick<int> ft(n+2);
  fenwick<long long> ft2(n+2);
  for (int i = 1; i <= n; i++) {
    if (s[i] && partner[i]) {
      ft.add(i, 1);
      ft.add(partner[parent[i]], -1);
      ft2.add(i, c2(children[i]+1));
    }
  }

  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {

    }
    else {
      int groups = ft.query(r) - ft.query(l) + 1;
      long long ans = c2(groups+1) + ft2.query(r) - ft2.query(l-1);
      cout << ans << '\n';
    }
  }
}