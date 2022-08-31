#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Op {
  int from, to, mul;

  Op (int _from, int _to, int _mul) :
    from(_from), to(_to), mul(_mul) {}
};

const int MAX_N = 1e4 + 5;

ll arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  if (sum % n != 0) {
    cout << -1 << '\n';
    return;
  }

  vector<Op> sol;
  for (int i = 2; i <= n; i++) {
    if (arr[i] % i != 0) {
      sol.push_back(Op(1, i, i - arr[i] % i));
      arr[i] += i - arr[i] % i;
    }
    sol.push_back(Op(i, 1, arr[i] / i));
  }

  int need = sum / n;
  for (int i = 2; i <= n; i++) {
    sol.push_back(Op(1, i, need));
  }

  cout << (int) sol.size() << '\n';
  for (Op op : sol) {
    cout << op.from << " " << op.to << " " << op.mul << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}