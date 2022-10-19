#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int firstzero = 0;
  int lastzero = 0;
  int firstone = 0;
  int lastone = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') lastzero = i;
    else lastone = i;
  }
  for (int i = n-1; i >= 0; i--) {
    if (s[i] == '0') firstzero = i;
    else firstone = i;
  }
  if (min(lastzero-firstzero, lastone-firstone) < k) {
    cout << "tokitsukaze" << endl;
    return 0;
  }
  bool draw = 0;
  if (firstzero >= k || lastzero <= n-k-1 || lastzero-firstzero > k) draw = 1;
  if (firstone >= k || lastone <= n-k-1 || lastone-firstone > k) draw = 1;
  cout << (draw ? "once again" : "quailty") << endl;
}