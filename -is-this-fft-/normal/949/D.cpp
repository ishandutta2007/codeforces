#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int ceil (int p, int q) {
  return (p + q - 1) / q;
}

int arr [MAX_N];
int pref [MAX_N];
int suff [MAX_N];
int insp [MAX_N];

int d;
bool canrun (int a, int b) { // can run from a to b in time?
  return ceil(abs(b - a), d) <= insp[b] + 1;
}

int main () {
  ios::sync_with_stdio(false);

  int n, b;
  cin >> n >> d >> b;
  
  set<pair<int, int>> ubs;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (i == 0) {
      pref[i] = arr[i];
    } else {
      pref[i] = pref[i - 1] + arr[i];
    }
    ubs.insert(make_pair(pref[i], i));
    insp[i] = min(i, n - i - 1);
  }

  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << canrun(i, j) << " ";
    }
    cout << endl;
  }
  */

  set<pair<int, int>> subs;
  suff[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    suff[i] = arr[i] + suff[i + 1];
    subs.insert(make_pair(suff[i], -i));
  }

  vector<pair<int, int>> ltr;
  pair<int, int> last = make_pair(0, 0);
  for (int i = 0; i < ceil(n, 2); i++) {
    while (last.first < i && !canrun(last.first, i)) {
      last.first++;
      last.second = 0;
    }

    int prefn = pref[last.first] - (arr[last.first] - last.second) + b;
    if (ubs.lower_bound(make_pair(prefn, -1)) == ubs.end()) break;
    int nxt = ubs.lower_bound(make_pair(prefn, -1))->second;

    if (canrun(nxt, i)) {
      last = make_pair(nxt, arr[nxt] - (pref[nxt] - prefn));
      ltr.push_back(last);
    }
  }

  vector<pair<int, int>> rtl;
  last = make_pair(n - 1, 0);
  for (int i = n - 1; i >= ceil(n, 2); i--) {
    while (last.first > i && !canrun(last.first, i)) {
      last.first--;
      last.second = 0;
    }

    int suffn = suff[last.first] - (arr[last.first] - last.second) + b;
    if (subs.lower_bound(make_pair(suffn, -n - 1)) == subs.end()) break;
    int nxt = -subs.lower_bound(make_pair(suffn, -n - 1))->second;

    if (canrun(nxt, i)) {
      last = make_pair(nxt, arr[nxt] - (suff[nxt] - suffn));
      rtl.push_back(last);
    }
  }

  /*
  for (auto pr : ltr) {
    cout << "(" << pr.first << " " << pr.second << ") ";
  }
  cout << endl;
  
  for (auto pr : rtl) {
    cout << "(" << pr.first << " " << pr.second << ") ";
  }
  cout << endl;
  */

  int m1 = ceil(n, 2);
  int m2 = n / 2;

  int mpr = m1 - m2;

  if (ltr.empty()) {
    cout << m1 << '\n';
    return 0;
  }

  if (mpr == 1) m1--;
  
  for (int i = 0; i + mpr < (int) ltr.size() && i < (int) rtl.size(); i++) {
    int lpref = pref[ltr[mpr + i].first] - (arr[ltr[mpr + i].first] - ltr[mpr + i].second);
    int rsuff = suff[rtl[i].first] - (arr[rtl[i].first] - rtl[i].second);
    if (lpref + rsuff <= b * n) {
      m1--;
      m2--;
    } else {
      break;
    }
  }

  cout << m1 << endl;
}