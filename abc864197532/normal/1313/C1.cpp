#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
#define MAXN 500000
vector <int> input;
vector <lli> aa[2];

void build (int n, int k) {
  aa[k].resize(n + 1);
  aa[k][0] = 0;
  vector <pii> tmp;
  fop (i,0,n) {
    int now = 1;
    while (tmp.size() and tmp.back().X > input[i]) {
      now += tmp.back().Y;
      tmp.pop_back();
    }
    tmp.eb(input[i], now);
    aa[k][i + 1] = aa[k][i - now + 1] + 1ll * now * input[i];
  }
}

int main () {
  int n;
  cin >> n;
  input.resize(n);
  fop (i,0,n) cin >> input[i];
  build(n, 0);
  reverse(input.begin(), input.end());
  build(n, 1);
  reverse(aa[1].begin() + 1, aa[1].end());
  reverse(input.begin(), input.end());
  lli ans1 = 0;
  int id = -1;
  fop (i,0,n) {
    if (ans1 < aa[0][i+1] + aa[1][i+1] - input[i]) {
      ans1 = aa[0][i+1] + aa[1][i+1] - input[i];
      id = i;
    }
  }
  vector <int> ans(n);
  ans[id] = input[id];
  FOP (i,id,0) {
    ans[i] = min(input[i], ans[i+1]);
  }
  fop (i,id+1,n) {
    ans[i] = min(input[i], ans[i-1]);
  }
  for (int i : ans) cout << i << ' ';
  cout << endl;
}