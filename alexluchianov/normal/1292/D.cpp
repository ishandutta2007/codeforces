#include <iostream>
#include <bitset>
#include <vector>
#include <map>

using namespace std;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 5000;
int const graphlim = 451112;

vector<int> primes;

bool isprime(int n){
  if(n <= 1)
    return 0;
  else
    for(int i = 2; i * i <= n; i++)
      if(n % i == 0)
        return 0;
  return 1;
}

int legendre(int n, int val){
  int result = 0;
  for(int i = val; i <= n; i *= val){
    result += n / i;
  }
  return result;
}

vector<map<int, pair<int,int>>> g;
int v[1 + nmax], frec[1 + nmax];
ll weight[1 + graphlim];
int ptr = 0;

void addnode(int k, int scount){
  int curr = 0;
  for(int i = primes.size() - 1; 0 <= i; i--){
    int p = primes[i];
    int coef = legendre(k, p);
    while(0 < coef){
      if(g[curr].find(p) == g[curr].end()) {
        ++ptr;
        g[curr][p] = {ptr, coef};
        g.resize(1 + ptr);
      }
      coef -= g[curr][p].second;
      curr = g[curr][p].first;
    }
  }
  weight[curr] += scount;
}

//*
ll sumdist[5 + graphlim];

void dfs(int node){
  map<int,pair<int,int>>::iterator it = g[node].begin();
  while(it != g[node].end()){
    dfs(it->second.first);
    weight[node] += weight[it->second.first];
    sumdist[node] += sumdist[it->second.first] + it->second.second * weight[it->second.first];
    it++;
  }
}

ll solve(int node, ll sum, ll acc){
  map<int,pair<int,int>>::iterator it = g[node].begin();
  ll result = sum + sumdist[node];

  while(it != g[node].end()){
    int to = it->second.first;
    ll acc2 = acc + (weight[node] - weight[to]);
    ll sum2 = sum + acc2 * it->second.second + (sumdist[node] - sumdist[to] - it->second.second * weight[it->second.first]);
    ll result2 = solve(it->second.first, sum2, acc2);
    result = MIN(result, result2);
    it++;
  }
  return result;
}
//*/


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 2;i <= nmax; i++)
    if(isprime(i) == 1)
      primes.push_back(i);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int val;
    cin >> val;
    frec[val]++;
  }
  g.resize(1);
  frec[1] += frec[0];
  for(int i = 1;i <= nmax; i++)
    if(0 < frec[i])
      addnode(i, frec[i]);
  dfs(0);
  ll result = solve(0, 0, 0);
  cout << result;
  return 0;
}