#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>
#define data abacabadabacaba

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

 const int N = 1e6;
const int inf = ~0u >> 2;
struct Node* null;
struct Node
{
        Node* ch[2];
        Node* fa;
        int mi, val, rev;
        inline bool isroot(){return fa==null||fa->ch[0]!=this&&fa->ch[1]!=this;}
        inline bool d(){return fa->ch[1]==this;}
        inline void setc(int s, Node* who){who->fa=this;ch[s]=who;}
        inline void rotate() {
                bool f=d();
                Node* y=fa; y->setc(f,ch[!f]),fa=y->fa;
                if(!y->isroot()) fa->ch[y->d()]=this;
                this->setc(!f,y),y->up();
        }
        void splay() {
                for(go();!isroot();rotate())
                        if(!fa->isroot())
                                (fa->d()^d())?rotate():fa->rotate();
                up();
        }
        inline void up() {
                mi = std::min(ch[0]->mi, ch[1]->mi);
                mi = std::min(mi, val);
        }
        void init(int v, Node* f) {
                fa = f;
                val = mi = v;
                ch[0] = ch[1] = null;
                rev = 0;
        }
        void flip() {
                std::swap(ch[0], ch[1]);
                rev ^= 1;
        }
        void push() {
                if(rev) {
                        ch[0]->flip(), ch[1]->flip(), rev = 0;
                }
        }
        /*
        void print() {
                if(this != null) {
                        if(ch[0] != null) ch[0]->print();
                        O(val);
                        if(ch[1] != null) ch[1]->print();
                }
        }
        */
        void go() {
                if(!isroot()) fa->go();
                push();
        }
};
struct Edge
{
        int a, b;
//        void in() {  I(a); I(b);    }
}edge[N];

int musorka = -1;

int my_n;

int kekos[N];

struct Link_Cut_Tree
{
        Node node[N]; int tot;
        Node* access(Node* u) {
                Node* v = null;
                for(; u != null; v = u, u = u->fa) u->splay(),u->ch[1] = v,u->up();
                return v;
        }
        int ask(Node* x, Node* y) {
                access(x);
                for(x = null; y != null; y = y->fa) {
                        y->splay();
                        if(y->fa == null)  {
                                return std::min(y->ch[1]->mi, x->mi);
                        }
                        y->ch[1] = x, y->up(), x = y;
                }
        }
        int ask(int a, int b) {
                return ask(node + a, node + b);
        }
        void cut(Node* u) {
                u->splay();
                u->ch[0]->fa = u->fa;
                u->fa = u->ch[0] = null;
                u->up();
        }
        void cut(Node* u, Node* v) {
                access(u), v->splay();
                if(v->fa == u) {
                        v->fa = null;
                } else {
                        access(v), u->splay(), u->fa = null;
                }
        }
        void link(Node* u, Node* v) {
                make_root(u);
                u->fa = v;
        }
        void make_root(Node* u) {
                Node* tmp = access(u);
                tmp->flip();
                u->splay();
        }
        bool judge(Node* u, Node* v) {
                while(u->fa != null) u = u->fa;
                while(v->fa != null) v = v->fa;
                return u == v;
        }
        void insert(int a, int b, int c, int w) {
          edge[c].a = a, edge[c].b = b;
          kekos[c] = w;
                Node* u = node + a;
                Node* v = node + b;
                Node* edge_node = &node[my_n + c + 1];
                edge_node->init(c, null);
                if(judge(u, v)) {
                        int id = ask(u, v);
                        musorka = min(kekos[c], kekos[id]);
                        if (kekos[c] <= kekos[id]) return;
                        //ta.insert(id, -1);
                        cut(node + my_n + id + 1, node + edge[id].a);
                        cut(node + my_n + id + 1, node + edge[id].b);
                }
                link(edge_node, node + a), link(edge_node, node + b);
                //ta.insert(c, 1);
        }
}lct;

pair <int, int> ret[300000];

struct data
{
  int mn, mn_cnt;
};

