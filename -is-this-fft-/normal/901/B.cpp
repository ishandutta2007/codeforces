#include <deque>
#include <iostream>

using namespace std;

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  deque<int> A = {1};
  deque<int> B = {};

  for (int i = 0; i < n; i++) {
    int hasm = 0;
    int hasn = 0;
    for (int j = 1; j - 1 < (int) A.size() && j < (int) B.size(); j++) {
      if (A[j - 1] != 0 && A[j - 1] == B[j]) {
        hasm = 1;
      }

      if (A[j - 1] != 0 && A[j - 1] == -B[j]) {
        hasn = 1;
      }
    }

    if (hasm && hasn) {
      cout << "ERROR" << endl;
    }

    deque<int> nB = A;
    A.push_front(0);
    if (hasm) {
      for (int j = 0; j < A.size(); j++) {
        A[j] *= -1;
      }
    }

    for (int j = 0; j < B.size(); j++) {
      A[j] += B[j];
    }

    B = nB;
  }

  int flag = 1;
  if (A.back() < 1) {
    flag = -1;
  }
  
  cout << (int) A.size() - 1 << '\n';
  for (int u : A) {
    cout << flag * u << " ";
  }
  cout << endl;

  flag = B.back();
  
  cout << (int) B.size() - 1 << '\n';
  for (int u : B) {
    cout << flag * u << " ";
  }
  cout << endl;
}