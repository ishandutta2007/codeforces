#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
const ll INF = 1e18+1;

class bounded_long {
  public:
    ll n;
    bounded_long() {n=0;};
    bounded_long(ll n): n(n){};
    bounded_long& operator+=(const bounded_long& other) {
      this->n = min(INF, this->n+other.n);
      return *this;
    }
};

int n, m;
ll k;
string s;
int lcp[N][N];
bounded_long dp[N][N];
// dp[i][j] = number of ways to split first i characters into exactly j
// substrings which are all greater than t

bool cmp(const pair<int,int>& a, const pair<int, int>& b) {
  int l = lcp[a.first][b.first];
  if (l >= a.second || l >= b.second) {
    return a.second < b.second;
  }
  return (s[a.first+l] < s[b.first+l]);
}

ll f(string& t) {
  // return the number of ways to split s into m strings so that every substring
  // is greater than t
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i+1][j] += dp[i][j];
    }
    // s[i:j] > t
    for (int j = i; j < n; j++) {
      if (j-i >= (int)t.size() || s[j] > t[j-i]) {
        for (int k = 0; k < m; k++) {
          dp[j+1][k+1] += dp[i][k];
        }
        break;
      }
      if (s[j] < t[j-i]) {
        break;
      }
    }
  }

  return dp[n][m].n;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k >> s;
  for (int i = n-1; i >= 0; i--) {
    for (int j = n-1; j >= 0; j--) {
      if (s[i] == s[j]) {
        lcp[i][j] = lcp[i+1][j+1] + 1;
      }
    }
  }

  vector<pair<int, int>> substr_pairs;
  for (int i = 0; i < n; i++) {
    for (int j = 1; i+j <= n; j++) {
      substr_pairs.push_back(make_pair(i, j));
    }
  }
  sort(substr_pairs.begin(), substr_pairs.end(), cmp);

  dp[0][0] = 1;
  int z = substr_pairs.size();
  int low = -1;
  int high = z-1;
  while (low+1 < high) {
    int mid = (low+high)/2;
    string t = s.substr(substr_pairs[mid].first, substr_pairs[mid].second);
    if (f(t) >= k) low = mid;
    else high = mid;
  }
  cout << s.substr(substr_pairs[high].first, substr_pairs[high].second) << '\n';
}