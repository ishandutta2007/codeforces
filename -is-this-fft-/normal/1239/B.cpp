#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 6e5 + 5;

int arr [MAX_N];

int main () {
  int n;
  cin >> n;

  string s;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') arr[i] = 1;
    else arr[i] = -1;
  }
  for (int i = n; i < 2 * n; i++) {
    if (s[i - n] == '(') arr[i] = 1;
    else arr[i] = -1;
  }

  int sum = 0;
  pair<int, int> mn = make_pair(0, 0);
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    mn = min(mn, make_pair(sum, i + 1));
  }

  if (sum != 0) {
    cout << 0 << endl;
    cout << 1 << " " << 1 << endl;
    return 0;
  }

  int sta = mn.second;
  int fin = sta + n;

  sum = 0;
  pair<int, pair<int, int>> best = make_pair(0, make_pair(0, 0));
  int c0s = 0;
  int ison = 0, cc2s = 0, curl = 0;
  for (int i = sta; i < fin; i++) {
    sum += arr[i];
    
    if (sum >= 2 && !ison) {
      ison = 1;
      cc2s = 0;
      curl = i;
    } else if (sum < 2 && ison) {
      ison = 0;
      best = max(best, make_pair(cc2s, make_pair(curl, i)));
      cc2s = 0;
    }

    if (sum == 2) cc2s++;
    if (sum == 0) c0s++;
  }
  
  best.first += c0s;
  // case 2

  sum = 0;
  int cc1s = 0;
  ison = 0;
  for (int i = sta; i < fin; i++) {
    sum += arr[i];

    if (sum >= 1 && !ison) {
      ison = 1;
      cc1s = 0;
      curl = i;
    } else if (sum < 1 && ison) {
      ison = 0;
      best = max(best, make_pair(cc1s, make_pair(curl, i)));
      cc1s = 0;
    }

    if (sum == 1) cc1s++;
  }
  
  if (best.second.first >= n) best.second.first -= n;
  if (best.second.second >= n) best.second.second -= n;
  
  cout << best.first << endl;
  cout << best.second.first + 1 << " " << best.second.second + 1 << endl;
}