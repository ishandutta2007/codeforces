#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100005;

typedef long long ll;

ll A [maxn], B [maxn];
ll At [maxn], Bt [maxn];

int main () {
  int length;
  cin >> length;

  for (int i = 0; i < length; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < length; i++) {
    cin >> B[i];
  }

  for (int i = 0; i < length - 1; i++) {
    At[i] = A[i + 1] - A[i];
    Bt[i] = B[i + 1] - B[i];
  }
  
  if (A[0] != B[0]) {
    cout << "No" << endl;
    return 0;
  }

  if (A[length - 1] != B[length - 1]) {
    cout << "No" << endl;
    return 0;
  }

  sort(At, At + length - 1);
  sort(Bt, Bt + length - 1);
  for (int i = 0; i < length - 1; i++) {
    if (At[i] != Bt[i]) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}