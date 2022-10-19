#include <bits/stdc++.h>
using namespace std;

const int K = 26;
char ans[6006];
int last[256];

char query1(int i) {
  cout << "? 1 " << i << endl;
  char c;
  cin >> c;
  return c;
}

int query2(int l, int r) {
  cout << "? 2 " << l << " " << r << endl;
  int x;
  cin >> x;
  return x;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    vector<char> to_try;
    for (char c = 'a'; c <= 'z'; c++) {
      if (last[c]) to_try.push_back(c);
    }
    sort(to_try.begin(), to_try.end(), [&] (char a, char b) {return last[a] > last[b];});
    int low = -1;
    int high = (int)to_try.size();
    while (high-low > 1) {
      int mid = (low+high)/2;
      if (query2(last[to_try[mid]], i) < mid+2) {
        high = mid;
      }
      else {
        low = mid;
      }
    }
    if (high == (int)to_try.size()) {
      ans[i] = query1(i);
    }
    else {
      ans[i] = to_try[high];
    }

    last[ans[i]] = i;
  }

  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << endl;
}