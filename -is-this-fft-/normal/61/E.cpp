#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

const int MAX_CPOW = 1000005;

using namespace std;

long long fenwick [3][MAX_CPOW], length;

void fenadd (int tree, int index, long long val) {
  for (int i = index; i <= length; i += (i & -i)) {
    fenwick[tree][i] += val;
  }
}

long long fenget (int tree, int right) {
  long long ans = 0;
  for (int i = right; i > 0; i -= (i & -i)) {
    ans += fenwick[tree][i];
  }
  return ans;
}

int main () {
  int soldc;
  cin >> soldc;

  vector<int> soldiers (soldc);
  for (int i = 0; i < soldc; i++) {
    cin >> soldiers[i];
  }

  vector<int> vals = soldiers;
  sort(vals.begin(), vals.end());
  
  map<int, int> comp;
  for (int i = 0; i < soldc; i++) {
    comp[vals[i]] = i + 1;
  }

  length = soldc;
  for (int i = 0; i < soldc; i++) {
    fenadd(0, comp[soldiers[i]], 1);
    fenadd(1, comp[soldiers[i]], fenget(0, length) - fenget(0, comp[soldiers[i]]));
    fenadd(2, comp[soldiers[i]], fenget(1, length) - fenget(1, comp[soldiers[i]]));
  }

  cout << fenget(2, length) << endl;
}