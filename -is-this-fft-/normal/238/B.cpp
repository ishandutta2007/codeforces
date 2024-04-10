#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 5;
const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int calc (const vector<int> &A, const vector<int> &B, int H) {
  int mn = INF;
  int mx = 0;
  if (!A.empty() && !B.empty()) {
    mn = min(mn, A[0] + B[0] + H);
    mx = max(mx, A.back() + B.back() + H);
  }

  if (A.size() > 1) {
    mn = min(mn, A[0] + A[1]);
    mx = max(mx, A.back() + *next(A.rbegin()));
  }

  if (B.size() > 1) {
    mn = min(mn, B[0] + B[1]);
    mx = max(mx, B.back() + *next(B.rbegin()));
  }

  return mx - mn;
}

int sol [MAX_N];

// type 1 - everyone in A
int calc_t1 (const vector<pair<int, int>> &ord, int H) {
  vector<int> A, B;
  for (int i = 0; i < (int) ord.size(); i++) {
    A.push_back(ord[i].first);
  }

  return calc(A, B, H);
}

void render_t1 (const vector<pair<int, int>> &ord) {
  return;
}

// type 2 - the first in B
int calc_t2 (const vector<pair<int, int>> &ord, int H) {
  vector<int> A, B;
  B.push_back(ord[0].first);
  for (int i = 1; i < (int) ord.size(); i++) {
    A.push_back(ord[i].first);
  }

  return calc(A, B, H);
}

void render_t2 (const vector<pair<int, int>> &ord) {
  sol[ord[0].second] = 1;
}

// type 3 - first and third in B
int calc_t3 (const vector<pair<int, int>> &ord, int H) {
  vector<int> A, B;
  B.push_back(ord[0].first);
  A.push_back(ord[1].first);
  B.push_back(ord[2].first);
  for (int i = 3; i < (int) ord.size(); i++) {
    A.push_back(ord[i].first);
  }

  return calc(A, B, H);
}

void render_t3 (const vector<pair<int, int>> &ord) {
  sol[ord[0].second] = 1;
  sol[ord[2].second] = 1;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, H;
  cin >> n >> H;

  vector<pair<int, int>> ord;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ord.push_back(make_pair(arr[i], i));
  }

  sort(ord.begin(), ord.end());

  pair<int, int> ans = make_pair(INF, 0);
                                 
  ans = min(ans, make_pair(calc_t1(ord, H), 1));
  ans = min(ans, make_pair(calc_t2(ord, H), 2));
  if (n >= 3) {
    ans = min(ans, make_pair(calc_t3(ord, H), 3));
  }

  if (ans.second == 1) {
    render_t1(ord);
  } else if (ans.second == 2) {
    render_t2(ord);
  } else {
    render_t3(ord);
  }

  cout << ans.first << endl;
  for (int i = 0; i < n; i++) {
    cout << sol[i] + 1 << " ";
  }
  cout << endl;
}