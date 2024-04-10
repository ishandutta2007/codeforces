#include <bits/stdc++.h>
using namespace std;

const bool testing = 0;
const int N = 1e6+5;
bool testvals[N];
bool is_prime[N];
bool is_squarefree[N];
int radical[N];
int lpf[N];
int answers[N]; // XOR of elements coprime to i
int xorrad[N];
vector<int> radical_preimage[N];
vector<int> rad_ordering;
vector<int> expected;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, c;

int myrandom(int n) {
  return rng()%n;
}

vector<vector<int>> form_combinations(vector<int> vals, int target) {
  // input: list of values to XOR, target value
  // output: list of subsets with XOR equal to target whose sizes cover the most
  // likely sizes
  
  vector<vector<int>> ans;
  set<int> seensizes;
  int k = vals.size();
  if (k < 8) {
    for (int mask = 0; mask < (1<<k); mask++) {
      int sum = 0;
      vector<int> used_vals;
      for (int i = 0; i < k; i++) {
        if (mask&(1<<i)) {
          sum ^= vals[i];
          used_vals.push_back(vals[i]);
        }
      }
      if (sum == target && !seensizes.count(used_vals.size())) {
        ans.push_back(used_vals);
        seensizes.insert(used_vals.size());
      }
    }
    //sort(ans.begin(), ans.end());
    return ans;
  }

  const int G = 288;
  assert(vals.size() < G);
  vector<vector<pair<int, bitset<G>>>> vecs(32);
  vector<pair<int, bitset<G>>> basis;
  vector<bitset<G>> nullspace;
  for (int i = 0; i < k; i++) {
    bitset<G> vec;
    vec[i] = 1;
    int val = vals[i];
    vecs[31-__builtin_clz(val)].push_back(make_pair(val, vec));
  }

  for (int j = 31; j >= 0; j--) {
    if (vecs[j].size()) {
      pair<int, bitset<G>> basis_element = vecs[j].back();
      vecs[j].pop_back();
      basis.push_back(basis_element);
      for (pair<int, bitset<G>> other: vecs[j]) {
        int newval = other.first^basis_element.first;
        bitset<G> newvec = other.second^basis_element.second;
        if (!newval) {
          nullspace.push_back(newvec);
        }
        else {
          vecs[31-__builtin_clz(newval)].push_back(make_pair(newval, newvec));
        }
      }
    }
  }
  /*
  for (pair<int, bitset<G>> p: basis) {
    cout << p.first << " " << p.second << '\n';
  }
  for (bitset<G> v: nullspace) {
    cout << v << '\n';
  }
  */

  bitset<G> seed;
  for (pair<int, bitset<G>> vec: basis) {
    if (!target) break;
    if (__builtin_clz(target) == __builtin_clz(vec.first)) {
      target ^= vec.first;
      seed ^= vec.second;
    }
  }

  int trials = 3*k;
  while (trials--) {
    bitset<G> solution = seed;
    for (bitset<G> vec: nullspace) {
      if (rng()&1) {
        solution ^= vec;
      }
    }
    int sz = solution.count();
    if (!seensizes.count(sz)) {
      vector<int> used_vals;
      for (int i = 0; i < k; i++) {
        if (solution[i]) {
          used_vals.push_back(vals[i]);
        }
      }
      ans.push_back(used_vals);
      seensizes.insert(sz);
    }
  }
  //sort(ans.begin(), ans.end());
  return ans;
}

