#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  long long total = 0;
  while (n--) {
    int a;
    cin >> a;
    if (total+a >= 0) {
      pq.push(a);
      total += a;
    }
    else if (pq.size() && pq.top() < a) {
      total += a-pq.top();
      pq.pop();
      pq.push(a);
    }
  }
  cout << pq.size() << '\n';
}