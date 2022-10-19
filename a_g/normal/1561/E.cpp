#include <math.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solve(int a[], int n);
void operate(int a[], int n);

int main () {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int a[n];
    bool valid = true;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
      if ((j+a[j]) % 2 == 0) {
        valid = false;
      }
    }
    if (valid) {
      vector<int> ans = solve(a, n);
      cout << ans.size() << endl;
      for (auto val: ans) {
        cout << val << " ";
      }
      cout << endl;
    }
    else {
      cout << "-1" << endl;
    }
  }
}

vector<int> solve(int a[], int n) {
  /*for (int i = 0; i < n; i++) {
    cout << a[i];
  }
  cout << endl;*/
  vector<int> ans;
  if (n == 1) return ans;
  int index1, index2;
  for (int i = 0; i < n; i++) {
    if (a[i] == n) {
      index1 = i;
    }
    if (a[i] == n-1) {
      index2 = i;
    }
  }
  ans.push_back(index1+1);
  operate(a, index1+1);
  if (index2 < index1) {
    index2 = index1-index2;
  }
  ans.push_back(index2);
  operate(a, index2);
  ans.push_back(index2+2);
  operate(a, index2+2);
  ans.push_back(3);
  operate(a, 3);
  ans.push_back(n);
  operate(a, n);

  vector<int> remainder = solve(a, n-2);
  ans.insert(ans.end(), remainder.begin(), remainder.end());
  return ans;
}

void operate(int a[], int p) {
  for (int i = 0; i < p/2; i++) {
    int temp = a[i];
    a[i] = a[p-1-i];
    a[p-1-i] = temp;
  }
}