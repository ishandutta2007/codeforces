#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  ll ans;
  cin >> ans;
  if (ans == -1) exit(0);
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    unordered_map<int, ll> answers;
    answers[n] = query(1, n);
    ll total = answers[n];

    // find k
    int low = 1;
    int high = n;
    while (high - low > 1) {
      int mid = (low + high)/2;
      answers[mid] = query(1, mid);
      ll q = answers[mid];
      if (q == total) high = mid;
      else low = mid;
    }
    int k = high;
    ll d = total-answers[k-1];
    int j = k-d;
    ll rem = total - (d*(d+1))/2;
    // a choose 2 = rem
    int a = (round(sqrt(8*rem+1))+1)/2;
    int i = j-a;

    cout << "! " << i << " " << j << " " << k << endl;
  }
}