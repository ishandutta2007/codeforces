#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>


using namespace std;

#define long long long

int readInt() {
  int x;
  std::cin >> x;
  return x;
}


long readLong() {
  long x;
  std::cin >> x;
  return x;
}

std::string readString() {
  std::string s;
  std::cin >> s;
  return s;
}

void printVector(const std::vector<int>& v) {
  for (int i : v) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

long getDiv(long x, long y) {
  long k = x / y;
  if (k * y < x) {
    ++k;
  }
  return k;
}

long Ans(long x, long y, long p, long q) {
  if (p == 0) {
    if (x == 0) {
      return 0;
    } else {
      return -1;
    }
  }

  if (p == q) {
    if (x == y) {
      return 0;
    } else {
      return -1;
    }
  }

  long k = std::max(getDiv(x, p), getDiv(y - x, q - p));
  return k * q - y;
}


int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int tests = readInt();

  for (int i = 0; i < tests; ++i) {
    long x = readLong();
    long y = readLong();
    long p = readLong();
    long q = readLong();

    long ans = Ans(x, y, p, q);
    std::cout << ans << "\n";


  }


  return 0;
}