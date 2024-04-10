#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 100005;

int mod_add (int p, int q, int m) {
  return (p + q) % m;
}

int mod_sub (int p, int q, int m) {
  return (p + m - q) % m;
}

int mod_mul (int p, int q, int m) {
  return ((ll) p * (ll) q) % m;
}

int mod_pow (int p, int k, int m) {
  if (k == 0) {
    return 1;
  } else if (k % 2 == 0) {
    int half = mod_pow(p, k / 2, m);
    return mod_mul(half, half, m);
  } else {
    return mod_mul(p, mod_pow(p, k - 1, m), m);
  }
}

vector<int> adj [maxn];

int main () {
  mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());
  
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  vector<int> primes1 = {1000000223, 1000001857, 1000001887, 1000002827, 1000003919};
  vector<int> primes2 = {1000004123, 1000004207, 1000004233, 1000004249, 1000001203};
  vector<int> primes3 = {1000004329, 1000004381, 1000004389, 1000004437, 1000004449};
  vector<int> bases1 = {101891,	101917,	101921,	101929,	101939,	101957};
  vector<int> bases2 = {1000000007,	1000000009,	1000000021,	1000000033,	1000000087};
    
  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    adj[u].push_back((v - u + vertexc) % vertexc);
    adj[v].push_back((u - v + vertexc) % vertexc);
  }

  for (int i = 0; i < vertexc; i++) {
    sort(adj[i].begin(), adj[i].end());
  }

  int P = primes1[rng() % 5];
  int B = bases1[rng() % 6];
  vector<int> hsh_str (vertexc);
  for (int i = 0; i < vertexc; i++) {
    hsh_str[i] = 0;
    for (int u : adj[i]) {
      hsh_str[i] = mod_mul(hsh_str[i], B, P);
      hsh_str[i] = mod_add(hsh_str[i], u, P);
    }
  }

  for (int i = 0; i < vertexc; i++) {
    hsh_str.push_back(hsh_str[i]);
  }

  int Q1 = primes2[rng() % 5];
  int Q2 = primes2[rng() % 5];
  int C = bases2[rng() % 5];
  int target1 = 0;
  int target2 = 0;
  for (int i = 0; i < vertexc; i++) {
    target1 = mod_mul(target1, C, Q1);
    target2 = mod_mul(target2, C, Q2);
    target1 = mod_add(target1, hsh_str[i], Q1);
    target2 = mod_add(target2, hsh_str[i], Q2);
  }

  int cur1 = target1;
  int cur2 = target2;
  int rem1 = mod_pow(C, vertexc, Q1);
  int rem2 = mod_pow(C, vertexc, Q2);
  for (int i = vertexc; i < 2 * vertexc - 1; i++) {
    target1 = mod_mul(target1, C, Q1);
    target2 = mod_mul(target2, C, Q2);
    target1 = mod_add(target1, hsh_str[i], Q1);
    target2 = mod_add(target2, hsh_str[i], Q2);
    target1 = mod_sub(target1, mod_mul(hsh_str[i - vertexc], rem1, Q1), Q1);
    target2 = mod_sub(target2, mod_mul(hsh_str[i - vertexc], rem2, Q2), Q2);
    if (cur1 == target1 && cur2 == target2) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  return 0;
}