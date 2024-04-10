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

const int N = int(4e5) + 10;
int A[N],nxt[N],pos[N],vis[N];
int main()
{
  int n,k;
  si(n);si(k);
  for(int i=1;i<=n;i++){
    nxt[i] = N;
    si(A[i]);
  }
  for(int i=n;i>=1;i--){
    if(pos[A[i]]){
      nxt[i] = pos[A[i]];
    }
    pos[A[i]] = i;
  }
  int ans = 0;
  set<II> S;
  SET(pos,0);
  for(int i=1;i<=n;i++){
    if(vis[A[i]]){
      assert(nxt[pos[A[i]]] == i);
      S.erase(S.find(MP(i,pos[A[i]])));
      S.insert(MP(nxt[i],i));
      pos[A[i]] = i;
      continue;
    }
    if(SZ(S) < k){
      vis[A[i]] = 1;
      ans++;
      S.insert(MP(nxt[i],i));
      pos[A[i]] = i;
      continue;
    }
    auto it = S.end();
    it--;
    int idx = it->S;
    assert(vis[A[idx]]);
    vis[A[idx]]=0;
    S.erase(it);
    S.insert(MP(nxt[i],i));
    vis[A[i]]=1;
    pos[A[i]] = i;
    ans++;
  }
  dout(ans);
	return 0;
}