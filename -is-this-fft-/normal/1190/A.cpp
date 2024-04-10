#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Fenwick {
  vector<ll> tree;
  
public:
  Fenwick (ll _length) {
    tree = vector<ll> (_length);
  }
  
  void add (ll idx, ll val) {
    for (ll i = idx; i < (ll) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  ll get (ll idx) {
    ll sum = 0;
    for (ll i = idx; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }
};

const ll MAX_N = 100005;
ll itemNo [MAX_N];

int main () {
  ll itemc;
  ll specialc, pagelen;
  cin >> itemc >> specialc >> pagelen;

  for (ll i = 1; i <= specialc; i++) {
    cin >> itemNo[i];
    itemNo[i]--;
  }

  Fenwick fenwick (specialc + 5);

  ll curPos = 1;
  ll ans = 0;
  while (curPos <= specialc) {
    ll curPage = (itemNo[curPos] + fenwick.get(curPos)) / pagelen;
    // cout << curPos << " " << curPage << endl;
    ll lastPos = curPos + 1;
    for (lastPos = curPos + 1; lastPos <= specialc && (itemNo[lastPos] + fenwick.get(lastPos)) / pagelen == curPage; lastPos++) {}
    for (ll i = curPos; i < lastPos; i++) {
      fenwick.add(i, -1);
    }
    ans++;
    curPos = lastPos;
  }

  cout << ans << endl;
}