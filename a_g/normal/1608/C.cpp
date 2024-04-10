#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<pii> ap(n);
    vector<pii> bp(n);
    for (int i = 0; i < n; i++) {
      ap[i] = {a[i], i};
      bp[i] = {b[i], i};
    }
    sort(ap.begin(), ap.end());
    sort(bp.begin(), bp.end());
    int minapower = a[bp[n-1].second];
    int minbpower = b[ap[n-1].second];
    int aindex = n-1;
    int bindex = n-1;
    while (ap[aindex].first > minapower || bp[bindex].first > minbpower) {
      while (ap[aindex].first > minapower) {
        aindex -= 1;
        minbpower = min(minbpower, b[ap[aindex].second]);
      }
      while (bp[bindex].first > minbpower) {
        bindex -= 1;
        minapower = min(minapower, a[bp[bindex].second]);
      }
    }
    for (int i = 0; i < n; i++) {
      cout << (a[i] >= minapower || b[i] >= minbpower ? 1 : 0);
    }
    cout << endl;
  }
}