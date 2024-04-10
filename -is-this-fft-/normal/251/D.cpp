#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

const int BITS = 60;

// returns the list of original ids
vector<int> reduce (const vector<ll> &orig) {
  vector<ll> basis (BITS, 0);

  vector<int> ans;
  for (int k = 0; k < (int) orig.size(); k++) {
    auto v = orig[k];
    
    for (int i = 0; i < BITS; i++) {
      if (v & 1LL << i) {
        v ^= basis[i];
      }
    }

    if (v == 0) {
      continue;
    }

    ans.push_back(k);
    int bit;
    for (int i = 0; i < BITS; i++) {
      if (v & 1LL << i) {
        bit = i;
        break;
      }
    }

    basis[bit] = v;
    for (int i = 0; i < BITS; i++) {
      if (i != bit && (basis[i] & 1LL << bit)) {
        basis[i] ^= v;
      }
    }
  }

  return ans;
}

struct Vec {
  ll val;
  ll ids;
  bool picked;

  void operator^= (Vec &oth) {
    val ^= oth.val;
    ids ^= oth.ids;
  }
};

// list of original ids again
vector<int> maximize (const vector<int> &ord, const vector<ll> &orig) {
  int n = orig.size();

  vector<Vec> state;
  for (int i = 0; i < n; i++) {
    Vec cur;
    cur.val = orig[i];
    cur.ids = 1LL << i;
    cur.picked = false;

    state.push_back(cur);
  }

  for (int b : ord) {
    int pivot = -1;
    for (int i = 0; i < n; i++) {
      if (!state[i].picked && (state[i].val & 1LL << b)) {
        pivot = i;
        break;
      }
    }

    if (pivot == -1) {
      continue;
    }

    state[pivot].picked = true;
    for (int i = 0; i < n; i++) {
      if (i != pivot && (state[i].val & 1LL << b)) {
        state[i] ^= state[pivot];
      }
    }
  }

  ll picked_bits = 0;
  for (auto v : state) {
    picked_bits ^= v.ids;
  }

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (picked_bits & 1LL << i) {
      ans.push_back(i);
    }
  }
  return ans;
}

int main () {
  int n;
  cin >> n;

  ll tot = 0;
  vector<ll> vecs (n);
  for (int i = 0; i < n; i++) {
    cin >> vecs[i];
    tot ^= vecs[i];
  }

  auto reduced_ids = reduce(vecs);
  vector<ll> reduced;
  for (auto i : reduced_ids) {
    reduced.push_back(vecs[i]);
  }

  vector<int> bit_ord;
  for (int i = BITS - 1; i >= 0; i--) {
    if (!(tot & 1LL << i)) {
      bit_ord.push_back(i);
    }
  }
  for (int i = BITS - 1; i >= 0; i--) {
    if (tot & 1LL << i) {
      bit_ord.push_back(i);
    }
  }

  auto max_red_ids = maximize(bit_ord, reduced);
  set<int> max_orig_ids;
  for (int u : max_red_ids) {
    max_orig_ids.insert(reduced_ids[u]);
  }

  for (int i = 0; i < n; i++) {
    cout << 1 + max_orig_ids.count(i) << " ";
  }
  cout << endl;
}