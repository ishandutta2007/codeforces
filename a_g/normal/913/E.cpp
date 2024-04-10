#include <bits/stdc++.h>
using namespace std;

const int N = 256;
string ans[N], ans2[N];


void chkmin(string& a, string b, bool& c) {
  // if b is better, replace a and mark that an improvement was made
  if (a == "" || a.size() > b.size() || (a.size() == b.size() && a.compare(b) > 0)) {
    a = b;
    c = 1;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  bool outer_improve;
  do {
    outer_improve = 0;
    for (int i = 0; i < N; i++) {
      if (!ans[i].empty()) ans2[i] = "(" + ans[i] + ")";
      else ans2[i] = "";
    }
    ans2[0b00001111] = "x";
    ans2[0b00110011] = "y";
    ans2[0b01010101] = "z";

    bool inner_improve;
    for (int mask = 0; mask < N; mask++) {
      if (!ans2[N-1-mask].empty()) chkmin(ans2[mask], "!" + ans2[N-1-mask], inner_improve);
    }

    do {
      inner_improve = 0;
      for (int mask = 0; mask < N; mask++) {
        for (int i = 0; i < N; i++) {
          if ((i&mask) != mask || ans2[i] == "") continue;
          for (int j = 0; j < N; j++) {
            if ((i&j) != mask || ans2[j] == "") continue;
            chkmin(ans2[mask], ans2[i]+"&"+ans2[j], inner_improve);
          }
        }
      }
    } while (inner_improve);

    do {
      inner_improve = 0;
      for (int mask = 0; mask < N; mask++) {
        for (int i = 0; i < N; i++) {
          if ((i&mask) != i || ans2[i] == "") continue;
          for (int j = 0; j < N; j++) {
            if ((i|j) != mask || ans2[j] == "") continue;
            chkmin(ans2[mask], ans2[i]+"|"+ans2[j], inner_improve);
          }
        }
      }
    } while (inner_improve);
    
    for (int mask = 0; mask < N; mask++) {
      chkmin(ans[mask], ans2[mask], outer_improve);
    }
  } while (outer_improve);

  /*
  for (int mask = 0; mask < N; mask++) {
    cout << bitset<8>(mask) << " " << ans[mask] << '\n';
  }
  */

  int n;
  cin >> n;
  while (n--) {
    bitset<8> s;
    //string s;
    cin >> s;
    int mask = static_cast<int>(s.to_ulong());
    //cout << mask << '\n';
    cout << ans[mask] << '\n';
  }
}