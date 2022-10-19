#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool is_power (ll a) {
  return (a & (a-1)) == 0;
}

int ilog2 (ll a) {
  int ans = 0;
  while (a >>=1) {
    ans++;
  }
  return ans;
}

int main () {
  int n;
  cin >> n;
  vector<int> counts(64);
  vector<ll> extras;
  for (int i = 0; i < n; i++) {
    ll val;
    cin >> val;
    if (is_power(val)) counts[ilog2(val)]++;
    else extras.push_back(val);
  }
  vector<int> groups;
  while (counts[0] > 0) {
    int i = 0;
    while (counts[i+1] > 0) i++;
    groups.push_back(i);
    for (int j = 0; j <= i; j++) counts[j]--;
  }
  for (int i = 0; i < 64; i++) {
    for (int j = 0; j < counts[i]; j++) {
      extras.push_back(1LL<<i);
    }
  }
  if (extras.size() > groups.size()) {
    cout << -1 << endl;
    return 0;
  }
  sort(extras.begin(), extras.end(), greater<ll>());
  for (int i = 0; i < extras.size(); i++) {
    if (1LL<<(groups[i]+1) < extras[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  vector<int> answers;
  int m = extras.size();
  while (m <= groups.size()) {
    answers.push_back(groups.size());
    m += groups.back()+1;
    groups.pop_back();
  }
  reverse(answers.begin(), answers.end());
  for (int i: answers) cout << i << " ";
  cout << endl;
}