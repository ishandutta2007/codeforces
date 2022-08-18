#include <iostream>
#include <map>

using namespace std;

int axor (int u, int v) {
  u++; v++;
  cout << "XOR " << u << " " << v << endl;
  int ans;
  cin >> ans;

  if (ans == -1) {
    exit(0);
  }
  return ans;
}

int aand (int u, int v) {
  u++; v++;
  cout << "AND " << u << " " << v << endl;
  int ans;
  cin >> ans;

  if (ans == -1) {
    exit(0);
  }
  return ans;
}

const int MAX_N = 1 << 16;

int arr [MAX_N];

int blog (int n) {
  return 31 - __builtin_clz(n);
}

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  for (int i = 1; i < n; i++) {
    arr[i] = axor(0, i);
  }

  map<int, int> pos;
  pair<int, int> match = make_pair(-1, -1);
  for (int i = 0; i < n; i++) {
    if (pos.count(arr[i])) {
      match = make_pair(pos[arr[i]], i);
      break;
    } else {
      pos[arr[i]] = i;
    }
  }

  if (match.first != -1) {
    int u = match.first;
    int v = match.second;

    int val = aand(u, v);
    int fval = val ^ arr[u];
    for (int i = 0; i < n; i++) {
      arr[i] ^= fval;
    }
  } else {
    int lastmask = 1 << (blog(n) - 1);
    int othmask = lastmask - 1;
    
    int rothmask = aand(pos[lastmask], 0) & othmask;
    int rlastmask = aand(pos[othmask], 0) & lastmask;
    int fval = rothmask | rlastmask;
    for (int i = 0; i < n; i++) {
      arr[i] ^= fval;
    }
  }

  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}