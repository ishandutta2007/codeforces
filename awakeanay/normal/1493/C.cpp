#include <iostream>
#include <vector>

std::vector<int> count(26, 0);
int n, k;

bool check() {
  int rem = n;
  int need = 0;
  for(int i = 0; i < 26; i++) {
    need += (k-(count[i]%k))%k;
    rem -= count[i];
  }
  return need <= rem;
}

signed main() {
  int t;
  std::cin >> t;

  while(t--) {
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    if(n%k != 0) {
      std::cout << -1 << std::endl;
      continue;
    }

    count = std::vector<int>(26, 0);
    int start = 0;
    for(int i = 0; i < n; i++)
      count[s[i]-'a']++;

    if(check()) {
      std::cout << s << std::endl;
      continue;
    }

    for(int i = n-1; i >= 0; i--) {
      count[s[i]-'a']--;
      bool poss = false;
      for(int j = (s[i]-'a')+1; j < 26; j++) {
        count[j]++;
        s[i] = 'a' + j;
        if(check()) {
          start = i+1;
          poss = true;
          break;
        }
        count[j]--;
      }
      if(poss)
        break;
    }

    for(int i = start; i < n; i++) {
      for(int j = 0; j < 26; j++) {
        count[j]++;
        s[i] = 'a' + j;
        if(check())
          break;
        count[j]--;
      }
    }
    
    std::cout << s << std::endl;
  }

  return 0;
}