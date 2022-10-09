#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 5000;
int potentia[1 + nmax], club[1 + nmax];
int update[1 + nmax], active[1 + nmax], seen[1 + nmax];
int currMex = 0, matchingsz = 0;
vector<int> g[1 + nmax];

int sol[1 + nmax];
int per[2][1 + nmax];

int pairup(int node){
  if(seen[node] == 1)
    return 0;
  seen[node] = 1;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(per[1][to] == node)
      continue;

    if(to - 1 <= currMex) {
      if(per[1][to] == 0){
        per[1][to] = node;
        per[0][node] = to;
        return  1;
      } else {
        if(pairup(per[1][to]) == 1){
          per[1][to] = node;
          per[0][node] = to;
          return 1;
        }
      }
    }
  }
  return 0;
}

int matching(int clubs){
  for(int i = 1;i <= clubs; i++)
    seen[i] = 0;
  for(int i = 1;i <= clubs; i++){
    if(per[0][i] == 0)
      matchingsz += pairup(i);
  }
  return matchingsz;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for(int i = 1;i <= n; i++) {
    cin >> potentia[i];
    potentia[i]++;
  }

  for(int i = 1;i <= n; i++)
    cin >> club[i];
  for(int i = 1;i <= n; i++)
    active[i] = 1;

  int q;
  cin >> q;
  for(int i = 1;i <= q; i++) {
    cin >> update[i];
    active[update[i]] = 0;
  }

  for(int i = 1;i <= n; i++)
    if(active[i] == 1)
      g[club[i]].push_back(potentia[i]);

  for(int i = q; 1 <= i; i--){
    while(matching(m) == (1 + currMex))
      currMex++;
    sol[i] = currMex;
    if(0 <= i)
      g[club[update[i]]].push_back(potentia[update[i]]);
  }

  for(int i = 1; i <= q;i++)
    cout << sol[i] << '\n';
  return 0;
}