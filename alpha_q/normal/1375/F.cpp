#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[3], id[3];

int main() {
  id[1] = 1, id[2] = 2;
  cin >> a[0] >> a[1] >> a[2];
  cout << "First" << endl; 
  sort(id, id + 3, [] (int i, int j) {return a[i] < a[j];});
  cout << 2 * a[id[2]] - a[id[0]] - a[id[1]] << endl;
  int rep; cin >> rep; --rep;
  if (rep == -1) return 0;
  if (rep == id[0]) {
    cout << a[id[2]] - a[id[1]] << endl;
    cin >> rep; --rep; assert(rep == -1); return 0;
  }
  if (rep == id[1]) {
    cout << a[id[2]] - a[id[0]] << endl;
    cin >> rep; --rep; assert(rep == -1); return 0;
  }
  a[id[2]] += 2 * a[id[2]] - a[id[0]] - a[id[1]];
  cout << 2 * a[id[2]] - a[id[0]] - a[id[1]] << endl;
  cin >> rep; --rep;
  if (rep == -1) return 0;
  if (rep == id[0]) {
    cout << a[id[2]] - a[id[1]] << endl;
    cin >> rep; --rep; assert(rep == -1); return 0;
  }
  if (rep == id[1]) {
    cout << a[id[2]] - a[id[0]] << endl;
    cin >> rep; --rep; assert(rep == -1); return 0;
  }
  assert(false);
  return 0;
}

// a-k, a, a+k


// a < b < c


// a, b, c

// give 2c-a-b

// add b --> a, c, 2c-a --> give c-a --> win

// add a --> b, c, 2c-b --> give c-b --> win

// add c --> a, b, 3c-a-b