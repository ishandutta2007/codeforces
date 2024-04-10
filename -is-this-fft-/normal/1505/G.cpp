#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main () {
  map<vector<int>, char> mp;
  mp[{1, 0, 0, 1}] = 'a';
  mp[{1, 1, 0, 2}] = 'b';
  mp[{2, 0, 0, 1}] = 'c';
  mp[{2, 1, 0, 1}] = 'd';
  mp[{1, 1, 0, 1}] = 'e';
  mp[{2, 1, 0, 2}] = 'f';
  mp[{2, 2, 0, 2}] = 'g';
  mp[{1, 2, 0, 2}] = 'h';
  // mp[{1, 1, 0, 1}] = 'i';
  mp[{1, 2, 0, 1}] = 'j';
  mp[{1, 0, 1, 2}] = 'k';
  mp[{1, 1, 1, 3}] = 'l';
  mp[{2, 0, 1, 2}] = 'm';
  mp[{2, 1, 1, 2}] = 'n';
  mp[{1, 1, 1, 2}] = 'o';
  mp[{2, 1, 1, 3}] = 'p';
  mp[{2, 2, 1, 3}] = 'q';
  mp[{1, 2, 1, 3}] = 'r';
  // mp[{1, 1, 1, 2}] = 's';
  mp[{1, 2, 1, 2}] = 't';
  mp[{1, 0, 2, 2}] = 'u';
  mp[{1, 1, 2, 3}] = 'v';
  mp[{1, 2, 1, 1}] = 'w';
  mp[{2, 0, 2, 2}] = 'x';
  mp[{2, 1, 2, 2}] = 'y';
  mp[{1, 1, 2, 2}] = 'z';

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    cout << mp[{a, b, c, d}];
  }
  cout << endl;
}