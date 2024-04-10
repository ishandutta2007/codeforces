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

const int N = 2e5+5;
int divisors[N];
vector<pair<int, int>> queries[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    queries[l].emplace_back(r, i);
  }
  vector<long long> answers(q);

  fenwick<long long> fen(N);
  for (int l = N-1; l >= 1; l--) {
    for (int j = 2*l; j < N; j += l) {
      fen.add(j, divisors[j]);
      divisors[j]++;
    }

    for (pair<int, int>& p: queries[l]) {
      int r = p.first;
      int i = p.second;
      int d = r-l+1;
      long long ans = 1LL*d*(d-1)*(d-2)/6;
      ans -= fen.query(r);
      // multiples of 15 between ceil(5l/2) and r inclusive
      ans -= max(0, r/15-(5*l-1)/30);
      // multiples of 6 between 2l and r inclusive
      ans -= max(0, r/6-(2*l-1)/6);
      answers[i] = ans;
    }
  }
  for (int i = 0; i < q; i++) {
    cout << answers[i] << '\n';
  }
}