void attempt_to_solve() {
  int k = rad_ordering.size();
  vector<int> ans;
  for (int i = 0; i < k; i++) {
    int e = expected[i];
    int rad = rad_ordering[i];
    vector<vector<int>> candidates = form_combinations(radical_preimage[rad], xorrad[rad]);
    int best = -1e9;
    int bestindex = -1;
    for (int j = 0; j < (int)candidates.size(); j++) {
      if (abs<int>(ans.size() + candidates[j].size()-e) < abs<int>(ans.size() + best-e)) {
        best = candidates[j].size();
        bestindex = j;
      }
    }
    for (int val: candidates[bestindex]) ans.push_back(val);
  }

  if (ans.size() == n) {
    sort(ans.begin(), ans.end());
    for (int val: ans) cout << val << ' ';
    cout << endl;
    exit(0);
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> c >> n;
  for (int i = 1; i < N; i++) {
    is_prime[i] = 1;
    is_squarefree[i] = 1;
  }
  is_prime[1] = 0;
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) {
      lpf[i] = i;
      for (int j = 2*i; j < N; j += i) {
        is_prime[j] = 0;
        lpf[j] = i;
      }
      for (long long j = 1LL * i*i; j < N; j += 1LL*i*i) {
        is_squarefree[j] = 0;
      }
    }
  }

  radical[1] = 1;
  for (int i = 1; i <= c; i++) {
    if (i > 1) {
      int p = lpf[i];
      if (lpf[i/p] == p) radical[i] = radical[i/p];
      else radical[i] = p*radical[i/p];
    }
    radical_preimage[radical[i]].push_back(i);
  }

  if (testing) {
    for (int i = 1; i <= n; i++) testvals[i] = 1;
    random_shuffle(testvals+1, testvals+c+1, myrandom);

    cout << "Test case:\n";
    for (int i = 1; i <= c; i++) {
      if (testvals[i]) cout << i << ' ';
    }
    cout << '\n';
  }

  /*
  for (pair<int, vector<int>> p: form_combinations(radical_preimage[30], 6)) {
    cout << p.first << ' ';
    for (int val: p.second) {
      //cout << val << ' ';
    }
    cout << '\n';
  }
  */

  int q = accumulate(is_squarefree+1, is_squarefree+c+1, 0);
  cout << q << endl;
  for (int i = 1; i <= c; i++) {
    if (is_squarefree[i]) cout << i << ' ';
  }
  cout << endl;
  
  if (testing) {
    for (int i = 1; i <= c; i++) {
      if (testvals[i]) {
        answers[radical[i]] ^= i;
      }
    }
    for (int i = c; i >= 1; i--) {
      for (int j = 2*i; j <= c; j+= i) {
        answers[i] ^= answers[j];
      }
    }
    for (int i = c; i >= 2; i--) {
      for (int j = 2*i; j <= c; j += i) {
        if (is_squarefree[j]) answers[j] ^= answers[i];
      }
    }
    for (int i = 2; i <= c; i++) {
      if (is_squarefree[i]) answers[i] ^= answers[1];
    }
  }


  else {
    for (int i = 1; i <= c; i++) {
      if (is_squarefree[i]) {
        cin >> answers[i];
      }
    }
  }

  for (int i = 2; i <= c; i++) {
    if (is_squarefree[i]) xorrad[i] = answers[i]^answers[1];
  }
  // xorrad[i] is the XOR of all numbers which share a prime divisor with i
  
  xorrad[1] = answers[1];
  for (int i = 2; i <= c; i++) {
    for (int j = 2*i; j <= c; j += i) {
      if (is_squarefree[j]) xorrad[j] ^= xorrad[i];
    }
  }
  // xorrad[i] is the XOR of all numbers which are a multiple of i

  for (int i = 1; i <= c; i++) {
    for (int j = 2*i; j <= c; j += i) {
      xorrad[i] ^= xorrad[j];
    }
  }
  // xorrad[i] is the XOR of all numbers with radical equal to i

  vector<pair<int, int>> radical_with_size;
  for (int i = 1; i <= c; i++) {
    if (is_squarefree[i]) {
      radical_with_size.push_back({radical_preimage[i].size(), i});
    }
  }
  sort(radical_with_size.begin(), radical_with_size.end());
  int k = radical_with_size.size();
  expected.resize(k);
  rad_ordering.resize(k);
  int tot = 0;
  for (int i = 0; i < k; i++) {
    tot += radical_with_size[i].first;
    expected[i] = 1LL*n*tot/c;
    rad_ordering[i] = radical_with_size[i].second;
  }

  int trials = 5;
  while (trials--) {
    attempt_to_solve();
  }
  cout << "failed\n";
  assert(0);
}