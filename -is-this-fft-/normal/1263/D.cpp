#include <iostream>
#include <set>
#include <string>

using namespace std;

const int MAX_N = 2e5 + 5 + 50;
const int LET = 2e5 + 5;
int letter (char c) {
  return LET + c - 'a';
}

int root [MAX_N];
int find (int u) {
  if (root[u] != u) {
    root[u] = find(root[u]);
  }
  return root[u];
}

void merge (int u, int v) {
  u = find(u);
  v = find(v);

  root[u] = v;
}

int main () {
  ios::sync_with_stdio(false);

  for (int i = 0; i < MAX_N; i++) {
    root[i] = i;
  }
  
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    string str;
    cin >> str;

    for (char c : str) {
      merge(letter(c), i);
    }
  }

  set<int> comps;
  for (int i = 0; i < length; i++) {
    comps.insert(find(i));
  }
  cout << (int) comps.size() << endl;
}