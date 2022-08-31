#include <iostream>
#include <set>
#include <vector>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

int count_vowels (const string &s) {
  int ans = 0;
  for (char c : s) {
    if (vowels.count(c)) {
      ans++;
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> pattern (n);
  for (int i = 0; i < n; i++) {
    cin >> pattern[i];
  }

  string trash;
  getline(cin, trash);
  
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);

    if (pattern[i] != count_vowels(line)) {
      failure();
    }
  }

  cout << "YES" << endl;
}