data merge(data a, data b)
{
  if (a.mn == b.mn)
  {
    return {a.mn, a.mn_cnt + b.mn_cnt};
  }
  if (a.mn > b.mn)
  {
    return a;
  }
  else
  {
    return b;
  }
}

data t[4 * N];
int d[4 * N];

void push(int v)
{
  t[v * 2 + 1].mn += d[v];
  t[v * 2 + 2].mn += d[v];
  d[v * 2 + 1] += d[v];
  d[v * 2 + 2] += d[v];
  d[v] = 0;
}


data get(int v, int l, int r, int tl, int tr)
{
  if (tl >= r || tr <= l)
  {
    return {-inf, 0};
  }
  if (tl >= l && tr <= r)
  {
    return t[v];
  }
  else
  {
    int tm = (tl + tr) / 2;
    push(v);
    return merge(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
  }
}

void build(int v, int l, int r)
{
  d[v] = 0;
  if (r - l == 1)
  {
    t[v] = {-l, 1};
  }
  else
  {
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

void upd(int v, int l, int r, int tl, int tr)
{
  if (tl >= r || tr <= l)
  {
    return;
  }
  if (tl >= l && tr <= r)
  {
    d[v]++;
    t[v].mn++;
  }
  else
  {
    int tm = (tl + tr) / 2;
    push(v);
    upd(v * 2 + 1, l, r, tl, tm);
    upd(v * 2 + 2, l, r, tm, tr);
    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

int main()
{
#ifdef ONPC
  freopen("a.in", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector <vector <int> > f(n, vector <int> (m));
  //vector <vector <pair <int, int> > > ret(n * m);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> f[i][j];
      f[i][j]--;
      ret[f[i][j]] = {i, j};
    }
  }
  int v = n * m;
  my_n = v;
  null = new Node();
  null->ch[0] = null->ch[1] = null->fa  = null;
  null->mi = null->val = inf;
  for (int i = 1; i <= v; i++)
  {
    lct.node[i].init(inf, null);
  }
  vector <int> vl(v, v);
  int ptr = 0;
  vector <vector <int> > g(v);
  vector <pair <int, int> > edg;
  for (int i = 0; i < n * m; i++)
  {
    int x = ret[i].first, y = ret[i].second;
    for (int t = 0; t < 4; t++)
    {
      if (0 <= x + dx[t] && x + dx[t] < n && 0 <= y + dy[t] && y + dy[t] < m && f[x + dx[t]][y + dy[t]] < f[x][y])
      {
        int j = f[x + dx[t]][y + dy[t]];
        edg.push_back({j, i});
      }
    }
  }
  sort(edg.begin(), edg.end());
  for (int i = 0; i < n * m; i++)
  {
    int x = ret[i].first, y = ret[i].second;
    for (int t = 0; t < 4; t++)
    {
      if (0 <= x + dx[t] && x + dx[t] < n && 0 <= y + dy[t] && y + dy[t] < m && f[x + dx[t]][y + dy[t]] < f[x][y])
      {
        int j = f[x + dx[t]][y + dy[t]];
        g[j].push_back(i);
        musorka = -1;
        int ptr = lower_bound(edg.begin(), edg.end(), make_pair(j, i)) - edg.begin();
        lct.insert(j + 1, i + 1, ptr, j + 1);
        if (musorka != -1)
        {
          vl[musorka - 1] = min(vl[musorka - 1], i);
        }
      }
    }
  }
  for (int i = v - 2; i >= 0; i--)
  {
    vl[i] = min(vl[i], vl[i + 1]);
  }
  ll ans = 0;
  build(0, 0, v);
  for (int i = v - 1; i >= 0; i--)
  {
    for (int x : g[i])
    {
      upd(0, x, v, 0, v);
    }
    if (i < vl[i])
    {
      data ret = get(0, i, vl[i], 0, v);
      if (ret.mn == -i) ans += ret.mn_cnt;
    }
  }
  cout << ans << '\n';
}