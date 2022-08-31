#include <iostream>

using namespace std;

const int maxn = 140000;
const int inf = 1023456789;

int xl [maxn], xr [maxn], yl [maxn], yr [maxn];
int prefxl [maxn], prefxr [maxn], prefyl [maxn], prefyr [maxn];
int suffxl [maxn], suffxr [maxn], suffyl [maxn], suffyr [maxn];

int main () {
  ios::sync_with_stdio(false);
  
  int rectcnt;
  cin >> rectcnt;

  xl[0] = -inf;
  xr[0] = inf;
  yl[0] = -inf;
  yr[0] = inf;
  for (int i = 1; i <= rectcnt; i++) {
    cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
  }
  xl[rectcnt + 1] = -inf;
  xr[rectcnt + 1] = inf;
  yl[rectcnt + 1] = -inf;
  yr[rectcnt + 1] = inf;

  prefxl[0] = -inf;
  prefxr[0] = inf;
  prefyl[0] = -inf;
  prefyr[0] = inf;
  for (int i = 1; i <= rectcnt + 1; i++) {
    prefxl[i] = max(prefxl[i - 1], xl[i]);
    prefxr[i] = min(prefxr[i - 1], xr[i]);
    prefyl[i] = max(prefyl[i - 1], yl[i]);
    prefyr[i] = min(prefyr[i - 1], yr[i]);
  }    

  suffxl[rectcnt + 1] = -inf;
  suffxr[rectcnt + 1] = inf;
  suffyl[rectcnt + 1] = -inf;
  suffyr[rectcnt + 1] = inf;
  for (int i = rectcnt; i >= 0; i--) {
    suffxl[i] = max(suffxl[i + 1], xl[i]);
    suffxr[i] = min(suffxr[i + 1], xr[i]);
    suffyl[i] = max(suffyl[i + 1], yl[i]);
    suffyr[i] = min(suffyr[i + 1], yr[i]);
  }    

  for (int i = 1; i <= rectcnt; i++) {
    int curxl = max(prefxl[i - 1], suffxl[i + 1]);
    int curxr = min(prefxr[i - 1], suffxr[i + 1]);
    int curyl = max(prefyl[i - 1], suffyl[i + 1]);
    int curyr = min(prefyr[i - 1], suffyr[i + 1]);

    if (curxl <= curxr && curyl <= curyr) {
      cout << curxl << " " << curyl << endl;
      return 0;
    }
  }
}