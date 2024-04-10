#include <bits/stdc++.h>
using namespace std;
typedef long long               ll;
const int mod = 1e9+7;
const ll inf = 1LL << 60;

//!escape \section{Generic persistent compressed lazy segment tree}

//!begin_codebook
//!start

/* copied from Tartu U ICPC notebook */
struct Seg{
  ll sum = inf;
  void recalc(const Seg &lhs_seg, int lhs_len, const Seg &rhs_seg, int rhs_len){
    sum = min(lhs_seg.sum, rhs_seg.sum);
  }
} __attribute__((packed));

struct Lazy{
  ll add;
  ll assign_val; //LLONG\_MIN if no assign;
  void init(){
    add = 0;
    assign_val = LLONG_MIN;
  }
  Lazy(){ init(); }
  void split(Lazy &lhs_lazy, Lazy &rhs_lazy, int len){
    lhs_lazy = *this;
    rhs_lazy = *this;
    init();
  }
  void merge(Lazy &oth, int len){
    if(oth.assign_val != LLONG_MIN){
      add = 0;
      assign_val = oth.assign_val;
    }
    add += oth.add;
  }
  void apply_to_seg(Seg &cur, int len) const{
    if(assign_val != LLONG_MIN){
      cur.sum =	len * assign_val;
    }
    cur.sum += add;
  } 
} __attribute__((packed));

//!finish
//!start

struct Node{ //Following code should not need to be modified
  int ver;
  bool is_lazy = false;
  Seg seg;
  Lazy lazy;
	Node *lc=NULL, *rc=NULL;
	void init(){
		if(!lc){
			lc = new Node {ver};
			rc = new Node {ver};
		}
	}
  Node *upd(int L, int R, int l, int r, Lazy &val, int tar_ver){
    if(ver != tar_ver){
      Node *rep = new Node(*this);
      rep->ver = tar_ver;
      return rep->upd(L, R, l, r, val, tar_ver);
    }
    if(L >= l && R <= r){
      val.apply_to_seg(seg, R-L);
      lazy.merge(val, R-L);
      is_lazy = true;
    } else {
      init();
      int M = (L+R)/2;
      if(is_lazy){
        Lazy l_val , r_val;
        lazy.split(l_val, r_val, R-L);
        lc = lc->upd(L, M, L, M, l_val, ver);
        rc = rc->upd(M, R, M, R, r_val, ver);
        is_lazy = false;
      }
      Lazy l_val , r_val;
      val.split(l_val, r_val, R-L);
      if(l < M)
        lc = lc->upd(L, M, l, r, l_val, ver);
      if(M < r)
        rc = rc->upd(M, R, l, r, r_val, ver);
      seg.recalc(lc->seg, M-L, rc->seg, R-M);
    }
    return this;
  }
  void get(int L, int R, int l, int r, Seg *&lft_res, Seg *&tmp, bool last_ver){
    if(L >= l && R <= r){
      tmp->recalc(*lft_res, L-l, seg, R-L);
      swap(lft_res, tmp);
    } else {
      init();
      int M = (L+R)/2;
      if(is_lazy){
        Lazy l_val , r_val;
        lazy.split(l_val, r_val, R-L);
        lc = lc->upd(L, M, L, M, l_val, ver+last_ver);
        lc->ver = ver;
        rc = rc->upd(M, R, M, R, r_val, ver+last_ver);
        rc->ver = ver;
        is_lazy = false;
      }
      if(l < M)
        lc->get(L, M, l, r, lft_res, tmp, last_ver);
      if(M < r)
        rc->get(M, R, l, r, lft_res, tmp, last_ver);
    }
  }
} __attribute__((packed));

struct SegTree{ //indexes start from 0, ranges are [beg, end)
  vector<Node *> roots; //versions start from 0
  int len;
  SegTree() {}
  SegTree(int _len) : len(_len){
    roots.push_back(new Node {0});
  }
  int upd(int l, int r, Lazy &val, bool new_ver = false){
    Node *cur_root = roots.back()->upd(0, len, l, r, val, roots.size()-!new_ver);
    if(cur_root != roots.back())
      roots.push_back(cur_root);
    return roots.size()-1;
  }
  Seg get(int l, int r, int ver = -1){
    if(ver == -1)
      ver = roots.size()-1;
    Seg seg1, seg2;
    Seg *pres = &seg1, *ptmp = &seg2;
    roots[ver]->get(0, len, l, r, pres, ptmp, roots.size()-1);
    return *pres;
  }
};

