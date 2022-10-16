#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define F first
#define S second
#define sz(x) ((int)x.size())
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define P pair < int, long long >
#define E cout << '\n'
 
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
 
int a[N], k, currElement, ans = 0;
vector < P > v;
int h[N];
 
void generateDivisors(int idx, long long cur) {            
    if (idx >= sz(v))return;
    for (int i = 0; i <= v[idx].first; ++i) {
      // To prevent it from number of divisors extra calls
      if (idx + 1 < sz(v)) {
        generateDivisors(idx+1, cur);
        cur *= v[idx].S;
      }
      else {
        // let's consider this prime factorization
        // {{1,2}, {2,3}, {2,5}, {1,7}} in this example 7 will never be multiplied
        // in if condition as idx + 1 == sz(v) so we multiply it in else condition if i > 0
        if (i) {
          cur *= v[idx].S;
        }
        int Ai = cur, Aj = currElement / Ai;
        // cout << cur << ' ';
        if (Ai == Aj) {
          if (Ai <= 1e5) {
            // if (h[Ai])
              // cout << "here " << cur << ' ' << cur * cur << ' ' << currElement << '\n';
            ans += h[Ai] * (h[Ai] - 1) / 2;
          }
        }
        else if (Ai < Aj && Aj <= 1e5){
          ans += h[Ai] * h[Aj];
        }
        // Here cur is the divisors formed
        // ans ^= cur;
      }
    } 
}
 
vector < int > primes;
vector < int > spf;
 
void RunLinearSieve() {
  int n = N;
  spf.assign(n + 1, 0);
  spf[1] = 1;
  for(int i = 2; i < n; ++i) {
    if(!spf[i]) {
      spf[i] = i;
      primes.push_back(i);
    }
    for(int x : primes) {
      int calc = i * x;
      if(x > spf[i] || calc > n) {
        break;        
      }
      spf[calc] = x;
    }
  }
}
 
void findPrimefactors(int n) {
  while (n != 1) {
    int ok = 1, pf = spf[n], cnt = 0;
    while (n > 1 && n % pf == 0) {
      ok *= pf;
      n /= pf;
      ++cnt;
    }   
    v.push_back({cnt*k, pf});
  }  
}
 
const int mx = 1e10;
bool isPossible(int x) {
  int cnt = 1, now = x;
  while (cnt < k && now <= mx / x) {
    ++cnt;
    now *= x;
  }
  return cnt == k;
}
 
inline void solve() {
   int n;
   cin >> n >> k;
   rep(i,1,n) {
    cin >> a[i];
    ++h[a[i]];
   }
   ans = h[1] * (h[1] - 1) / 2;
   for (int i = 2; i <= 1e5; ++i) {
    if (!isPossible(i)) {
      break;
    }
    v.clear();
    currElement = powl(i, k);
    findPrimefactors(i);
    generateDivisors(0, 1);
    // E;
   }
   cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);  
  RunLinearSieve();  
  solve();
  return 0;
}