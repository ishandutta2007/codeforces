#include <iostream>
#include <vector>

using namespace std;

const int RECW = 5000;
const int RECH = 4;

int main () {
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;

  vector<pair<int, int>> gray;
  for (int i = 0; i <= RECW; i++) {
    gray.push_back(make_pair(0, i));
    gray.push_back(make_pair(RECH, i));
  }

  for (int i = 1; i < RECH; i++) {
    gray.push_back(make_pair(i, 0));
    gray.push_back(make_pair(i, RECW));
  }

  int c = 2;
  while (n >= 2) {
    // add a thing
    gray.push_back({-1, c});
    gray.push_back({-2, c});
    gray.push_back({-2, c + 1});
    gray.push_back({-2, c + 2});
    gray.push_back({-1, c + 2});
    gray.push_back({1, c});
    gray.push_back({2, c});
    gray.push_back({2, c + 1});
    gray.push_back({2, c + 2});
    gray.push_back({1, c + 2});

    c += 4;
    n -= 2;
  }

  if (n == 1) {
    gray.push_back({-1, RECW});
    gray.push_back({-1, RECW + 1});
    gray.push_back({0, RECW + 1});
  }

  cout << (int) gray.size() << '\n';
  for (auto pr : gray) {
    cout << pr.first << " " << pr.second << '\n';
  }
}