#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define pb push_back
#define ctz __builtin_ctz
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

struct ufds {
  vi ranks,p,num;
  ufds(int n):ranks(n,0),p(n),num(n,1) {
    for(int i=0;i<n;++i) {
      p[i]=i;
    }
  }
  int findSet(int i) {
    return p[i]==i ? i : p[i]=findSet(p[i]);
  }
  void unionSet(int i,int j) {
    int x = findSet(i), y=findSet(j);
    if(x==y) return;
    if(ranks[x]<ranks[y]) {
      p[x]=y;
      num[y]+=num[x];
    } else {
      if(ranks[x]==ranks[y]) ++ranks[x];
      p[y]=x;
      num[x]+=num[y];
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,k,a,cur;
  cin>>n>>m;
  ufds sol(n);
  while(m--) {
    cin>>k;
    if(k>0) {
      --k;
      cin>>a;
      --a;
    }
    while(k--) {
      cin>>cur;
      --cur;
      sol.unionSet(a,cur);
    }
  }
  for(int i=0;i<n;++i) {
    printf("%d ",sol.num[sol.findSet(i)]);
  }
  printf("\n");

}