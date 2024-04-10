#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using namespace std;

const int INF = 1e9 + 5;

void failure () {
  cout << 0 << endl;
  exit(0);
}

namespace Lib {
#define ran(i, a, b) for (auto i = (a); i < (b); i++)
  
  struct ModArithm {
    //!pause
    ull q = 0; // (1<<(shift+64))/n
    char shift = -1;
    //!unpause
    ull n;
    ld rec;
    ModArithm(ull _n) : n(_n) { // n in [2, 1<<63)
      rec = 1.0L / n;
      //!pause
      ull rem = 1;
      while (rem < n) {
        ++shift;
        rem <<= 1;
      }
      for (int i = 63; i >= 0; --i) {
        if (rem >= n) {
          q |= 1LL << i;
          rem -= n;
        }
        rem *= 2;
      }
      //!unpause
    }
    // a, b in [0, min(2*n, 1<<63))
    ull multf(ull a, ull b) {
      ull mult = (ld)a * b * rec + 0.5L;
      ll res = a * b - mult * n;
      if (res < 0) res += n;
      return res; // in [0, n-1)
    }
    //!pause
#ifndef ONLINE_JUDGE
    ull multa(ll a, ll b) { // a, b in [0, min(2*n, 1<<63))
      ull res;
      ull tmp;
      __asm__(
              "mulq %[b];\n\t"          // a*b
              "movq %%rax, %[res];\n\t" // ab_l = (a*b) & ((1 <<
              // 64)-1)
              "movq %%rdx, %[tmp];\n\t" // ab_h = (a*b) >> 64
              "mulq %[q];\n\t"          // ab_l * q
              "movq %[tmp], %%rax;\n\t"
              "movq %%rdx, %[tmp];\n\t" // abq_m = (ab_l * q) >>
              // 64
              "mulq %[q];\n\t"          // ab_h * q
              "addq %[tmp], %%rax;\n\t" // abq_m += (ab_h * q) &
              // ((1 << 64)-1)
              "adcq $0, %%rdx;\n\t" // abq_h = ((ab_h * q) >> 64)
              // + carry
              "shrdq %%cl, %%rdx, %%rax;\n\t" // d = (a*b)/n =
              // (abq_m >> shift)
              // | (abq_h << (64
              // -shift))
              "mulq %[n];\n\t"                // d*n
              "subq %%rax, %[res];\n\t"       // ab_l - = dn_l
              : [res] "=&r"(res), [tmp] "=&r"(tmp)
              : [a] "%a"(a), [b] "d"(b), [q] "r"(q),
                [shift] "c"(shift), [n] "rm"(n)
              : "cc");
      return res; // in [0, 2n-1)
    }
    ull multi(ull a, ull b) {
      unsigned __int128 mult = a;
      mult *= b;
      ull prod =
        (((mult >> 64) * q) +
         ((unsigned __int128)(ull)mult * q >> 64)) >>
        shift;
      return (ull)mult - prod * n;
    }
    ull fix(ull a) {
      if (a >= n) a -= n;
      return a;
    }
    ull mult(ull a, ull b) { return fix(multi(a, b)); }
#endif
    //!unpause
    ull sqp1(ull a) { return multf(a, a) + 1; }
  };
  //!finish
  //!start

  ull pow_mod(ull a, ull n, ModArithm &arithm) {
    ull res = 1;
    for (ull i = 1; i <= n; i <<= 1) {
      if (n & i) res = arithm.multf(res, a);
      a = arithm.multf(a, a);
    }
    return res;
  }
  //!finish
  //!start

  vector<char> small_primes = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

  bool is_prime(ull n) { // n <= 1<<63, 1M rand/s
    ModArithm arithm(n);
    if (n == 2 || n == 3) return true;
    if (!(n & 1) || n == 1) return false;
    int s = __builtin_ctzll(n - 1);
    ull d = (n - 1) >> s;
    for (ull a : small_primes) {
      if (a >= n) break;
      a = pow_mod(a, d, arithm);
      if (a == 1 || a == n - 1) continue;
      ran(r, 1, s) {
        a = arithm.multf(a, a);
        if (a == 1) return false;
        if (a == n - 1) break;
      }
      if (a != n - 1) return false;
    }
    return true;
  }
  //!finish
  //!pause

#ifdef ONLINE_JUDGE
  ll __gcd(ll a, ll b) {
    if (a) return __gcd(b % a, a);
    return b;
  }
#endif

  //!unpause
  //!start

  ll pollard_rho(ll n) {
    ModArithm arithm(n);
    int cum_cnt = 64 - __builtin_clzll(n);
    cum_cnt *= cum_cnt / 5 + 1;
    while (true) {
      ll lv = rand() % n;
      ll v = arithm.sqp1(lv);
      int idx = 1;
      int tar = 1;
      while (true) {
        ll cur = 1;
        ll v_cur = v;
        int j_stop = min(cum_cnt, tar - idx);
        for (int j = 0; j < j_stop; ++j) {
          cur = arithm.multf(cur, abs(v_cur - lv));
          v_cur = arithm.sqp1(v_cur);
          ++idx;
        }
        //!pause
        // cur = arithm.fix(cur);
        //!unpause
        if (!cur) {
          for (int j = 0; j < cum_cnt; ++j) {
            ll g = __gcd(abs(v - lv), n);
            if (g == 1) {
              v = arithm.sqp1(v);
            } else if (g == n) {
              break;
            } else {
              return g;
            }
          }
          break;
        } else {
          ll g = __gcd(cur, n);
          if (g != 1) return g;
        }
        v = v_cur;
        idx += j_stop;
        if (idx == tar) {
          lv = v;
          tar *= 2;
          v = arithm.sqp1(v);
          ++idx;
        }
      }
    }
  }
  //!finish
  //!start


