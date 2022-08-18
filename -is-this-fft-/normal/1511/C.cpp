#include <iostream>
#include <deque>

using namespace std;

const int MAX_N = 55;

bool seen [MAX_N];
int add [MAX_N];

int query (deque<int> &deck, int u) {
  int ans = add[u];
  add[u] = 0;

  int pos = -1;
  for (int i = 0; i < (int) deck.size(); i++) {
    if (deck[i] == u) {
      pos = i;
      break;
    }
  }
  deck.erase(deck.begin() + pos);
  deck.push_front(u);

  return ans + pos;
}

int main () {
  int n, qc;
  cin >> n >> qc;

  deque<int> deck;
  int cur_add = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (!seen[x]) {
      deck.push_back(x);
      add[x] = cur_add;
      seen[x] = true;
    } else {
      cur_add++;
    }
  }

  for (int i = 0; i < qc; i++) {
    int q;
    cin >> q;

    cout << 1 + query(deck, q) << " "; 
  }
  cout << '\n';
}