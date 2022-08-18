#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

typedef long long llong;

const int MAX_BANK = 200005;

using namespace std;

llong vals [MAX_BANK];
llong csum [MAX_BANK];
int nxt [MAX_BANK];
bool vis [MAX_BANK];

int main () {
  for (int i = 0; i < MAX_BANK; i++) {
    nxt[i] = 2 * MAX_BANK;
  }

  int bankc;
  cin >> bankc;
  
  for (int i = 0; i < bankc; i++) {
    cin >> vals[i];
    vals[i + bankc] = vals[i];
  }

  vector<pair<llong, int> > cssms;
  for (int i = 0; i < 2 * bankc; i++) {
    if (i > 0) {
      csum[i] = csum[i - 1];
    }
    csum[i] += vals[i];
    cssms.push_back(make_pair(csum[i], i));
  }

  sort(cssms.begin(), cssms.end());

  for (int i = 0; i < (int) cssms.size() - 1; i++) {
    if (cssms[i].first == cssms[i + 1].first) {
      nxt[(cssms[i].second + 1) % bankc] = min(nxt[(cssms[i].second + 1)],
                                               cssms[i + 1].second % bankc);
    }
  }

  for (int i = 0; i < bankc; i++) {
    if (vals[i] == 0) {
      nxt[i] = i;
    }
  }


  int ans = bankc;
  for (int i = 0; i < bankc; i++) {
    if (!vis[i]) {
      int cans = bankc, cur = i;
      do {
        vis[cur] = true;
        cur = (nxt[cur] + 1) % bankc;
        cans--;
      } while (cur != i);
      ans = min(ans, cans);
    }
  }

  cout << ans << endl;
}