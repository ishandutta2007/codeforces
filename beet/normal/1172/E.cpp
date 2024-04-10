#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename Node, size_t LIM, typename Impl>
struct LinkCutTreeBase{
  alignas(Node) static uint8_t pool[sizeof(Node) * LIM];
  static Node* ptr;
  static size_t size;

  template<typename... Args>
  inline Node* create(Args&&... args){
    return new (ptr+size++) Node(std::forward<Args>(args)...);
  }

  inline size_t idx(Node *t){return t-ptr;}
  Node* operator[](size_t k){return ptr+k;}

  inline void toggle(Node *t){
    static_cast<Impl*>(this)->toggle(t);
  }

  inline Node* eval(Node *t){
    return static_cast<Impl*>(this)->eval(t);
  }

  inline void pushup(Node *t){
    static_cast<Impl*>(this)->pushup(t);
  }

  inline Node* expose(Node *t){
    return static_cast<Impl*>(this)->expose(t);
  }

  void rotR(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->l=t->r)) t->r->p=x;
    t->r=x;x->p=t;
    pushup(x);pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  void rotL(Node *t){
    Node *x=t->p,*y=x->p;
    if((x->r=t->l)) t->l->p=x;
    t->l=x;x->p=t;
    pushup(x);pushup(t);
    if((t->p=y)){
      if(y->l==x) y->l=t;
      if(y->r==x) y->r=t;
      pushup(y);
    }
  }

  // for splay tree (not original tree)
  bool is_root(Node *t){
    return !t->p or (t->p->l!=t and t->p->r!=t);
  }

  void splay(Node *t){
    eval(t);
    while(!is_root(t)){
      Node *q=t->p;
      if(is_root(q)){
        eval(q);eval(t);
        if(q->l==t) rotR(t);
        else rotL(t);
      }else{
        auto *r=q->p;
        eval(r);eval(q);eval(t);
        if(r->l==q){
          if(q->l==t) rotR(q),rotR(t);
          else rotL(t),rotR(t);
        }else{
          if(q->r==t) rotL(q),rotL(t);
          else rotR(t),rotL(t);
        }
      }
    }
  }

  // c must be root on LCT
  void link(Node *par,Node *c){
    expose(c);
    expose(par);
    c->p=par;
    par->r=c;
    pushup(par);
  }

  void cut(Node *c){
    expose(c);
    Node *par=c->l;
    c->l=nullptr;
    pushup(c);
    par->p=nullptr;
  }

  void evert(Node *t){
    expose(t);
    toggle(t);
    eval(t);
  }

  Node *parent(Node *t){
    expose(t);
    if(!(t->l)) return nullptr;
    t=eval(t->l);
    while(t->r) t=eval(t->r);
    splay(t);
    return t;
  }

  Node *root(Node *t){
    expose(t);
    while(t->l) t=eval(t->l);
    splay(t);
    return t;
  }

  bool is_connected(Node *a,Node *b){
    return root(a)==root(b);
  }

  Node *lca(Node *a,Node *b){
    expose(a);
    return expose(b);
  }
};
template<typename Node, size_t LIM, typename Impl>
alignas(Node) uint8_t LinkCutTreeBase<Node, LIM, Impl>::pool[];
template<typename Node, size_t LIM, typename Impl>
Node* LinkCutTreeBase<Node, LIM, Impl>::ptr=
  (Node*)LinkCutTreeBase<Node, LIM, Impl>::pool;
template<typename Node, size_t LIM, typename Impl>
size_t LinkCutTreeBase<Node, LIM, Impl>::size=0;
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

#undef call_from_test

#endif
// http://beet-aizu.hatenablog.com/entry/2019/06/08/221833
//BEGIN CUT HERE
template<typename Ap>
struct NodeBase{
  using A = Ap;
  NodeBase *l,*r,*p;
  bool rev;
  A val,dat,sum;
  NodeBase(A val,A dat,A sum):
    rev(0),val(val),dat(dat),sum(sum){
    l=r=p=nullptr;}
};

template<typename Np, size_t LIM>
struct Subtree : LinkCutTreeBase<Np, LIM, Subtree<Np, LIM>>{
  using super = LinkCutTreeBase<Np, LIM, Subtree>;
  using Node = Np;
  using A = typename Node::A;

  Node* create(A val){
    return super::create(Node(val,A(),val));
  }

  inline void toggle(Node *t){
    swap(t->l,t->r);
    t->rev^=1;
  }

