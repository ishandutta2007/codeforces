#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

int factor [MAX_N];
int arr [MAX_N];

int K;
pair<int, int> normalize (int x) {
  vector<int> factors;
  while (x != 1) {
    factors.push_back(factor[x]);
    x /= factor[x];
  }

  sort(factors.begin(), factors.end());

  vector<pair<int, int>> fpows;
  for (int i = 0; i < (int) factors.size(); i++) {
    if (i == 0 || factors[i] != factors[i - 1]) {
      fpows.push_back(make_pair(factors[i], 0));
    }
    fpows.back().second++;
  }

  for (int i = 0; i < (int) fpows.size(); i++) {
    fpows[i].second %= K;
  }

  int normalized = 1;
  for (int i = 0; i < (int) fpows.size(); i++) {
    for (int j = 0; j < (int) fpows[i].second; j++) {
      normalized *= fpows[i].first;
    }
  }

  long long complement = 1;
  for (int i = 0; i < (int) fpows.size(); i++) {
    for (int j = 0; j < (int) (K - fpows[i].second) % K; j++) {
      complement *= fpows[i].first;

      if (complement > MAX_N) {
        return make_pair(normalized, -1);
      }
    }
  }
  return make_pair(normalized, (int) complement);
}

pair<int, int> ps [MAX_N];

int main () {
  int primec = 0;
  for (int i = 2; i < MAX_N; i++) {
    if (factor[i] == 0) {
      primec++;
      for (int j = i; j < MAX_N; j += i) {
        factor[j] = i;
      }
    }
  }

  int length;
  cin >> length >> K;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];

    ps[i] = normalize(arr[i]);
    // cout << ps[i].first << "  " << ps[i].second << endl;
  }

  map<pair<int, int>, int> cnt;
  for (int i = 0; i < length; i++) {
    cnt[ps[i]] = 0;
  }

  for (int i = 0; i < length; i++) {
    cnt[ps[i]]++;
  }

  long long ans = 0;
  for (int i = 0; i < length; i++) {
    ans += cnt[make_pair(ps[i].second, ps[i].first)];
    if (ps[i].first == ps[i].second) {
      ans--;
    }
  }
  ans /= 2;
  cout << ans << endl;
}