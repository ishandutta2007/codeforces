#include <iostream>
#include <set>

#define int long long

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    int n;
    std::string s;
    
    std::cin >> s;
    n = s.length();

    std::set<int> chars[26];
    for(int i = 0; i < n; i++) {
      chars[s[i]-'a'].insert(i);
    }

    int rem = 0;
    std::string t;
    for(int i = 0; i < 26; i++) {
      int minLast = n-1;
      if(rem == n)
        break;
      for(int j = 0; j < 26; j++) {
        if(chars[j].size())
          minLast = std::min(minLast, *chars[j].rbegin());
      }

      for(int j = 25; j >= 0; j--) {
        if(chars[j].empty())
          continue;

        if((*chars[j].begin()) <= minLast) {
          t += 'a' + j;
          int nrem = *chars[j].begin();
          nrem++;
          while(rem < nrem) {
            chars[s[rem]-'a'].erase(rem);
            rem++;
          }
          chars[j].clear();
          break;
        }
      }
    }

    std::cout << t << std::endl;
  }

  return 0;
}