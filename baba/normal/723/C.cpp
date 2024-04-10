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
const int N = int(2e3)+10;
int A[N],cnt[N],ans[N];
VI pos[N];
VI extra;
VII updates;
VI MN;
int main()
{
  int n,m;
  si(n);si(m);
  for(int i=1;i<=n;i++){
    si(A[i]);
    if(A[i] <= m){cnt[A[i]]++;pos[A[i]].PB(i);}
    else extra.PB(i);
  }
  set<II> S;
  int changes = 0;
  for(int i=1;i<=m;i++)
    S.insert({cnt[i],i});
  MN.PB(S.begin()->F);
  while(!extra.empty()){
    auto top = *S.begin();
    S.erase(S.begin());
    top.F = top.F + 1;
    changes++;
    updates.PB({extra.back(),top.S});
    ans[extra.back()] = top.S;
    extra.pop_back();
    S.insert(top);
    MN.PB(S.begin()->F);
  }
  while(1){
    auto top = *S.begin();
    auto last = *S.rbegin();
    if(last.F - top.F <= 1)break;
    S.erase(S.begin());
    S.erase(--S.end());
    top.F = top.F + 1;
    last.F = last.F - 1;
    changes++;
    int p = pos[last.S].back();
    ans[p] = top.S;
    updates.PB({p,top.S});
    pos[last.S].pop_back();
    S.insert(top);
    S.insert(last);
    MN.PB(S.begin()->F);
  }
  int idx = -1;
  //trace(SZ(updates),SZ(MN));
  for(int i=0;i<SZ(updates);i++)
    if(MN[i+1]!=MN[i])
      idx = i;
  SET(ans,0);
  for(int i=0;i<=idx;i++)
    ans[updates[i].F] = updates[i].S;
  for(int i=1;i<=n;i++)
    if(!ans[i])
      ans[i] = A[i];
  printf("%d %d\n",S.begin()->F,idx+1);
  for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);
  puts("");
  
	return 0;
}