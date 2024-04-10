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
const int N = int(1e5)+10;
const int SQRT = 400;
int A[N],ans[N];
namespace greedy{
  int vis[N];
  int solve(int n,int k){
    int cnt = 0, ret = 1, prv = 0;
    for(int i=1;i<=n;i++){
      vis[A[i]]++;
      if(vis[A[i]] == 1){
        cnt++;
      }
      if(cnt == k + 1){
        for(int j=i-1;j>=prv;j--)
          vis[A[j]] = 0;
        vis[A[i]] = 1;
        cnt = 1;
        ret++;
        prv = i;
      }
    }
    for(int i=n;i>=prv;i--)vis[A[i]]=0;
    return ret;
  }
}
namespace Big{
  int vis[SQRT][N],sz[SQRT],num[SQRT],len=1;
  bool started = false;
  void init(int n,int k){
    for(int i=1;i<=n;i++){
      vis[len][A[i]]++;
      num[len]++;
      if(vis[len][A[i]] == 1){
        sz[len]++;
      }
      if(sz[len] == k + 1){
        sz[len]--;
        vis[len][A[i]]--;
        num[len]--;
        len++;
        assert(len < SQRT);
        vis[len][A[i]]++;
        sz[len]++;
        num[len]++;
      }
    }
    started = true;
  }
  void update(int n,int k){
    int add = 0;
    for(int i=1,t=1;i<len;i++){
      if(t == i){
        t++;
        add += num[t-1];
      }
      for(int done=0;t <= len;t++){
        int iter = num[t];
        for(int j=1;j<=iter;j++){
          //insert in i
          vis[i][A[add+j]]++;num[i]++;
          if(vis[i][A[add+j]] == 1){
            sz[i]++;
          }
          //delete from i+1
          vis[t][A[add+j]]--;num[t]--;
          if(vis[t][A[add+j]] == 0){
            sz[t]--;
          }
          //check if fucked
          if(sz[i] == k + 1){
            //remove from i
            vis[i][A[add+j]]--;num[i]--;
            if(vis[i][A[add+j]] == 0)sz[i]--;
            //add in i+1
            vis[t][A[add+j]]++;num[t]++;
            if(vis[t][A[add+j]] == 1){
              sz[t]++;
            }
            add += j-1;
            done = 1;
            break;
          }
        }
        if(done){
          break;
        }
        else{
          add +=iter;
        }
      }
      if(t > len){
        len = i;
        break;
      }
    }
  }
  int solve(int n,int k){
    if(!started)init(n,k);
    else update(n,k);
    return len;
  }
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++)
    si(A[i]);
  for(int i=1;i<=min(n,SQRT);i++)
    ans[i] = greedy::solve(n,i);
  for(int i=min(n,SQRT)+1;i<=n;i++)
    ans[i] = Big::solve(n,i);
  for(int i=1;i<=n;i++)printf("%d ",ans[i]);
  puts("");
  return 0;
}