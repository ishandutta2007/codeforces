#include <iostream>
#include <map>
#include <vector>

#define int long long

std::vector<std::string> exac, pref, suff;
std::vector<int> ans, len;
std::map<std::string, int> iden;

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;

  while(t--) {
    ans.clear();
    iden.clear();
    exac.clear();
    pref.clear();
    suff.clear();

    int n;
    std::cin >> n;

    ans = len = std::vector<int>(n+1, 0);
    pref = std::vector<std::string>(n+1);
    suff = pref;

    for(int i = 1; i <= n; i++) {
      std::string id, type, l, r;
      std::cin >> id;

      std::cin >> type;
      if(type == "=") {
        std::cin >> l >> r >> r;
        int li = iden[l], ri = iden[r];
        len[i] = len[li] + len[ri];

        pref[i] = pref[li];
        if((int)pref[i].length() < 4)
          pref[i] += pref[ri];
        pref[i] = pref[i].substr(0, std::min((int)pref[i].length(), (int)4));

        suff[i] = suff[ri];
        if(suff[i].length() < 4)
          suff[i] = suff[li] + suff[i];
        int y = suff[i].length();
        int sz = std::min((int)y, (int)4);
        suff[i] = suff[i].substr(y-sz, sz);

        std::string mix = suff[li] + pref[ri];
        ans[i] = ans[li] + ans[ri];
        for(int j = 0; j+4 <= mix.length() && j < suff[li].length(); j++) {
          if(j+4 > suff[li].size()) {
            ans[i] += mix.substr(j, 4) == "haha";
          }
        }
        //std::cout << i << " " << pref[i] << " " << suff[i] << " " << ans[i] << " " << ans[li] << " " << ans[ri] << std::endl;
      }
      else {
        std::string cur;
        std::cin >> cur;
        pref[i] = cur;
        pref[i] = pref[i].substr(0, std::min((int)pref[i].length(), (int)4));

        suff[i] = cur;
        int y = suff[i].length();
        int sz = std::min((int)y, (int)4);
        suff[i] = suff[i].substr(y-sz, sz);

        ans[i] = 0;
        for(int j = 0; j+4 <= cur.length(); j++)
          ans[i] += cur.substr(j, 4) == "haha";
      }
      iden[id] = i;
    }

    std::cout << ans.back() << std::endl;
  }

  return 0;
}