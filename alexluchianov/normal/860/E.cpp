#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <stack>
#include <cstdio>
using namespace std;

int const nmax = 500000;
int const lgmax = 20;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

vector<int> g[1 + nmax];
int level[1 + nmax], far[1 + lgmax][1 + 2 * nmax], ptr = 0;
int pos[1 + nmax], lg[1 + 2 * nmax];

vector<int> cand[1 + nmax];

void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  far[0][++ptr] = node;
  pos[node] = ptr;

  cand[level[node]].push_back(node);
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
    far[0][++ptr] = node;
  }
}

int join(int gala, int galb){
  if(level[gala] < level[galb])
    return gala;
  else
    return galb;
}

void computefar(){
  for(int i = 2;i <= ptr; i++)
    lg[i] = lg[i / 2] + 1;
  for(int h = 1; h < lgmax; h++)
    for(int i = 1;i <= ptr; i++)
      if(i + (1 << h) <= ptr)
        far[h][i] = join(far[h - 1][i], far[h - 1][i + (1 << (h - 1))]);
}

int getlca(int x, int y){
  x = pos[x];
  y = pos[y];
  if(y < x)
    swap(x, y);
  int h = lg[y - x];
  return join(far[h][x], far[h][y - (1 << h) + 1]);
}

ll sol[1 + nmax];
stack<pair<int,int>> st, st2;

void solvelevel(int id){
  ll result = 0;
  for(int i = 0; i < cand[id].size(); i++){
    int node = cand[id][i];
    st2.push({node, 1});
    while(0 < st.size()){
      int newlca = getlca(st.top().first, node), scount = st.top().second;
      if(newlca == st.top().first)
        break;
      result -= 1LL * level[st.top().first] * scount;
      st.pop();
      if(st2.top().first == newlca)
        st2.top().second += scount;
      else
        st2.push({newlca, scount});
      assert(st2.size() <= 2);
    }
    while(0 < st2.size()){
      result += 1LL * level[st2.top().first] * st2.top().second;
      st.push(st2.top());
      st2.pop();
    }
    sol[node] += result - 1;
  }
  while(0 < st.size())
    st.pop();
}

void collect(int node, int parent){
  if(0 < node)
    sol[node] += sol[parent] - (level[node] - 1);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    collect(to, node);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++){
    int parent = 0;
    cin >> parent;
    g[parent].push_back(i);
  }
  level[0] = -1;
  dfs(0, 0);
  computefar();

  for(int i = 1;i <= n; i++) {
    solvelevel(i);
    reverse(cand[i].begin(), cand[i].end());
    solvelevel(i);
  }

  collect(0, 0);
  for (int i=1; i<=n; i++)
    cout << sol[i] << " ";

  return 0;
}