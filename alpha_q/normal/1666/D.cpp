#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   string s, t;
   cin >> s >> t;
   reverse(s.begin(), s.end());
   int cnt[26] = {};
   for(char c : t) cnt[c - 'A']++;
   string res;
   for(char c : s) {
      int x = c - 'A';
      if(cnt[x]) {
         cnt[x]--;
         res += c;
      }
   }
   for(int i=0; i<26; i++) {
      if(cnt[i]) {
         cout << "NO" << '\n';
         return;
      }
   }
   reverse(res.begin(), res.end());
   cout << (res == t ? "YES" : "NO") << '\n';
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t;
   cin >> t;
   while(t--) solve();
}