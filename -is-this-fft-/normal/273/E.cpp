#include <iostream>
#include <vector>

using namespace std;

const int BLOCKC = 102;
const int MOD = 1e9 + 7;
pair<int, int> pre_blocks [BLOCKC] = {
  make_pair(0, 2), make_pair(1, 1), make_pair(2, 1), make_pair(1, 2), make_pair(2, 2), make_pair(0, 4), make_pair(1, 2), make_pair(2, 4), make_pair(0, 8), make_pair(1, 12), make_pair(2, 1), make_pair(0, 17), make_pair(2, 1), make_pair(1, 23), make_pair(2, 4), make_pair(0, 35), make_pair(2, 1), make_pair(1, 53), make_pair(2, 5), make_pair(0, 76), make_pair(2, 5), make_pair(1, 103), make_pair(2, 19), make_pair(0, 155), make_pair(2, 7), make_pair(1, 236), make_pair(2, 25), make_pair(0, 341), make_pair(2, 23), make_pair(1, 463), make_pair(2, 86), make_pair(0, 697), make_pair(2, 32), make_pair(1, 1060), make_pair(2, 115), make_pair(0, 1532), make_pair(2, 106), make_pair(1, 2081), make_pair(2, 389), make_pair(0, 3136), make_pair(2, 145), make_pair(1, 4769), make_pair(2, 518), make_pair(0, 6892), make_pair(2, 479), make_pair(1, 9364), make_pair(2, 1751), make_pair(0, 14110), make_pair(2, 655), make_pair(1, 21458), make_pair(2, 2333), make_pair(0, 31012), make_pair(2, 2158), make_pair(1, 42137), make_pair(2, 7880), make_pair(0, 63493), make_pair(2, 2950), make_pair(1, 96560), make_pair(2, 10499), make_pair(0, 139552), make_pair(2, 9713), make_pair(1, 189616), make_pair(2, 35461), make_pair(0, 285716), make_pair(2, 13277), make_pair(1, 434518), make_pair(2, 47248), make_pair(0, 627983), make_pair(2, 43709), make_pair(1, 853270), make_pair(2, 159577), make_pair(0, 1285721), make_pair(2, 59747), make_pair(1, 1955329), make_pair(2, 212618), make_pair(0, 2825923), make_pair(2, 196691), make_pair(1, 3839713), make_pair(2, 718099), make_pair(0, 5785742), make_pair(2, 268864), make_pair(1, 8798978), make_pair(2, 956783), make_pair(0, 12716653), make_pair(2, 885110), make_pair(1, 17278708), make_pair(2, 3231446), make_pair(0, 26035837), make_pair(2, 1209890), make_pair(1, 39595399), make_pair(2, 4305526), make_pair(0, 57224936), make_pair(2, 3982997), make_pair(1, 77754184), make_pair(2, 14541509), make_pair(0, 117161266), make_pair(2, 5444506), make_pair(1, 178179293), make_pair(2, 19374869), make_pair(0, 257512210), make_pair(2, 17923489), make_pair(1, 115568296)};

typedef long long ll;

ll sumn (ll n) {
  return n * (n + 1) / 2;
}

ll sumlr (ll l, ll r) {
  return sumn(r) - sumn(l - 1);
}

vector<pair<int, int>> blocks;
const int MAX_N = 1e3 + 5;
ll ways [6];
ll dp [MAX_N][4];

int main () {
  int length, cap;
  cin >> length >> cap;
  cap--;
  
  int curl = 0;
  for (int i = 0; i < BLOCKC; i++) {
    pair<int, int> cur = pre_blocks[i];

    int l = curl;
    int r = curl + cur.second - 1;
    if (r > cap) {
      r = cap;
    }

    ways[cur.first] += ((ll) (r - l + 1) * (ll) cap) % MOD;
    ways[cur.first] %= MOD;
    
    ways[cur.first] += MOD - sumlr(l, r) % MOD;
    ways[cur.first] %= MOD;
    
    curl = r + 1;
    if (curl >= cap) break;
  }
  
  dp[0][0] = 1;
  for (int i = 1; i <= length; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        dp[i][j] += (dp[i - 1][k ^ j] * ways[k]) % MOD;
        dp[i][j] %= MOD;
      }
    }
  }

  ll ans = dp[length][1] + dp[length][2] + dp[length][3];
  ans %= MOD;
  cout << ans << endl;
}