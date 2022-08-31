#include <iostream>
#include <deque>

using namespace std;

const int MAX_N = 200005;

typedef long long ll;

pair<int, int> small_ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int length, queryc;
  cin >> length >> queryc;

  deque<int> arr (length);
  int mx = -1;
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }

  int last_op = 0;
  for (int i = 1; arr[0] != mx; i++) {
    last_op = i;
    int a = arr[0];
    arr.pop_front();
    int b = arr[0];
    arr.pop_front();

    small_ans[i] = make_pair(a, b);
    if (a > b) {
      arr.push_front(a);
      arr.push_back(b);
    } else {
      arr.push_front(b);
      arr.push_back(a);
    }
  }

  for (int i = 0; i < queryc; i++) {
    ll query;
    cin >> query;

    if (query <= last_op) {
      cout << small_ans[query].first << " " << small_ans[query].second << '\n';
    } else {
      int a = arr[0];
      int b = arr[1 + (query - last_op - 1) % ((int) arr.size() - 1)];
      cout << a << " " << b << '\n';
    }
  }
}