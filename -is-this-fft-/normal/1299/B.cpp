#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pt;
#define x first
#define y second

pt operator- (pt a, pt b) {
  return make_pair(a.x - b.x, a.y - b.y);
}

ll cross (pt a, pt b) {
  return a.x * b.y - a.y * b.x;
}

ll dot (pt a, pt b) {
  return a.x * b.x + a.y * b.y;
}

ll sq (pt a) {
  return dot(a, a);
}

const int MAX_N = 1e5 + 5;

pt arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
  }

  if (n % 2 == 1) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 0; i < n / 2; i++) {
    pt cur = arr[(i + 1) % n] - arr[i];
    pt oth = arr[(i + 1 + n / 2) % n] - arr[i + n / 2];

    if (sq(cur) != sq(oth)) {
      cout << "nO" << endl;
      return 0;
    }
  }

  for (int i = 0; i < n / 2; i++) {
    pt curf = arr[i + 1] - arr[i];
    pt curb = arr[(i + n - 1) % n] - arr[i];

    pt othf = arr[(i + 1 + n / 2) % n] - arr[i + n / 2];
    pt othb = arr[(i - 1 + n / 2) % n] - arr[i + n / 2];

    if (cross(curf, curb) != cross(othf, othb)) {
      cout << "no" << endl;
      return 0;
    }

    if (dot(curf, curb) != dot(othf, othb)) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}