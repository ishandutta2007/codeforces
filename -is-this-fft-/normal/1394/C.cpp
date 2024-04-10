#include <iostream>
#include <vector>

using namespace std;

#define l first
#define r second

#define N first
#define B second

const int MAX_N = 3e5 + 5;
const int INF = 1e9 + 5;

int n;
pair<int, int> arr [MAX_N];

pair<int, int> interND (int N, int D) {
  int B = N - D;
  return make_pair(N, B);
}

pair<int, int> interBD (int B, int D) {
  int N = D + B;
  return make_pair(N, B);
}

pair<int, int> interNB (int N, int B) {
  return make_pair(N, B);
}

bool ok (pair<int, int> pt, int Nmin, int Nmax, int Bmin, int Bmax, int Dmin, int Dmax) {
  int D = pt.N - pt.B;

  return Nmin <= pt.N && pt.N <= Nmax &&
    Bmin <= pt.B && pt.B <= Bmax &&
    Dmin <= D && D <= Dmax && pt != make_pair(0, 0);
}

pair<bool, pair<int, int>> inters (int D) {
  int Nmin = 0;
  int Nmax = INF;

  int Bmin = 0;
  int Bmax = INF;

  int Dmin = -INF; // values of N - B
  int Dmax = INF;

  for (int i = 0; i < n; i++) {
    Nmin = max(Nmin, arr[i].N - D);
    Nmax = min(Nmax, arr[i].N + D);

    Bmin = max(Bmin, arr[i].B - D);
    Bmax = min(Bmax, arr[i].B + D);

    Dmin = max(Dmin, arr[i].N - arr[i].B - D);
    Dmax = min(Dmax, arr[i].N - arr[i].B + D);
  }

  if (Nmin > Nmax) return make_pair(false, make_pair(0, 0));
  if (Bmin > Bmax) return make_pair(false, make_pair(0, 0));
  if (Dmin > Dmax) return make_pair(false, make_pair(0, 0));

  if (Nmin - Bmax > Dmax) return make_pair(false, make_pair(0, 0));
  // the smallest possible N - B is still too big
  if (Nmax - Bmin < Dmin) return make_pair(false, make_pair(0, 0));
  // the biggest possible N - B is still too small

  vector<pair<int, int>> cands =
    {interNB(Nmax, Bmax), interND(Nmax, Dmin), interND(Nmax, Dmax),
     interBD(Bmax, Dmin), interBD(Bmax, Dmax)};
  for (auto pr : cands) {
    if (ok(pr, Nmin, Nmax, Bmin, Bmax, Dmin, Dmax)) {
      return make_pair(true, pr);
    }
  }
  return make_pair(false, make_pair(0, 0));
}
  
int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    
    for (char c : s) {
      if (c == 'N') arr[i].N++;
      else arr[i].B++;
    }
  }

  pair<int, int> midpoint;
  if (inters(0).first) {
    midpoint = inters(0).second;
    cout << 0 << endl;
  } else {
    int ans = 0;
    for (int k = 1 << 20; k != 0; k /= 2) {
      if (!inters(ans + k).first) {
        ans += k;
      }
    }
    midpoint = inters(ans + 1).second;
    cout << ans + 1 << endl;
  }

  string ans;
  for (int i = 0; i < midpoint.N; i++) {
    ans.push_back('N');
  }
  for (int i = 0; i < midpoint.B; i++) {
    ans.push_back('B');
  }
  cout << ans << endl;
}