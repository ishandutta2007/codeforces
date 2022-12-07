#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define maxs 100005
#define maxV 200005
#define maxq 200005
#define maxt 400005

using namespace std;
typedef long long ll;

namespace SAM { // for s.
  int len[maxV], link[maxV], nxt[maxV][26], V, lst;
  // V: 1-base.
  void init() {
    memset(nxt, 0, sizeof(nxt));
    V = lst = 1;
    len[1] = link[1] = 0;
  }
  void append(char c) {
    c -= 'a';
    int p = lst, cur = ++V;
    len[cur] = len[p] + 1;
    while (p && !nxt[p][c]) {
      nxt[p][c] = cur;
      p = link[p];
    }
    if (!p) {
      link[cur] = 1;
    } else {
      int q = nxt[p][c];
      if (len[p] + 1 == len[q]) {
        link[cur] = q;
      } else {
        int tmp = ++V;
        for (int i = 0; i < 26; i++) nxt[tmp][i] = nxt[q][i];
        len[tmp] = len[p] + 1;
        link[tmp] = link[q];
        while (p && nxt[p][c] == q) {
          nxt[p][c] = tmp;
          p = link[p];
        }
        link[q] = link[cur] = tmp;
      }
    }
    lst = cur;
  }
  
  void print() {
    for (int i = 1; i <= V; i++) {
      cout << "node " << i << ": ";
      cout << "len: " << len[i] << ", link: " << link[i] << endl;
      for (int j = 0; j < 26; j++) {
        if (nxt[i][j]) {
          cout << char(j + 'a') << " " << nxt[i][j] << endl;
        }
      }
      system("pause"); 
    }
  }
  
}
namespace Tree {
  vector<int> adj[maxV];
  void build() {
    for (int i = 2; i <= SAM::V; i++) {
      adj[SAM::link[i]].push_back(i);
    }
  }
  int dfn[maxV], ed[maxV], ind;
  void dfs(int u) {
    dfn[u] = ++ind;
    for (auto v : adj[u]) dfs(v);
    ed[u] = ind;
  }
}
namespace Sgt {
  int maxi[maxV << 2];
  void update(int id, int l, int r, int pos, int x) {
    if (l == r) {
      maxi[id] = x;
    } else {
      int mid = (l + r) >> 1;
      if (pos <= mid) update(id << 1, l, mid, pos, x);
      else update(id << 1 | 1, mid + 1, r, pos, x);
      maxi[id] = max(maxi[id << 1], maxi[id << 1 | 1]);
    }
  }
  int query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return maxi[id];
    int mid = (l + r) >> 1, res = 0;
    if (ql <= mid) res = max(res, query(id << 1, l, mid, ql, qr));
    if (mid < qr) res = max(res, query(id << 1 | 1, mid + 1, r, ql, qr));
    return res;
  }
}
bool able(int u, int l, int ql, char c) {
  c -= 'a';
  int v = SAM::nxt[u][c];
  if (!v) return false;
  return Sgt::query(1, 1, SAM::V, Tree::dfn[v], Tree::ed[v]) - ql + 1 > l;
}
char s[maxs], t[maxt], *tail = t;
int n, q; // n: s.length().
string ans[maxq];
struct Query {
  int l, r, id;
  char* str;
  bool operator < (const Query &b)const
  {
    return r < b.r;
  }
}qs[maxq];
bool dfs(int id, int u, int i) { // for qs[id], now deciding ans for t[i].
  // tight = true.
  
//  cout << "dfs " << id << " " << u << " " << i << endl;
//  system("pause");
  
  for (char c = max(qs[id].str[i], 'a'); c <= 'z'; c++) {
    
//    cout << i << " " << c << endl;
//    system("pause");
    
    if (able(u, i - 1, qs[id].l, c)) {
      
//      cout << "ok" << endl;
      
      ans[qs[id].id].push_back(c);
      if (c > qs[id].str[i] || dfs(id, SAM::nxt[u][c - 'a'], i + 1))
        return true;
      ans[qs[id].id].pop_back();
    }
  }
  return false;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  SAM::init();
  for (int i = 1; i <= n; i++) SAM::append(s[i]);
  
//  SAM::print();
  
  Tree::build();
  Tree::dfs(1);
  
//  cout << "dfn: ";
//  for (int i = 1; i <= 5; i++) {
//    cout << Tree::dfn[i] << " ";
//  }
//  cout << endl;
//  system("pause");
  
//  cout << "ed: ";
//  for (int i = 1; i <= 5; i++) {
//    cout << Tree::ed[i] << " ";
//  }
//  cout << endl;
//  system("pause");
  
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%s", &qs[i].l, &qs[i].r, tail + 1);
    int tmp = strlen(tail + 1);
    qs[i].str = tail;
    qs[i].id = i;
    tail += tmp + 1;
  }
  sort(qs + 1, qs + q + 1);
  
//  cout << "qs[1]: " << endl;
//  cout << "l: " << qs[1].l << " r: " << qs[1].r << " id: " << qs[1].id << endl;
//  cout << (qs[1].str + 1) << endl;
//  system("pause");
  
  int j = 0, u = 1;
  for (int i = 1; i <= q; i++) {
    while (j < qs[i].r) {
      j++;
      u = SAM::nxt[u][s[j] - 'a'];
      
//      cout << j << " " << u << endl;
//      system("pause");
      
      Sgt::update(1, 1, SAM::V, Tree::dfn[u], j);
    }
    
//    cout << "ok" << endl;
    
    dfs(i, 1, 1);
  }
  
//  cout << "ok" << endl;
   
  for (int i = 1; i <= q; i++) {
    if (ans[i].empty()) puts("-1");
    else printf("%s\n", ans[i].c_str());
  }
  return 0;
}