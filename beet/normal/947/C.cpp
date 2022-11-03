#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T,size_t X>
struct BinaryTrie{
  struct Node{
    size_t cnt;
    Node *p,*l,*r;
    Node(Node* p):cnt(0),p(p){l=r=nullptr;}
  };

  T acc;
  Node *root;
  BinaryTrie():acc(0){root=emplace(nullptr);}

  void dfs(Node *a){
    if(!a) return;
    dfs(a->l);dfs(a->r);
    delete(a);
  }

  inline Node* emplace(Node* p){
    return new Node(p);
  }

  inline size_t count(Node* a){
    return a?a->cnt:0;
  }

  void add(const T b,size_t k=1){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!f&&!a->l) a->l=emplace(a);
      if( f&&!a->r) a->r=emplace(a);
      a=f?a->r:a->l;
    }
    a->cnt+=k;
    while((a=a->p)) a->cnt=count(a->l)+count(a->r);
  }

  inline void update(const T b){acc^=b;}

  Node* find(const T b){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      a=f?a->r:a->l;
      if(!a) return a;
    }
    return a;
  }

  Node* check(Node *a){
    if(!a||count(a)) return a;
    delete(a);
    return nullptr;
  }

  void sub(Node* a,size_t k=1){
    assert(a&&a->cnt>=k);
    a->cnt-=k;
    while((a=a->p)){
      a->l=check(a->l);
      a->r=check(a->r);
      a->cnt=count(a->l)+count(a->r);
    }
  }

  Node* xmax(const T b){
    assert(count(root));
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!a->l||!a->r) a=a->l?a->l:a->r;
      else a=f?a->l:a->r;
    }
    return a;
  }

  Node* xmin(const T b){
    return xmax(~b&((T(1)<<X)-1));
  }

  Node* ge(Node *a,int i){
    if(!a) return a;
    Node *l=a->l,*r=a->r;
    if((acc>>i)&1) swap(l,r);
    if(l||r) return ge(l?l:r,i+1);
    return a;
  }

  Node* next(Node* a,int i){
    if(!(a->p)) return nullptr;
    Node *l=a->p->l,*r=a->p->r;
    if((acc>>(i+1))&1) swap(l,r);
    if(a==l&&r) return ge(r,i);
    return next(a->p,i+1);
  }

  Node* lower_bound(const T b){
    const T nb=b^acc;
    Node* a=root;
    for(int i=X-1;i>=0;i--){
      bool f=(nb>>i)&1;
      if(!f&&a->l){a=a->l;continue;}
      if( f&&a->r){a=a->r;continue;}
      if((b>>i)&1) return next(a,i);
      return ge(a,i);
    }
    return a;
  }

  Node* upper_bound(const T b){
    return lower_bound(b+1);
  }

  T val(Node* a){
    T res(0);
    for(int i=0;i<(int)X;i++){
      assert(a->p);
      res|=(T(a==a->p->r)<<i);
      a=a->p;
    }
    return res^acc;
  }

  Node* find_by_order(size_t k){
    Node *a=root;
    if(count(a)<=k) return nullptr;
    for(int i=X-1;i>=0;i--){
      bool f=(acc>>i)&1;
      if(count(f?a->r:a->l)<=k){
        k-=count(f?a->r:a->l);
        a=f?a->l:a->r;
      }else{
        a=f?a->r:a->l;
      }
    }
    return a;
  }

  size_t order_of_key(const T b){
    Node *a=root;
    size_t res=0;
    for(int i=X-1;i>=0;i--){
      Node *l=a->l,*r=a->r;
      if((acc>>i)&1) swap(l,r);
      bool f=(b>>i)&1;
      if(f) res+=count(l);
      a=f?r:l;
      if(!a) break;
    }
    return res;
  }
};
//END CUT HERE
#ifndef call_from_test
signed JAG2013SUMMERWARMINGUP_F(){
  int n;
  scanf("%d",&n);
  vector<int> a(n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  vector<int> s(n+1,0);
  for(int i=0;i<n;i++) s[i+1]=s[i]^a[i];
  BinaryTrie<int, 30> bt;
  using ull = unsigned long long;
  map<ull, int> r;
  bt.add(0);
  r[(ull)bt.find(0)]=0;
  int ans=-1,idx=-1,idy=-1;
  for(int i=0;i<n;i++){
    int k=r[(ull)bt.xmax(a[i])];
    int res=s[i+1]^s[k];
    if(ans<res||(ans==res&&idx>k)){
      ans=res;
      idx=k;
      idy=i;
    }
    bt.update(a[i]);
    bt.add(0);
    if(!r.count((ull)bt.find(0))) r[(ull)bt.find(0)]=i+1;
  }
  printf("%d %d %d\n",ans,idx+1,idy+1);
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/jag2013summer-warmingup/tasks/icpc2013summer_warmingUp_f
*/

signed ARC033_C(){
  int q;
  scanf("%d",&q);
  BinaryTrie<int, 30> bt;
  while(q--){
    int t,x;
    scanf("%d %d",&t,&x);
    if(t==1) bt.add(x);
    if(t==2){
      auto k=bt.find_by_order(x-1);
      printf("%d\n",bt.val(k));
      bt.sub(k);
    }
  }
  return 0;
}

/*
  verified on 2019/10/25
  https://atcoder.jp/contests/arc033/tasks/arc033_3
*/

signed CFR470_C(){
  int n;
  scanf("%d",&n);
  vector<int> a(n),p(n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  for(int i=0;i<n;i++) scanf("%d",&p[i]);

  BinaryTrie<int, 30> bt;
  for(int i=0;i<n;i++) bt.add(p[i]);

  for(int i=0;i<n;i++){
    if(i) printf(" ");
    auto k=bt.xmin(a[i]);
    printf("%d",a[i]^bt.val(k));
    bt.sub(k);
  }
  puts("");
  return 0;
}
/*
  verified on 2019/10/25
  http://codeforces.com/contest/947/problem/C
*/

signed CFR477_C(){
  using ll = long long;

  int n;
  scanf("%d",&n);
  vector<ll> bs(n);
  for(int i=0;i<n;i++) scanf("%lld",&bs[i]);

  BinaryTrie<ll, 61> bt;
  for(int i=0;i<n;i++) bt.add(bs[i]);

  ll z=0;
  auto apply=[&](ll a){
               z^=a;
               bt.update(a);
             };

  vector<ll> ans;
  ll x=bt.val(bt.xmin(0));

  ans.emplace_back(x);
  bt.sub(bt.find(x));
  apply(x);

  for(int i=1;i<n;i++){
    if(bt.val(bt.xmax(0))<=x){
      printf("No\n");
      return 0;
    }
    auto nxt=bt.upper_bound(x);
    ll y=bt.val(nxt);

    ans.emplace_back(y^z);
    bt.sub(nxt);
    apply(x^y);
    x=y;
  }

  printf("Yes\n");
  for(int i=0;i<n;i++){
    if(i) printf(" ");
    printf("%lld",ans[i]);
  }
  puts("");
  return 0;
}
/*
  verified on 2019/10/25
  http://codeforces.com/contest/966/problem/C
*/

#define call_from_test
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
class HLD {
private:
  void dfs_sz(int v) {
    for(int &u:G[v]){
      if(u==par[v]) continue;
      par[u]=v;
      dep[u]=dep[v]+1;
      dfs_sz(u);
      sub[v]+=sub[u];
      if(sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
    }
  }

  void dfs_hld(int v,int c,int &pos) {
    vid[v]=pos++;
    inv[vid[v]]=v;
    type[v]=c;
    for(int u:G[v]){
      if(u==par[v]) continue;
      head[u]=(u==G[v][0]?head[v]:u);
      dfs_hld(u,c,pos);
    }
  }

public:
  vector<vector<int> > G;
  vector<int> vid, head, sub, par, dep, inv, type;

  HLD(int n):
    G(n),vid(n,-1),head(n),sub(n,1),
    par(n,-1),dep(n,0),inv(n),type(n){}

  void add_edge(int u,int v) {
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void build(vector<int> rs={0}) {
    int c=0,pos=0;
    for(int r:rs){
      dfs_sz(r);
      head[r]=r;
      dfs_hld(r,c++,pos);
    }
  }

  int lca(int u,int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }

  // for_each(vertex)
  // [l, r) <- attention!!
  template<typename F>
  void for_each(int u, int v, const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      f(max(vid[head[v]],vid[u]),vid[v]+1);
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
  }

  template<typename T,typename Q,typename F>
  T for_each(int u,int v,T ti,const Q &q,const F &f){
    T l=ti,r=ti;
    while(1){
      if(vid[u]>vid[v]){
        swap(u,v);
        swap(l,r);
      }
      l=f(l,q(max(vid[head[v]],vid[u]),vid[v]+1));
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
    return f(l,r);
  }

  // for_each(edge)
  // [l, r) <- attention!!
  template<typename F>
  void for_each_edge(int u, int v,const F& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
        f(vid[head[v]],vid[v]+1);
        v=par[head[v]];
      }else{
        if(u!=v) f(vid[u]+1,vid[v]+1);
        break;
      }
    }
  }
};
//END CUT HERE
#ifndef call_from_test
template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,T ti):f(f),ti(ti){}
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }
  T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?k-n:-1;
    }
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};

