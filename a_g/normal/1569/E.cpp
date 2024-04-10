#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int powA[20];
int winners[20];
int ranks[40];
int games_won[20];

int k, A, h, games_per_half;

void deconstruct(int mask) {
  for (int j = games_per_half-1; j >= games_per_half/2; j--) {
    winners[j] = (mask&(1<<j) ? 2*j - games_per_half + 2 : 2*j - games_per_half + 3);
  }
  for (int j = games_per_half/2-1; j >= 0; j--) {
    winners[j] = (mask&(1<<j) ? winners[2*j+1] : winners[2*j+2]);
  }
  for (int j = 0; j < games_per_half; j++) {
    games_won[winners[j]]++;
  }
  for (int j = 1; j <= (1<<(k-1)); j++) {
    ranks[j] = (1<<(k-1-games_won[j]))+1;
    games_won[j] = 0;
  }
}

int main () {
  cin >> k >> A >> h;
  games_per_half = (1<<(k-1))-1;
  powA[0] = 1;
  for (int i = 1; i < 20; i++) {
    powA[i] = 1LL * powA[i-1] * A % MOD;
  }

  unordered_map<int, int> unhash[2][2];
  for (int i = 0; i < 2; i++) {
    for (int mask = 0; mask < (1<<games_per_half); mask++) {
      deconstruct(mask);
      int hashval = 0;
      int winner;
      for (int j = 1; j <= (1<<(k-1)); j++) {
        if (ranks[j] != 2) {
          hashval += 1LL * (i ? j + (1<<(k-1)) : j) * powA[ranks[j]] % MOD;
          hashval %= MOD;
        }
        else {
          winner = (i ? j + (1<<(k-1)) : j);
        }
      }
      unhash[i][0][(hashval + 1LL * winner * powA[1]) % MOD] = mask;
      unhash[i][1][(hashval + 1LL * winner * powA[2]) % MOD] = mask;
    }
  }

  for (int i = 0; i < 2; i++) {
    for (auto const& p: unhash[0][i]) {
      int target = (h+MOD-p.first)%MOD;
      if (unhash[1][1-i].count(target)) {
        int mask1 = p.second;
        int mask2 = unhash[1][1-i][target];
        deconstruct(mask2);
        for (int j = 1; j <= (1<<(k-1)); j++) {
          ranks[j+(1<<(k-1))] = (i && ranks[j] == 2 ? 1 : ranks[j]);
        }
        deconstruct(mask1);
        if (!i) {
          for (int j = 1; j <= (1<<(k-1)); j++) {
            if (ranks[j] == 2) ranks[j] = 1;
          }
        }
        for (int j = 1; j <= (1<<k); j++) {
          cout << ranks[j] << ' ';
        }
        cout << '\n';
        return 0;
      }
    }
  }
  cout << "-1\n";
}