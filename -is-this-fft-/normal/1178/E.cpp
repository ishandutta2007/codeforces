#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int cnt [200];

int main () {
  string str;
  cin >> str;

  int length = (int) str.size();
  while (length % 4 != 1 && length % 4 != 0) {
    length--;
  }
  
  deque<char> ans;
  int mid = length / 2;
  if (length % 4 == 1) {
    ans.push_back(str[mid]);
  }

  string pre, post;
  if (length % 4 == 0) {
    pre = str.substr(0, length / 2);
    post = str.substr(mid, length / 2);
  } else {
    pre = str.substr(0, length / 2);
    post = str.substr(mid + 1, length / 2);
  }

  
  for (int i = 0; i < length / 2; i += 2) {
    cnt['a'] = 0;
    cnt['b'] = 0;
    cnt['c'] = 0;
    cnt[pre[length / 2 - 1 - i]]++;
    cnt[pre[length / 2 - 2 - i]]++;
    cnt[post[i]]++;
    cnt[post[i + 1]]++;
    if (cnt['a'] >= 2) {
      ans.push_back('a');
      ans.push_front('a');
    } else if (cnt['b'] >= 2) {
      ans.push_back('b');
      ans.push_front('b');
    } else if (cnt['c'] >= 2) {
      ans.push_back('c');
      ans.push_front('c');
    }
  }

  for (char u : ans) {
    cout << u;
  }
  cout << endl;
}