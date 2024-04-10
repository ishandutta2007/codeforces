#include <iostream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 1000000;
int f[1 + nmax];
int seen[1 + nmax];
vector<int> v;

int cycle(int node){
  if(seen[node] == 1)
    return 0;
  seen[node] = 1;
  return 1 + cycle(f[node]);
}

int solvemax(int n, int k){
  int spec = 0;
  for(int i = 0; i < v.size(); i++) {
    spec += v[i] % 2;
  }
  int doublep = (n - spec) / 2;
  if(k <= doublep)
    return k * 2;
  else
    return doublep * 2 + MIN(spec, (k - doublep));
}

bitset<1 + nmax> dp;

map<int, int> frec;

void update(int val, int scount){
 // cout << ":" << val << " " << scount << '\n';

  for(int h = 20; 0 <= h; h--){
    if((1 << h) * 2 <= scount){
      dp |= (dp << (val * (1 << h)));
      scount -= (1 << h);
    }
  }
  dp |= (dp << (val * scount));
}

int solvemin(int n, int k){
  for(int i = 0; i < v.size(); i++)
    frec[v[i]]++;
  dp[0] = 1;

  for(int i = 0; i < v.size(); i++){
    if(0 < frec[v[i]]){
      update(v[i], frec[v[i]]);
      frec[v[i]] = 0;
    }
  }
  return k + (1 - dp[k]);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n , k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> f[i];
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      v.push_back(cycle(i));

  cout << solvemin(n, k) << " " << solvemax(n, k);

  return 0;
}