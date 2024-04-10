#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

template <typename T, typename F>
struct SegmentTree{
  // using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){}
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
  int find(C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?k-n:-1;
    }
    int m=(l+r)>>1;
    if(!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(check,acc,(k<<1)|1,m,r);
  }
  template<typename C>
  int find(C &check){
    T acc=ti;
    return find(check,acc,1,0,n);
  }
};

template<size_t len>
struct LCA{
  const int lg = 12;
  const int sz = 1<<lg;
  const int ms = sz-1;
  int n;
  array<int, len> P,D,E,A,B,T;
  vector<int> ht;
  vector<vector<int> > G,dat;
  LCA(int n):n(n),G(n){
    fill(P.begin(),P.end(),-1);
    fill(E.begin(),E.end(),0);
    fill(A.begin(),A.end(),-1);
    fill(T.begin(),T.end(),0);
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p,int d){
    int k=0,u;
    vector<int> iter(n,0);

    using T = tuple<int, int, int>;
    stack<T> st;

  START:
    D[v]=k;
    A[k]=P[v]=p;
    E[k++]=d;
    for(;iter[v]<(int)G[v].size();iter[v]++){
      u=G[v][iter[v]];
      if(u==p) continue;
      st.emplace(v,p,d);
      p=v;v=u;d=d+1;
      goto START;
    END:
      tie(v,p,d)=st.top();st.pop();
    }

    A[k]=P[v];
    E[k++]=d-1;

    if(!st.empty()) goto END;
  }

  // if it need leftmost, then add: if(E[i]==E[j]) return i<j?i:j;
  inline int comp(int i,int j){return E[i]<E[j]?i:j;};
  inline int comp(int i,int j,int k){return comp(comp(i,j),k);};

  void build(int r=0){
    dfs(r,-1,1);

    B[0]=1;
    for(int i=1;i<n*2;i++) B[i/lg]|=(E[i-1]<E[i])<<(i%lg);

    for(int b=0;b<sz;b++){
      int e=0,w=1,&x=T[b];
      for(int i=0;i<lg;i++){
        if((b>>i)&1) e++;
        else e--;
        if(e<w) e=w,x=i;
      }
    }

    int m=(n*2+lg-1)/lg;
    int h=1;
    while((1<<h)<m) h++;
    dat.assign(h,vector<int>(m,-1));
    ht.assign(m+1,0);
    for(int j=2;j<=m;j++) ht[j]=ht[j>>1]+1;

    for(int j=0;j<n*2;j++){
      if(dat[0][j/lg]<0) dat[0][j/lg]=j;
      dat[0][j/lg]=comp(dat[0][j/lg],j);
    }

    for(int i=1,p=1;i<h;i++,p<<=1)
      for(int j=0;j<m;j++)
        dat[i][j]=comp(dat[i-1][j],dat[i-1][min(j+p,m-1)]);
  }

  inline int cs(int a,int b){
    int l=b-a;
    return comp(dat[ht[l]][a],dat[ht[l]][b-(1<<ht[l])]);
  }

  inline int es(int i,int l,int r){
    int x=r-i*lg+1,y=l-i*lg;
    int b=(((B[i]|(ms<<x))>>y)|(ms<<(lg-y)))&ms;
    return l+T[b];
  }

  inline int ls(int i,int l){
    int k=l-i*lg;
    int b=((B[i]>>k)|(ms<<(lg-k)))&ms;
    return l+T[b];
  }

  inline int rs(int j,int r){
    int k=r-j*lg+1;
    int b=(B[j]|(ms<<k))&ms;
    return j*lg+T[b];
  }

  inline int rmq(int l,int r){
    int i=l/lg,j=r/lg;
    if(i==j) return es(i,l,r);
    if(i+1==j) return comp(ls(i,l),rs(j,r));
    return comp(ls(i,l),cs(i+1,j),rs(j,r));
  }

  int lca(int l,int r){
    if(l==r) return l;
    if(D[l]>D[r]) swap(l,r);
    int x=D[l],y=D[r];
    int m=rmq(x,y);
    return m==x?l:A[m];
  }
};

//INSERT ABOVE HERE
signed main(){
  int n;
  cin>>n;
  vector<int> ps(n);
  for(int i=0;i<n;i++) cin>>ps[i];
  const int len = 4e5+100;
  LCA<len> H(n);
  for(int i=1;i<n;i++){
    int d;
    cin>>d;
    d--;
    H.add_edge(d,i);
  }
  H.build();

  vector<int> dep(n);
  for(int i=0;i<n;i++) dep[i]=H.E[H.D[i]];
  auto distance=
    [&](int p,int q){
      int r=H.lca(p,q);
      return dep[p]+dep[q]-dep[r]*2;
    };

  struct T{
    int p,q;
    T(int p,int q):p(p),q(q){}
  };

  const int m=4;
  int dd[m],di[m][m]={},vs[m];
  auto f=[&](T a,T b){
           if(a.p<0&&a.q<0) return b;
           if(b.p<0&&b.q<0) return a;
           if(a.p<0||b.p<0) return T(-1,0);

           int r=H.lca(H.lca(a.p,a.q),H.lca(b.p,b.q));
           vs[0]=a.p;vs[1]=a.q;vs[2]=b.p;vs[3]=b.q;

           for(int i=0;i<m;i++) dd[i]=dep[vs[i]]-dep[r];

           for(int i=0;i<m;i++)
             for(int j=0;j<i;j++)
               di[i][j]=di[j][i]=distance(vs[i],vs[j]);

           for(int i=0;i<m;i++){
             for(int j=0;j<i;j++){
               int p=vs[i],q=vs[j];
               if(r!=H.lca(p,q)) continue;

               int flg=1,dpr=dd[i],dqr=dd[j];
               for(int k=0;k<m;k++)
                 flg&=(di[i][k]+dd[k]==dpr)||(di[j][k]+dd[k]==dqr);

               if(flg) return T(p,q);
             }
           }
           return T(-1,0);
         };
  T ti(-1,-1);
  SegmentTree<T, decltype(f)> seg(f,ti);
  vector<T> vt(n,ti);
  for(int i=0;i<n;i++) vt[ps[i]]=T(i,i);
  seg.build(vt);

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      int x,y;
      cin>>x>>y;
      x--;y--;
      swap(ps[x],ps[y]);
      seg.set_val(ps[x],T(x,x));
      seg.set_val(ps[y],T(y,y));
    }
    if(t==2){
      auto check=[&](T x){return x.p<0&&x.q>=0;};
      int res=seg.find(check);
      cout<<(~res?res:n)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}