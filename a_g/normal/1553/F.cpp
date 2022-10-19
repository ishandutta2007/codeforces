#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+7;

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
  fenwick<long long> z(N);
  fenwick<int> occ(N);
  long long ans = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans += 1LL*i*a - z.query(a); // a mod x
    ans += sum; // x mod a

    for (int j = a; j < N; j+=a) {
      z.add(j, a);
      ans -= 1LL*(i-occ.query(j-1))*a;
    }
    sum += a;
    occ.add(a, 1);
    cout << ans << ' ';
  }
  cout << '\n';
}