#include <iostream>

using namespace std;

const int maxn = 100005;

int firstloc [maxn];
int lastloc [maxn];

int main () {
  int length, queryc;
  cin >> length >> queryc;

  for (int i = 1; i <= length; i++) {
    firstloc[i] = queryc + 1;
  }

  for (int i = 1; i <= queryc; i++) {
    int x;
    cin >> x;

    firstloc[x] = min(firstloc[x], i);
    lastloc[x] = max(lastloc[x], i);
  }
  
  long long ans = 0;
  for (int i = 1; i <= length; i++) {
    if (i > 1) {
      ans += firstloc[i] > lastloc[i - 1];
    }
    ans += (firstloc[i] == queryc + 1 && lastloc[i] == 0);
    if (i < length) {
      ans += firstloc[i] > lastloc[i + 1];
    }
  }
  cout << ans << endl;
}