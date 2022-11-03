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

//INSERT ABOVE HERE
const int MAX = 2020;
using BS = bitset<MAX>;
BS diff(BS a,BS b){return a&~b;};
int first(BS a){return a._Find_first();};
BS range(int l,int r){return (~BS()>>(MAX-(r-l)))<<l;}

BS bs[MAX];

signed main(){
  int n,m,q;
  cin>>n>>m>>q;

  bs[n+1]=~BS();

  using P = pair<int, int>;
  set<P> sp;
  vector<int> cnt(n+2);
  for(int i=0;i<=n+1;i++){
    cnt[i]=bs[i].count();
    sp.emplace(cnt[i],i);
  }

  set<int> ok;
  auto check=
    [&](int p,int q){
      if(ok.count(p)) ok.erase(p);
      if(diff(bs[p],bs[q]).any()) ok.emplace(p);
    };

  for(int i=0;i<q;i++){
    {
      int a,l,r;
      cin>>a>>l>>r;
      r++;
      // erase
      {
        auto it=sp.find(P(cnt[a],a));
        auto pr=it,nx=it;
        pr--;nx++;
        {
          int p=pr->second;
          int q=nx->second;
          check(p,q);
        }
        if(ok.count(a)) ok.erase(a);
      }

      sp.erase(P(cnt[a],a));
      bs[a]^=range(l,r);
      cnt[a]=bs[a].count();
      sp.emplace(cnt[a],a);

      //insert
      {
        auto it=sp.find(P(cnt[a],a));
        auto pr=it,nx=it;
        pr--;nx++;
        {
          int p=pr->second;
          int q=it->second;
          check(p,q);
        }
        {
          int p=it->second;
          int q=nx->second;
          check(p,q);
        }
      }
    }

    if(ok.empty()){
      cout<<-1<<"\n";
      continue;
    }

    {
      int p=*ok.begin();
      int q=sp.upper_bound(P(cnt[p],p))->second;
      int s=first(diff(bs[p],bs[q]));
      int t=first(diff(bs[q],bs[p]));
      if(p>q) swap(p,q);
      if(s>t) swap(s,t);
      cout<<p<<" "<<s<<" "<<q<<" "<<t<<"\n";
    }
  }
  cout<<flush;
  return 0;
}