struct LowLink{
  int n,pos;
  vector<int> ord,low,par,blg,num;
  vector<vector<int> > G,C,T;
  vector<vector<pair<int, int> > > E;

  vector<int> ap;
  vector<pair<int, int> > bs,cand;

  LowLink(int n):n(n),pos(0),ord(n,-1),low(n),
                 par(n,-1),blg(n,-1),num(n,1),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  bool is_bridge(int u,int v){
    if(ord[u]>ord[v]) swap(u,v);
    return ord[u]<low[v];
  }

  void dfs(int v){
    ord[v]=low[v]=pos++;
    for(int u:G[v]){
      if(u==par[v]) continue;
      if(ord[u]<ord[v])
        cand.emplace_back(min(u,v),max(u,v));
      if(~ord[u]){
        low[v]=min(low[v],ord[u]);
        continue;
      }
      par[u]=v;
      dfs(u);
      num[v]+=num[u];
      low[v]=min(low[v],low[u]);
      if(is_bridge(u,v)) bs.emplace_back(u,v);
      if(low[u]>=ord[v]){
        E.emplace_back();
        while(1){
          auto e=cand.back();
          cand.pop_back();
          E.back().emplace_back(e);
          if(make_pair(min(u,v),max(u,v))==e) break;
        }
      }
    }
  }

