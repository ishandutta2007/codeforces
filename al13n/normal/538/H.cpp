#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
typedef pair<LL, LL> pll;
typedef pair<ULL, ULL> puu;
typedef pair<ld, ld> pdd;
template<class T> inline T sqr(T x) { return x * x; }
template<class T> inline string tostr(const T & x) { stringstream ss; ss << x; return ss.str(); }
inline LL parse(const string & s) { stringstream ss(s); LL x; ss >> x; return x; }
#define left asdleft
#define right asdright
#define link asdlink
#define unlink asdunlink
#define next asdnext
#define prev asdprev
#define y0 asdy0
#define y1 asdy1
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define forn(i,n) for(int i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define X first
#define Y second
#define hash asdhash
#define move asdmove
const ld EPS = 1e-9;
const int inf = 1000*1000*1000;
const char cinf = 102;
const LL linf = inf * 1ll * inf;
const ld dinf = 1e200;
const ld PI = 3.1415926535897932384626433832795l;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
LL gcd(LL a,LL b){return a?gcd(b%a,a):b;}
LL powmod(LL a,LL p,LL m){LL r=1;while(p){if(p&1)r=r*a%m;p>>=1;a=a*a%m;}return r;}
#define FAIL { cerr<<"assertion failed on line "<<__LINE__<<endl; exit(123);}

struct segtree{
  vector<int> T,D;

  segtree(int n):T(n*4+10),D(n*4+10){}

  void add(int l,int r,int v,int a,int b,int k){
    if(l>=b || r<=a)
      return;
    if(l<=a && r>=b){
      D[k]+=v;
      T[k]+=v;
      return;
    }
    int c=(a+b)/2;
    add(l,r,v,a,c,k*2+1);
    add(l,r,v,c,b,k*2+2);
    T[k]=D[k]+max(T[k*2+1],T[k*2+2]);
  }
  int find(int a,int b,int k){
    if(b==a+1)
      return a;
    int c=(a+b)/2;
    if(T[k*2+1]>T[k*2+2])
      return find(a,c,k*2+1);
    else
      return find(c,b,k*2+2);
  }
};

struct group{
  int l[2]{0,0},r[2];
  vector<pii> id;

  group(int c):r{c,c}{}
};

pair<pii,string> solve(int tt,int TT,vector<pii> R,vector<pii> E){
  int n=sz(R);
  vector<int> xs={0,tt,TT};
  forn(i,n){
    xs.pb(R[i].X);
    xs.pb(max(0,tt-R[i].X));
    xs.pb(max(0,TT-R[i].X));
    xs.pb(R[i].Y-1);
    xs.pb(max(0,tt-(R[i].Y-1)));
    xs.pb(max(0,TT-(R[i].Y-1)));
  }

  sort(all(xs));
  xs.erase(unique(all(xs)),xs.end());
  for(auto& x:R){
    x.X=lower_bound(all(xs),x.X)-xs.begin();
    x.Y=lower_bound(all(xs),x.Y)-xs.begin();
  }

  vector<group> G;

  {
    vector<vector<int>> gr(n);
    forv(i,E){
      gr[E[i].X].pb(E[i].Y);
      gr[E[i].Y].pb(E[i].X);
    }
    vector<char> was(n);
    forn(v0,n){
      if(was[v0])
        continue;
      group g(sz(xs));
      bool ok=true;
      function<void(int,int)> dfs;
      dfs = [&](int v,int s){
        if(was[v]){
          if(was[v]-1!=s)
            ok=false;
          return;
        }
        was[v]=1+s;
        g.l[s]=max(g.l[s],R[v].X);
        g.r[s]=min(g.r[s],R[v].Y);
        g.id.pb(mp(v,s));
        for(int p:gr[v])
          dfs(p,1-s);
      };
      dfs(v0,0);
      if(!ok)
        return mp(mp(-1,-1),"");
      G.pb(g);
      //cerr<<"G "<<g.l[0]<<' '<<g.r[0]<<' '<<g.l[1]<<' '<<g.r[1]<<endl;
    }
  }

  struct event{
    int x;
    int a,b,s;
    
    bool operator<(const event& e)const{
      return x<e.x;
    }
  };

  vector<event> evs;
  for(group& g:G){
    vector<int> p={g.l[0],g.l[1],g.r[0],g.r[1]};
    sort(all(p));
    p.erase(unique(all(p)),p.end());
    assert(sz(p)>1);
    forn(i,sz(p)-1){
      int l=inf,r=-inf;
      if(p[i]>=g.l[0] && p[i]<g.r[0])
        l=min(l,g.l[1]),r=max(r,g.r[1]);
      if(p[i]>=g.l[1] && p[i]<g.r[1])
        l=min(l,g.l[0]),r=max(r,g.r[0]);
      if(l==inf)
        continue;
      evs.pb({p[i  ],l,r,+1});
      evs.pb({p[i+1],l,r,-1});
      //cerr<<"ev "<<p[i  ]<<' '<<l<<' '<<r<<" +1"<<endl;
      //cerr<<"ev "<<p[i+1]<<' '<<l<<' '<<r<<" -1"<<endl;
    }
  }
  forv(i,xs)
    evs.pb({i,0,0,0});

  //forv(i,xs)cerr<<xs[i]<<' ';cerr<<endl;

  sort(all(evs));
  segtree T(sz(xs));
  forv(q,evs){
    event e=evs[q];
    //cerr<<e.s<<' '<<e.a<<' '<<e.b<<' '<<endl;
    if(e.s)
      T.add(e.a,e.b,e.s,0,sz(xs),0);
    if(q+1==sz(evs) || evs[q+1].x!=evs[q].x){
      int l=lower_bound(all(xs),tt-xs[e.x])-xs.begin();
      int r=upper_bound(all(xs),TT-xs[e.x])-xs.begin();
      //cerr<<"? "<<l<<' '<<r<<endl;
      T.add(l,r,+1,0,sz(xs),0);
      int tv=T.T[0];
      //cerr<<"tv: "<<tv<<endl;
      if(T.T[0]==sz(G)+1){
        int n1=e.x;
        int n2=T.find(0,sz(xs),0);
        //cerr<<l<<' '<<r<<' '<<n1<<' '<<n2<<' '<<xs[n1]<<' '<<xs[n2]<<' '<<sz(xs)<<endl;
        assert(xs[n1]+xs[n2]>=tt && xs[n1]+xs[n2]<=TT);
        string res(n,'?');
        for(group& g:G){
          int s;
          if     (g.l[0]<=n1 && g.r[0]>n1 && g.l[1]<=n2 && g.r[1]>n2)
            s=0;
          else if(g.l[1]<=n1 && g.r[1]>n1 && g.l[0]<=n2 && g.r[0]>n2)
            s=1;
          else
            assert(false);
          for(auto& p:g.id){
            res[p.X]='1'+(p.Y!=s);
          }
        }
        return mp(mp(xs[n1],xs[n2]),res);
      }
      T.add(l,r,-1,0,sz(xs),0);
    }
  }

  return mp(mp(-1,-1),"");
}

pair<pii,string> brute(int tt,int TT,vector<pii> R,vector<pii> E){
  int n=sz(R);
  forn(m,1<<n){
    int l[2]={0,0},r[2]={inf+1,inf+1};
    forn(i,n){
      int t=(m>>i)&1;
      l[t]=max(l[t],R[i].X);
      r[t]=min(r[t],R[i].Y-1);
    }
    bool ok=true;
    for(pii e:E){
      ok&=((m>>e.X)%2!=(m>>e.Y)%2);
    }
    if(!ok)
      continue;
    if(l[0]<=r[0] && l[1]<=r[1] && l[0]+l[1]<=TT && r[0]+r[1]>=tt){
      //cerr<<m<<' '<<l[0]<<' '<<r[0]<<' '<<l[1]<<' '<<r[1]<<endl;
      int n1=max(l[0],tt-r[1]);
      int n2=max(l[1],tt-n1);
      assert(n1 <= r[0] && n2 <= r[1] && n1+n2<=TT);
      string res(n,'1');
      forn(i,n){
        if(m&(1<<i))
          res[i]='2';
      }
      return mp(mp(n1,n2),res);
    }
  }
  return mp(mp(-1,-1),"");
}

void stress(){
  for(int n=1;n<10;++n){
    for(int m=0;m<10;++m){
      for(int lim: {10,inf}){
        forn(q,10000){
          int tt=rand()%lim+1;
          int TT=rand()%lim+1;
          if(TT<tt)
            swap(tt,TT);
          vector<pii> R(n);
          forn(i,n){
            R[i]=mp(rand()%(lim+1),rand()%(lim+1));
            if(R[i].Y<R[i].X)
              swap(R[i].X,R[i].Y);
            ++R[i].Y;
          }
          vector<pii> E(m);
          forn(i,m){
            E[i]=mp(rand()%n,rand()%n);
          }

          {
            ofstream sout("in.txt");
            sout<<tt<<' '<<TT<<'\n'<<n<<' '<<m<<'\n';
            forn(i,n){
              sout<<R[i].X<<' '<<R[i].Y-1<<'\n';
            }
            forn(i,m){
              sout<<E[i].X+1<<' '<<E[i].Y+1<<'\n';
            }
          }

          auto b=brute(tt,TT,R,E);
          auto r=solve(tt,TT,R,E);
          if((r.X.X==-1)!=(b.X.X==-1)){
            cerr<<"failed "<<n<<' '<<m<<' '<<lim<<' '<<q<<":"<<endl;
            cerr<<b.X.X<<' '<<b.X.Y<<' '<<b.Y<<endl;
            cerr<<r.X.X<<' '<<r.X.Y<<' '<<r.Y<<endl;
            cout<<tt<<' '<<TT<<'\n'<<n<<' '<<m<<'\n';
            forn(i,n){
              cout<<R[i].X<<' '<<R[i].Y-1<<'\n';
            }
            forn(i,m){
              cout<<E[i].X+1<<' '<<E[i].Y+1<<'\n';
            }
            return;
          }
        }
      }
    }
  }
  cerr<<"passed"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);

//  stress();return 0;

  int tt,TT;
  cin>>tt>>TT;
  int n,m;
  cin>>n>>m;
  vector<pii> R(n);
  forn(i,n){
    cin>>R[i].X>>R[i].Y;
    ++R[i].Y;
  }
  vector<pii> E(m);
  forn(i,m){
    cin>>E[i].X>>E[i].Y;
    --E[i].X;
    --E[i].Y;
  }
  auto r=solve(tt,TT,R,E);
//  auto r=brute(tt,TT,R,E);
  if(r.X.X==-1){
    cout<<"IMPOSSIBLE";
  }else{
    cout<<"POSSIBLE\n"<<r.X.X<<' '<<r.X.Y<<'\n'<<r.Y<<endl;
  }

  return 0;
}