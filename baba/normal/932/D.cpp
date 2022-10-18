//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int N = 4e5 + 10;
const int LOGN = 20;
class myDS{
  public:
    void addNode(int p, int x, int wt){
      if(p != -1)level[x] = level[p] + 1;
      DP[0][x] = p;
      SUM[0][x] = MAX[0][x] = wt;
      for(int i = 1; i < LOGN; ++i){
        DP[i][x] = DP[i - 1][DP[i - 1][x]];
        SUM[i][x] = SUM[i - 1][x];
        MAX[i][x] = MAX[i - 1][x];
        if(DP[i - 1][x] != -1){
          SUM[i][x] += SUM[i - 1][DP[i - 1][x]];
          MAX[i][x] = max(MAX[i][x], MAX[i - 1][DP[i - 1][x]]);
        }
      }
    }
    int goUp(int x, int d){
      REP(i, LOGN)if(d & (1 << i))x = DP[i][x];
      return x;
    }
    LL getMax(int x, int d){
      LL ret = 0;
      REP(i, LOGN)if(d & (1 << i)){
        ret = max(ret, MAX[i][x]);
        x = DP[i][x];
        if(x == -1)break;
      }
      return ret;
    }
    LL getSum(int x, int d){
      LL ret = 0;
      REP(i, LOGN)if(d & (1 << i)){
        ret += SUM[i][x];
        x = DP[i][x];
        if(x == -1)break;
      }
      return ret;
    }
    int getLevel(int x){
      return level[x];
    }
  private:
    int DP[LOGN][N], level[N];
    LL SUM[LOGN][N], MAX[LOGN][N];
} tree[2];
int main()
{
  int q;si(q);
  int last = 0;
  REP(t, 2)tree[t].addNode(-1, 1, 0);
  int cnt = 1;
  while(q--){
    int t;si(t);
    LL p, q;
    sll(p);sll(q);
    if(t == 1){
      int R = last ^ p;
      int W = last ^ q;
      tree[0].addNode(R, ++cnt, W);
      //find it's parent in tree[1]. note that it can be -1.
      int low = 1, high = tree[0].getLevel(R) + 1, ans = -1;
      while(low <= high){
        int mid = (low + high) >> 1;
        LL val = tree[0].getMax(R, mid);
        if(val < W){
          //go up
          low = mid + 1;
        }
        else {
          high = mid - 1;
          ans = mid;
        }
      }
      int par;
      if(ans == -1)par = -1;
      else par = tree[0].goUp(R, ans - 1);
      tree[1].addNode(par, cnt, W);
    }
    else {
      int R = p ^ last;
      LL X = q ^ last;
      int low = 1, high = tree[1].getLevel(R) + 1, ans = -1;
      while(low <= high){
        int mid = (low + high) >> 1;
        LL sum = tree[1].getSum(R, mid);
        if(sum <= X){
          ans = mid;
          low = mid + 1;
        }
        else high = mid - 1;
      }
      if(ans == -1)ans = 0;
      last = ans;
      dout(last);
    }
  }
  return 0;
}