  void fill_component(int v){
    C[blg[v]].emplace_back(v);
    for(int u:G[v]){
      if(~blg[u]||is_bridge(u,v)) continue;
      blg[u]=blg[v];
      fill_component(u);
    }
  }

  void add_component(int v,int &k){
    if(~blg[v]) return;
    blg[v]=k++;
    C.emplace_back();
    fill_component(v);
  }

  int build(){
    for(int i=0;i<n;i++)
      if(ord[i]<0) dfs(i);

    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
      int p=par[i];
      if(p<0) continue;
      if(par[p]<0) cnt[p]++;
      else if(ord[p]<=low[i]) ap.emplace_back(p);
    }

    for(int i=0;i<n;i++)
      if(cnt[i]>1) ap.emplace_back(i);

    sort(ap.begin(),ap.end());
    ap.erase(unique(ap.begin(),ap.end()),ap.end());

    int k=0;
    for(int i=0;i<n;i++) add_component(i,k);

    T.assign(k,vector<int>());
    for(auto e:bs){
      int u=blg[e.first],v=blg[e.second];
      T[u].emplace_back(v);
      T[v].emplace_back(u);
    }
    return k;
  }
};

//INSERT ABOVE HERE
signed YUKI_529(){
  int n,e,q;
  scanf("%d %d %d",&n,&e,&q);

  LowLink big(n);
  for(int i=0;i<e;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    u--;v--;
    big.add_edge(u,v);
  }

  int E=0,V=big.build();
  HLD hld(V);
  for(int i=0;i<V;i++)
    for(int j:big.T[i])
      if(i<j) hld.add_edge(i,j),E++;
  hld.build();

  SegmentTree<int> rmq([](int a,int b){return max(a,b);},-1);
  rmq.build(vector<int>(V,-1));

  vector<priority_queue<int> > pq(V);
  map<int,int> m;
  int num=0;
  for(int i=0;i<q;i++){
    int d;
    scanf("%d",&d);
    if(d==1){
      int u,w;
      scanf("%d %d",&u,&w);
      u--;
      u=big.blg[u];
      u=hld.vid[u];
      m[w]=u;
      if(pq[u].empty()||pq[u].top()<w) rmq.set_val(u,w);
      pq[u].push(w);
      num++;
    }
    if(d==2){
      int s,t;
      scanf("%d %d",&s,&t);
      s--;t--;
      s=big.blg[s];
      t=big.blg[t];
      auto f=[&](int l,int r){return rmq.query(l,r);};
      int ans=hld.for_each(s,t,-1,f,rmq.f);
      printf("%d\n",ans);
      if(~ans){
        int k=m[ans];
        pq[k].pop();
        rmq.set_val(k,(!pq[k].empty()?pq[k].top():-1));
        num--;
      }
    }
  }
  return 0;
}
/*
  verified on 2019/07/08
  https://yukicoder.me/problems/no/529
*/
signed main(){
  //YUKI_529();
  return 0;
};
#endif

