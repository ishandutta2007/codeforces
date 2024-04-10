#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_P = 1e6 + 5;

bool sieve [MAX_P];
vector<int> primes;

ll arr [MAX_P];
ll carr [MAX_P];

int length;
ll solve_for (ll K) {
  for (int i = 0; i < length; i++) {
    carr[i] = arr[i] % K;
  }
  
  ll ans = 0;
  int st = 0;
  vector<pair<int, ll>> buf;
  ll cur_sum = 0;
  for (int i = 0; i < length; i++) {
    buf.push_back(make_pair(i, carr[i]));
    cur_sum += carr[i];
    if (cur_sum >= K) {
      ll leftover = cur_sum - K;
      carr[i] -= leftover;
      buf.pop_back();
      buf.push_back(make_pair(i, carr[i]));

      ll cur_ans = 0;
      for (pair<int, ll> u : buf) {
        cur_ans += (ll) (u.first - st) * u.second;
      }
      ll delta = -K;
      delta += 2 * carr[st];

      ll cur_min = cur_ans;
      for (int j = st + 1; j <= i; j++) {
        cur_ans += delta;
        delta += 2 * carr[j];
        cur_min = min(cur_min, cur_ans);
      }
      ans += cur_min;

      buf.clear();
      cur_sum = 0;
      carr[i] = leftover;
      st = i;
      i--;
    }
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  
  for (int i = 2; i < MAX_P; i++) {
    if (!sieve[i]) {
      primes.push_back(i);
      for (int j = i; j < MAX_P; j += i) {
        sieve[j] = 1;
      }
    }
  }

  cin >> length;

  ll sum = 0;
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  if (sum == 1) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = sum * length;
  for (int p : primes) {
    if (sum % p == 0) {
      ans = min(ans, solve_for(p));
      while (sum % p == 0) {
        sum /= p;
      }
    }
  }
  if (sum != 1) {
    ans = min(ans, solve_for(sum));
  }

  cout << ans << endl;
}