  inline Node* eval(Node *t){
    if(t->rev){
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev=false;
    }
    return t;
  }

  inline A resolve(Node *t){
    return t?t->sum:A();
  }

  inline void pushup(Node *t){
    if(t==nullptr) return;
    t->sum=t->val+t->dat;
    t->sum+=resolve(t->l);
    t->sum+=resolve(t->r);
  }

  using super::splay;

  inline Node* expose(Node *t){
    Node *rp=nullptr;
    for(Node *c=t;c;c=c->p){
      splay(c);
      c->dat+=resolve(c->r);
      c->r=rp;
      c->dat-=resolve(c->r);
      pushup(c);
      rp=c;
    }
    splay(t);
    return rp;
  }

  A query(Node *t){
    expose(t);
    return t->sum;
  }

  void set_val(Node *t,A a){
    expose(t);
    t->val=a;
    pushup(t);
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

#undef call_from_test

//INSERT ABOVE HERE

// sum of square
signed CFR564_E(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>> modv(n),modt(n);
  vector<int> cs(n);

  for(int i=0;i<n;i++){
    cin>>cs[i];
    cs[i]--;
    modv[cs[i]].emplace_back(i);
    modt[cs[i]].emplace_back(0);
  }

  vector<vector<int> > G(n+1);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  G[n].emplace_back(0);

  for(int i=1;i<=m;i++){
    int v,x;
    cin>>v>>x;
    v--;x--;
    modv[cs[v]].emplace_back(v);
    modt[cs[v]].emplace_back(i);
    cs[v]=x;
    modv[cs[v]].emplace_back(v);
    modt[cs[v]].emplace_back(i);
  }

  using ll = long long;
  struct A{
    ll sz1,sz2;
    A():sz1(0),sz2(0){}
    A(ll sz1,ll sz2):sz1(sz1),sz2(sz2){}
    A operator+(const A &a)const{
      return A(sz1+a.sz1,sz2+a.sz2);
    };
    A& operator+=(const A &a){
      sz1+=a.sz1;
      sz2+=a.sz1*a.sz1;
      return (*this);
    }
    A& operator-=(const A &a){
      sz1-=a.sz1;
      sz2-=a.sz1*a.sz1;
      return (*this);
    }
  };

  using Node = NodeBase<A>;
  constexpr size_t LIM = 1e6;
  using LCT = Subtree<Node, LIM>;
  LCT lct;

  for(int i=0;i<n+1;i++) lct.create(A(1,0));

  vector<int> par(n+1,0);
  {
    using P = pair<int, int>;
    queue<P> q;
    q.emplace(n,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      par[v]=p;
      if(~p) lct.link(lct[p],lct[v]);
      for(int u:G[v])
        if(u!=p) q.emplace(u,v);
    }
  }

  vector<ll> delta(m+1,0);
  vector<int> color(n+1,0);

  for(int c=0;c<n;c++){
    ll lst=(ll)n*n,cur=(ll)n*n;
    delta[0]+=lst;

    if(modv[c].empty()) continue;
    for(int i=0;i<(int)modv[c].size();i++){
      int v=modv[c][i];
      color[v]^=1;
      if(color[v]){
        cur-=lct.query(lct.root(lct[v])).sz2;
        lct.cut(lct[v]);
        cur+=lct.query(lct.root(lct[par[v]])).sz2;
        cur+=lct.query(lct[v]).sz2;
      }else{
        cur-=lct.query(lct.root(lct[par[v]])).sz2;
        cur-=lct.query(lct[v]).sz2;
        lct.link(lct[par[v]],lct[v]);
        cur+=lct.query(lct.root(lct[v])).sz2;
      }
      if(i+1==(int)modv[c].size() or modt[c][i]!=modt[c][i+1]){
        delta[modt[c][i]]+=cur-lst;
        lst=cur;
      }
    }

    for(int i=0;i<(int)modv[c].size();i++){
      int v=modv[c][i];
      if(!color[v]) continue;
      color[v]^=1;
      lct.link(lct[par[v]],lct[v]);
    }
  }

  ll ans=(ll)n*n*n;
  for(int i=0;i<=m;i++){
    ans-=delta[i];
    cout<<ans<<"\n";
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2020/10/28
  https://codeforces.com/contest/1172/problem/E
*/

signed main(){
  CFR564_E();
  //NIKKEI2019_QUAL_E();
  return 0;
}
#endif