#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct LevelAncestor{
  int n,h;
  vector<vector<int> > G,par,lad;
  vector<int> dep,nxt,len,pth,ord,hs;
  LevelAncestor(){}
  LevelAncestor(int n):
    n(n),G(n),dep(n),nxt(n,-1),len(n),pth(n),ord(n),hs(n+1,0){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<int>(n,-1));
    for(int i=2;i<=n;i++) hs[i]=hs[i>>1]+1;
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d,int f){
    if(nxt[v]<0){
      par[0][nxt[v]=v]=p;
      len[v]=dep[v]=d;
      for(int u:G[v]){
        if(u==p) continue;
        dfs(u,v,d+1,0);
        if(len[v]<len[u]) nxt[v]=u,len[v]=len[u];
      }
    }
    if(!f) return;
    pth[v]=lad.size();
    lad.emplace_back();
    for(int k=v;;k=nxt[k]){
      lad.back().emplace_back(k);
      pth[k]=pth[v];
      if(k==nxt[k]) break;
    }
    for(;;p=v,v=nxt[v]){
      for(int u:G[v])
        if(u!=p&&u!=nxt[v]) dfs(u,v,d+1,1);
      if(v==nxt[v]) break;
    }
  }

  void build(int r=0){
    dfs(r,-1,0,1);
    for(int k=0;k+1<h;k++){
      for(int v=0;v<n;v++){
        if(par[k][v]<0) par[k+1][v]=-1;
        else par[k+1][v]=par[k][par[k][v]];
      }
    }
    for(int i=0;i<(int)lad.size();i++){
      int v=lad[i][0],p=par[0][v];
      if(~p){
        int k=pth[p],l=min(ord[p]+1,(int)lad[i].size());
        lad[i].resize(l+lad[i].size());
        for(int j=0,m=lad[i].size();j+l<m;j++)
          lad[i][m-(j+1)]=lad[i][m-(j+l+1)];
        for(int j=0;j<l;j++)
          lad[i][j]=lad[k][ord[p]-l+j+1];
      }
      for(int j=0;j<(int)lad[i].size();j++)
        if(pth[lad[i][j]]==i) ord[lad[i][j]]=j;
    }
  }

  int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<h;k++){
      if((dep[v]-dep[u])>>k&1){
        v=par[k][v];
      }
    }
    if(u==v) return u;
    for(int k=h-1;k>=0;k--){
      if(par[k][u]!=par[k][v]){
        u=par[k][u];
        v=par[k][v];
      }
    }
    return par[0][u];
  }

  int up(int v,int d){
    if(d==0) return v;
    v=par[hs[d]][v];
    d-=1LL<<hs[d];
    return lad[pth[v]][ord[v]-d];
  }

  int distance(int u,int v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
char buf[256];
signed solve(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  using P = pair<int, int>;
  vector<vector<P> > G(n);
  LevelAncestor la(n);
  for(int i=1;i<n;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--;b--;
    la.add_edge(a,b);
    G[a].emplace_back(b,c);
    G[b].emplace_back(a,c);
  }
  la.build();

  vector<ll> dep(n,0);
  {
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      for(auto e:G[v]){
        int u,c;
        tie(u,c)=e;
        if(u==p) continue;
        dep[u]=dep[v]+c;
        q.emplace(u,v);
      }
    }
  }

  while(scanf("%s",buf)){
    string s(buf);
    if(s=="DONE"s) break;
    if(s=="DIST"s){
      int a,b;
      scanf("%d %d",&a,&b);
      a--;b--;
      printf("%lld\n",dep[a]+dep[b]-2*dep[la.lca(a,b)]);
    }
    if(s=="KTH"s){
      int a,b,k;
      scanf("%d %d %d",&a,&b,&k);
      a--;b--;k--;
      int l=la.lca(a,b);
      int x=la.distance(a,l),y=la.distance(l,b);
      assert(0<=k&&k<=x+y);
      printf("%d\n",(k<=x?la.up(a,k):la.up(b,x+y-k))+1);
    }
  }
  return 0;
}

