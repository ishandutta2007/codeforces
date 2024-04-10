#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_P = 1e6 + 5;

bool sieve [MAX_P];
vector<int> primes;

ll arr [MAX_P];

int length;
ll solve_for (ll K) {
  ll ans = 0;
  int st = 0;
  vector<int> buf;
  for (int i = 0; i < length; i++) {
    if (arr[i]) {
      buf.push_back(i);
    }

    if ((int) buf.size() == K) {
      ll cur_ans = 0;
      for (int u : buf) {
        cur_ans += u - st;
      }
      int delta = -(int) buf.size();
      if (arr[st]) {
        delta += 2;
      }

      ll cur_min = cur_ans;
      for (int j = st + 1; j <= i; j++) {
        cur_ans += delta;
        if (arr[j]) {
          delta += 2;
        }
        cur_min = min(cur_min, cur_ans);
      }
      ans += cur_min;
      
      buf.clear();
      st = i + 1;
    }
  }
  return ans;
}

int main () {
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