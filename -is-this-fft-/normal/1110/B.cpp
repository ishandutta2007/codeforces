#include <iostream>
#include <queue>

using namespace std;

const int maxn = 100005;
int arr [maxn];

int main () {
  int brokenc, length, maxpcs;
  cin >> brokenc >> length >> maxpcs;

  int cur_len = brokenc;
  for (int i = 0; i < brokenc; i++) {
    cin >> arr[i];
  }

  priority_queue<int, vector<int>, greater<int>> Q;
  for (int i = 0; i < brokenc - 1; i++) {
    Q.push(arr[i + 1] - arr[i] - 1);
  }

  int pcs = brokenc;
  while (pcs > maxpcs) {
    int qtop = Q.top();
    Q.pop();

    cur_len += qtop;
    pcs--;
  }

  cout << cur_len << endl;
}