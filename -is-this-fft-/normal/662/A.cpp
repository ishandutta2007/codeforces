#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 5e5 + 5;
const int BITS = 60;

ll a [MAX_N];
ll b [MAX_N];
int used [MAX_N];
ll basis [BITS];

int main () {
  ios::sync_with_stdio(false);

  int length;
  cin >> length;

  ll target = 0;
  for (int i = 0; i < length; i++) {
    cin >> a[i] >> b[i];
    target ^= a[i];
    b[i] ^= a[i];
  }
  
  for (int i = 0; i < BITS; i++) {
    int pivot = -1;
    for (int j = 0; j < length; j++) {
      if (!used[j] && (b[j] & 1LL << i)) {
        pivot = j;
        break;
      }
    }

    if (pivot == -1) {
      basis[i] = -1;
    } else {
      used[pivot] = 1;
      basis[i] = b[pivot];
      for (int j = 0; j < length; j++) {
        if (!used[j] && (b[j] & 1LL << i)) {
          b[j] ^= basis[i];
        }
      }
    }
  }

  int rank = 0;
  for (int i = BITS - 1; i >= 0; i--) {
    if (basis[i] != -1) {
      rank++;
      for (int j = i - 1; j >= 0; j--) {
        if (basis[j] != -1 && (basis[j] & 1LL << i)) {
          basis[j] ^= basis[i];
        }
      }
    }
  }

  ll try_target = 0;
  for (int i = 0; i < BITS; i++) {
    if (target & 1LL << i) {
      if (basis[i] != -1) {
        try_target ^= basis[i];
      }
    }
  }

  if (try_target != target) {
    cout << "1/1" << endl;
  } else {
    cout << (1LL << rank) - 1 << "/" << (1LL << rank) << endl;
  }
}