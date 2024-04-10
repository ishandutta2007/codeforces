#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long ;

int const nmax = 1000;
int const period = 8 * 9 * 5 * 7;
int cost[1 + nmax], far[1 + nmax * period];

int getid(int node, int time){
  return (node - 1) * period + time;
}
int cycle[1 + nmax * period], seen[1 + nmax * period];

vector<int> st;
int frec[1 + nmax * period];

int dfs(int node, int time){
  if(0 < seen[node]){
    if(0 < cycle[node])
      return cycle[node];
    else {
      int l = time - seen[node];
      int result = 0;
      for(int i = 1; i <= l; i++) {
        frec[st[st.size() - i]]++;
        if(frec[st[st.size() - i]] == 1)
          result++;
      }
      for(int i = 1; i <= l; i++)
        frec[st[st.size() - i]]--;
      cycle[node] = result;
      return result;
    }
  } else {
    seen[node] = time;
    st.push_back(node / period);
    cycle[node] = dfs(far[node], time + 1);
    st.pop_back();
    return cycle[node];
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> cost[i];
    cost[i] %= period;
    if(cost[i] < 0)
      cost[i] += period;
  }

  for(int i = 1;i <= n; i++){
    int m;
    cin >> m;
    vector<int> g;
    for(int j = 0; j < m; j++){
      int to;
      cin >> to;
      g.push_back(to);
    }
    for(int j = 0; j < period; j++)
      far[getid(i, j)] = getid(g[j % m], (j + cost[g[j % m]]) % period);
  }

  for(int i = 0;i <= getid(n, period - 1); i++)
    if(seen[i] == 0)
      dfs(i, 1);

  int q;
  cin >> q;
  for(int i = 1;i <= q; i++){
    int x, start;
    cin >> x >> start;
    start += cost[x];
    start %= period;

    if(start < 0)
      start += period;
    cout << cycle[getid(x, start)] << '\n';
  }
  return 0;
}