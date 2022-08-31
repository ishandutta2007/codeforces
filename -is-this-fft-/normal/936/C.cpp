#include <iostream>
#include <vector>

using namespace std;

vector<int> ops;
vector<char> shift (vector<char> v, int x) {
  ops.push_back(x);
  
  vector<char> ans;
  for (int i = 0; i < x; i++) {
    ans.push_back(v.back());
    v.pop_back();
  }

  for (int u : v) {
    ans.push_back(u);
  }
  return ans;
}

int length;
vector<char> state;
void bring (int preflen, int spos) {
  state = shift(state, length - preflen);
  state = shift(state, spos);
  state = shift(state, 1);
}

int find_target (int preflen, char target) {
  for (int i = preflen; i < length; i++) {
    if (state[i] == target) {
      return i;
    }
  }
  cout << -1 << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);
  
  cin >> length;
  state = vector<char> (length);
  vector<char> target = vector<char> (length);

  for (int i = 0; i < length; i++) {
    cin >> state[i];
  }

  for (int i = 0; i < length; i++) {
    cin >> target[i];
  }

  int mid = (length - 1) / 2, pref = 0;
  bring(pref, find_target(pref, target[mid]));
  pref++;
  for (int i = 1; true; i++) {
    if (mid + i >= length) break;
    bring(pref, find_target(pref, target[mid + i]));
    pref++;

    if (mid - i < 0) break;
    bring(pref, find_target(pref, target[mid - i]));
    pref++;
  }

  if (length % 2 == 0) {
    state = shift(state, length);
  }
  
  cout << ops.size() << endl;
  for (int u : ops) {
    cout << u << " ";
  }
  cout << endl;
}