  map<ll, int> prime_factor(
                            ll n, map<ll, int> *res = NULL) {
    // n <= 1<<62, ~1000/s (<500/s on CF)
    if (!res) {
      map<ll, int> res_act;
      for (int p : small_primes) {
        while (!(n % p)) {
          ++res_act[p];
          n /= p;
        }
      }
      if (n != 1) prime_factor(n, &res_act);
      return res_act;
    }
    if (is_prime(n)) {
      ++(*res)[n];
    } else {
      ll factor = pollard_rho(n);
      prime_factor(factor, res);
      prime_factor(n / factor, res);
    }
    return map<ll, int>();
  } // Usage: fact = prime_factor(n);
}

struct Num {
  ll val;
  vector<int> divs;
};

const int MAX_N = 1005;

map<ll, int> idx; // prime number -> small number
vector<ll> ppw [MAX_N];
vector<Num> oths;

ll arr [MAX_N];
map<ll, int> factor [MAX_N];

int main () {
  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    factor[i] = Lib::prime_factor(arr[i]);
    if (factor[i].size() == 1) {
      idx[factor[i].begin()->first] = 0;
    }
  }

  int pc = 0;
  for (auto it = idx.begin(); it != idx.end(); it++) {
    it->second = pc;
    pc++;
  }

  for (int i = 0; i < n; i++) {
    if (factor[i].size() == 1) {
      ppw[idx[factor[i].begin()->first]].push_back(arr[i]);
    }
  }

  set<int> ok_ids;
  for (int i = 0; i < pc; i++) {
    if ((int) ppw[i].size() >= 2) {
      ok_ids.insert(i);
    }
  }

  for (int i = 0; i < n; i++) {
    if (factor[i].size() != 1) {
      Num cur;
      cur.val = arr[i];
      cur.divs = vector<int> (0);

      bool ok = true;

      for (auto it = factor[i].begin(); it != factor[i].end(); it++) {
        if (!idx.count(it->first) || !ok_ids.count(idx[it->first])) {
          ok = false;
        } else {
          cur.divs.push_back(idx[it->first]);
        }
      }
      
      if (ok) {
        oths.push_back(cur);
      }
    }
  }

  if (K == 1) {
    failure();
  }

  int ppc = 0, all2 = true;
  for (int id : ok_ids) {
    ppc += ppw[id].size();
    if (ppw[id].size() != 2) {
      all2 = false;
    }
  }

  int totc = ppc + (int) oths.size();
  if (totc < K) {
    failure();
  }

  // easy case: take all primes and then whatever
  if (ppc <= K) {
    for (int id : ok_ids) {
      for (ll pp : ppw[id]) {
        cout << pp << " ";
      }
    }

    for (int i = 0; i < K - ppc; i++) {
      cout << oths[i].val << " ";
    }
    cout << endl;
    return 0;
  }

  // take one other thing with the smallest number of requirements
  // and then prime powers in pairs
  if (all2 && K % 2 == 1) {
    pair<int, int> least_req = make_pair(INF, -1);
    for (int i = 0; i < (int) oths.size(); i++) {
      least_req = min(least_req, make_pair((int) oths[i].divs.size(), i));
    }

    if (least_req.first > K / 2) {
      failure();
    }

    int lid = least_req.second;
    cout << oths[lid].val << " ";
    K--;
    for (int d : oths[lid].divs) {
      for (ll pp : ppw[d]) {
        cout << pp << " ";
      }
      ok_ids.erase(d);
      K -= 2;
    }

    for (int u : ok_ids) {
      if (K == 0) {
        break;
      }

      for (ll pp : ppw[u]) {
        cout << pp << " ";
      }
      K -= 2;
    }
    cout << endl;
    return 0;
  }

  // take two things from each prime power and then some
  if (K >= 2 * (int) ok_ids.size()) {
    vector<ll> rem_ppws;
    for (int id : ok_ids) {
      for (int i = 0; i < (int) ppw[id].size(); i++) {
        if (i < 2) {
          cout << ppw[id][i] << " ";
          K--;
        } else {
          rem_ppws.push_back(ppw[id][i]);
        }
      }
    }

    for (int i = 0; i < K; i++) {
      cout << rem_ppws[i] << " ";
    }
    cout << endl;
    return 0;
  }

  // take 3 things from an >2 first, then take the others in pairs
  int spec = -1;
  if (K % 2 == 1) {
    for (int id : ok_ids) {
      if ((int) ppw[id].size() > 2) {
        spec = id;
        break;
      }
    }

    for (int i = 0; i < 3; i++) {
      cout << ppw[spec][i] << " ";
      K--;
    }
  }

  for (int id : ok_ids) {
    if (id != spec) {
      if (K == 0) {
        break;
      }

      for (int i = 0; i < 2; i++) {
        cout << ppw[id][i] << " ";
        K--;
      }
    }
  }
  cout << endl;
}