signed SPOJ_QTREE2(){
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++) solve();
  return 0;
}
/*
  verified on 2019/10/25
  https://www.spoj.com/problems/QTREE2/
*/

signed main(){
  SPOJ_QTREE2();
  return 0;
}
#endif

#undef call_from_test

//INSERT ABOVE HERE
signed KUPC2018_M(){
  using ll = long long;
  int n;
  scanf("%d",&n);
  HLD hld(n);
  LevelAncestor la(n);
  for(int i=1;i<n;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    hld.add_edge(a,b);
    la.add_edge(a,b);
  }
  hld.build();
  la.build();

  using T = BinaryTrie<int, 31>;
  using E = pair<int, ll>;

  struct SegmentTree{
    int n;
    vector<T> dat;
    SegmentTree(int n_){
      n=1;
      while(n<n_) n<<=1;
      dat=vector<T>(n*2);
      for(int i=0;i<n*2;i++) dat[i]=T();
    }
    void reset(){
      for(int i=0;i<n*2;i++) dat[i].dfs(dat[i].root);
    }
    void update(int a,int b,E x){
      for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
        if(l&1) dat[l++].add(x.first,x.second);
        if(r&1) dat[--r].add(x.first,x.second);
      }
    }
    ll query(int k,E x){
      ll res=0;
      k+=n;
      while(k){
        dat[k].update(x.first);
        res+=dat[k].order_of_key(x.second+1);
        dat[k].update(x.first);
        k>>=1;
      }
      return res;
    }
  };

  int q;
  scanf("%d",&q);

  vector<int> type(q),vs(q),xs(q),ks(q),ys(q),zs(q);
  vector<ll> ans(q);
  for(int i=0;i<q;i++){
    scanf("%d",&type[i]);
    if(type[i]==1) scanf("%d %d %d",&vs[i],&xs[i],&ks[i]);
    if(type[i]==2) scanf("%d %d %d",&vs[i],&ys[i],&zs[i]);
    if(type[i]==3) scanf("%d",&vs[i]);
    vs[i]--;
  }

  const int UKU = 8;
  for(int uku=0;uku<UKU;uku++){
    SegmentTree seg(n);
    int rt=0;
    for(int i=0;i<q;i++){
      if(type[i]==1&&(i%UKU)==uku){
        int v=vs[i],x=xs[i],k=ks[i];
        if(rt==v){
          seg.update(0,n,E(x,k));
        }else if(hld.lca(rt,v)==v){
          int u=la.up(rt,hld.distance(rt,v)-1);
          int l=hld.vid[u],r=hld.vid[u]+hld.sub[u];
          seg.update(0,l,E(x,k));
          seg.update(r,n,E(x,k));
        }else{
          int l=hld.vid[v],r=hld.vid[v]+hld.sub[v];
          seg.update(l,r,E(x,k));
        }
      }
      if(type[i]==2){
        int v=vs[i],y=ys[i],z=zs[i];
        ans[i]+=seg.query(hld.vid[v],E(y,z));
      }
      if(type[i]==3){
        rt=vs[i];
      }
    }
    seg.reset();
  }

  for(int i=0;i<q;i++)
    if(type[i]==2) printf("%lld\n",ans[i]);
  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/kupc2018/tasks/kupc2018_m
*/

signed main(){
  //JAG2013SUMMERWARMINGUP_F();
  //ARC033_C();
  CFR470_C();
  //CFR477_C();
  //KUPC2018_M();
  return 0;
}
#endif