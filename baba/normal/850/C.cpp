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

map<int,int> mp;
int f(int mask){
  if(mp.count(mask))return mp[mask];
  if(mask <= 1)return mp[mask] = 0;
  set<int> grundy;
  for(int i=1;i<31;i++){
    int newmask = 0;
    for(int j=1;j<31;j++){
      if(!(mask & (1 << j)))continue;
      if(j < i) newmask |= (1 << j);
      else if(j > i) newmask |= (1 << (j - i));
    }
    if(newmask == mask)continue;
    assert(newmask < mask);
    grundy.insert(f(newmask));
  }
  int val = 0;
  for(auto it : grundy){
    if(it != val)break;
    val++;
  }
  //if(!(mask & 1))trace(mask,bitset<32>(mask),val);
  return mp[mask] = val;
}
map<int,int> cnt;
int main()
{
  //int m = 0;
  //for(int i=0;i<31;i++)
    //m |= (1 << i);
  //trace(m,f(m));
  int n;si(n);
  for(int i=1;i<=n;i++){
    int x;si(x);
    for(int i=2;i * i <= x; ++i){
      int v = 0;
      while(x % i == 0){
        x = x / i;
        v++;
      }
      if(!v)continue;
      cnt[i] |= (1 << v);
    }
    if(x > 1)cnt[x] |= (1 << 1);
  }
  int ans = 0;
  for(auto x : cnt){
    //trace(x.F,bitset<10>(x.S),f(x.S));
    ans ^= f(x.S);
  }
  puts(ans ? "Mojtaba" : "Arpa");
	return 0;
}