//!finish
//!begin_codebook
/*
int main(){

//!begin_codebook
  ll n, m; //solves Mechanics Practice LAZY
  cin>>n>>m;
	SegTree seg_tree(1<<17);
  for(ll i=0; i<n; ++i){
    Lazy tmp;
    scanf("%lld", &tmp.assign_val);
    seg_tree.upd(i, i+1, tmp);
  }
  for(ll i=0; i<m; ++i){
    ll o;
    ll l, r;
    scanf("%d %d %d", &o, &l, &r);
    --l;
    if(o==1){
      Lazy tmp;
      scanf("%lld", &tmp.add);
      seg_tree.upd(l, r, tmp);
    } else if(o==2){
      Lazy tmp;
      scanf("%lld", &tmp.assign_val);
      seg_tree.upd(l, r, tmp);
    } else {
      Seg res = seg_tree.get(l, r);
      prllf("%lld\n",res.sum);
    }
  }
//!end_codebook
#endif
//!begin_codebook
}
//!end_codebook
*/

const ll maxn = 500005;

ll ans [maxn];
ll weight [maxn];
vector<pair<pair<ll, ll>, ll>> queries [maxn];
ll euler [maxn];
vector<ll> children [maxn];
ll lvl [maxn];
ll lfend [maxn];
ll rgend [maxn];

ll cur_id = 1;
void build_euler (ll vertex, ll parent) {
  euler[vertex] = cur_id;
  lfend[vertex] = cur_id;
  cur_id++;
  if (vertex == 1) {
    lvl[vertex] = 0;
  } else {
    lvl[vertex] = lvl[parent] + weight[vertex];
  }

  for (ll u : children[vertex]) {
    build_euler(u, vertex);
  }
  rgend[vertex] = cur_id;
}

SegTree dists;

void build_ans (ll vertex) {
  if (vertex != 1) {
    Lazy incr1;
    incr1.add = -weight[vertex];
    dists.upd(lfend[vertex], rgend[vertex], incr1);

    Lazy decr1;
    decr1.add = weight[vertex];
    dists.upd(0, lfend[vertex], decr1);

    Lazy decr2;
    decr2.add = weight[vertex];
    dists.upd(rgend[vertex], maxn, decr2);
  }

  for (pair<pair<ll, ll>, ll> query : queries[vertex]) {
    ll l = query.first.first;
    ll r = query.first.second;
    ll idx = query.second;

    ans[idx] = dists.get(l, r + 1).sum;
  }

  for (ll nxt : children[vertex]) {
    build_ans(nxt);
  }

  if (vertex != 1) {
    Lazy incr1;
    incr1.add = weight[vertex];
    dists.upd(lfend[vertex], rgend[vertex], incr1);

    Lazy decr1;
    decr1.add = -weight[vertex];
    dists.upd(0, lfend[vertex], decr1);

    Lazy decr2;
    decr2.add = -weight[vertex];
    dists.upd(rgend[vertex], maxn, decr2);
  }
}  
  
int main () {
  ios::sync_with_stdio(false);

  dists = SegTree (1 << 20);
  
  ll vertexc, queryc;
  cin >> vertexc >> queryc;

  for (ll i = 2; i <= vertexc; i++) {
    ll p, w;
    cin >> p >> w;

    children[p].push_back(i);
    weight[i] = w;
  }

  for (ll i = 0; i < queryc; i++) {
    ll v, l, r;
    cin >> v >> l >> r;

    queries[v].push_back(make_pair(make_pair(l, r), i));
  }

  build_euler(1, 0);

  for (ll i = 2; i <= vertexc; i++) {
    if ((ll) children[i].size() == 0) {
      Lazy tmp;
      tmp.add = -inf + lvl[i];
      dists.upd(euler[i], euler[i] + 1, tmp);
    }
  }

  build_ans(1);
  
  for (ll i = 0; i < queryc; i++) {
    cout << ans[i] << '\n';
  }
}