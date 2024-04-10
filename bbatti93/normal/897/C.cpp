#include <bits/stdc++.h>
#define FOR(i,n) for(int i = 0; i < n; ++i)

using namespace std;
typedef unsigned long long ull;

const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string f1s = "What are you doing while sending \"";
const string f1m = "\"? Are you busy? Will you send \"";
const string f1e = "\"?";
const ull f0l = 75;
const ull f1sl = 34;
const ull f1ml = 32;
const ull f1el = 2;
const ull N=54;
vector<ull> s(N+1);

char solve(const ull n, const ull k) {
  if (n >= N) {
        if(k>(n-N+1)*f1sl) {
           return solve(N-1, k-(n-N+1)*f1sl);
        } else {
            return f1s[k%f1sl];
        }
  }
  if (n < N && k >= s[n]) return '.';
  if (n == 0) return f0[k];
  if (k < f1sl) return f1s[k];
  if (k < f1sl + s[n-1]) return solve(n-1,k-f1sl);
  if (k < f1sl + s[n-1] + f1ml) return f1m[k - f1sl - s[n-1]];
  if (k < f1sl + s[n-1] + f1ml + s[n-1]) return solve(n-1,k-(f1sl + s[n-1] + f1ml));
  return f1e[k-(f1sl + 2*s[n-1] + f1ml)];
}

int main() {
  ull q, n, k;
  s[0] = f0l;
  FOR(i,N) s[i + 1] = s[i]*2 + f1sl + f1ml + f1el;
  cin >> q;
  FOR(q1,q) {
    cin >> n >> k;
    --k;
    cout << solve(n,k);
  }
  cout << endl;
  return 0;
}