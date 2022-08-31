#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    std::string s;
    std::cin >> s;

    int n = s.length();

    if(n <= 2) {
      std::sort(s.begin(), s.end());
      std::cout << s << std::endl;
      continue;
    }

    std::vector<int> count(26, 0);

    for(int i = 0; i < n; i++)
      count[s[i]-'a']++;

    int diff = 0;
    int done = 0;
    int first = -1;
    int second = -1;
    for(int i = 0; i < 26; i++) {
      if(count[i])
        diff++;

      if(count[i] == 0)
        continue;

      if(first == -1)
        first = i;
      else if(second == -1)
        second = i;

      if(count[i] == n) {
        std::cout << s << std::endl;
        done = true;
        break;
      }

      if(count[i] == 1) {
        int c = 0;
        s[c++] = 'a'+i;
        count[i] = 0;
        for(int j = 0; j < 26; j++) {
          while(count[j]) {
            s[c++] = 'a' + j;
            count[j]--;
          }
        }
        done = true;
        std::cout << s << std::endl;
        break;
      }
    }

    if(done)
      continue;

    if(diff == 2) {
      int k = count[first]-2;
      int pos = (n-2)/2;

      if(k > pos) {
        s[0] = 'a' + first;
        for(int c = 1; c < n; c++) {
          if(count[second]) {
            s[c] = 'a' + second;
            count[second]--;
          }
          else
            s[c] = 'a' + first;
        }
        std::cout << s << std::endl;
      }
      else {
        s[0] = s[1] = 'a' + first;
        count[first] -= 2;
        for(int c = 2; c < n; c++) {
          if(c%2 == 1 && count[first]) {
            s[c] = 'a' + first;
            count[first]--;
          }
          else
            s[c] = 'a' + second;
        }

        std::cout << s << std::endl;
      }
    }
    else {
      int k = count[first]-2;
      int pos = (n-2)/2;

      if(k > pos) {
        count[first]--;
        s[0] = 'a' + first;
        s[1] = 'a' + second;
        count[second]--;

        int c = 2;
        while(count[first]) {
          s[c++] = 'a' + first;
          count[first]--;
        }

        for(int i = 0; i < 26; i++) {
          if(i == second)
            continue;
          if(count[i]) {
            s[c++] = 'a' + i;
            count[i]--;
            break;
          }
        }

        for(int i = 0; i < 26; i++) {
          while(count[i]) {
            count[i]--;
            s[c++] = 'a' + i;
          }
        }

        std::cout << s << std::endl;
      }
      else {
        s = std::string(n, '#');
        s[0] = s[1] = 'a' + first;
        count[first] -= 2;

        for(int i = 3; i < n; i += 2) {
          if(count[first] == 0)
            break;
          s[i] = 'a' + first;
          count[first]--;
        }

        int c = 2;
        for(int j = 0; j < 26; j++) {
          while(count[j]) {
            if(s[c] == 'a' + first)
              c++;
            s[c++] = 'a' + j;
            count[j]--;
          }
        }

        std::cout << s << std::endl;
      }
    }
  }

  return 0;
}