//TooWeakTooSlow
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
const int N = 1e5 + 10;
int A[26], B[26], n;
string T[N], S[N];
int c;
bool ok(int idx){
  SET(A, 0);SET(B, 0);
  int want = 0;
  REP(i, idx){
    if(T[i] == "."){
      for(auto cc : S[i]){
        int c = cc - 'a';
        B[c] = 1;
      }
    }
    if(T[i] == "!"){
      set<int> SS;
      for(auto cc : S[i]){
        int c = cc - 'a';
        SS.insert(c);
      }
      for(auto i : SS)A[i]++;
      want++;
    }
    if(T[i] == "?"){
      B[S[i][0] - 'a'] = 1;
    }
  }
  REP(i, 26){
    if(c == i){
      assert(!B[i] && A[i] == want);
      continue;
    }
    if(B[i])continue;
    if(A[i] != want)continue;
    return false;
  }
  return true;
}
int main()
{
  fast_io;
  cin >> n;
  REP(i, n)cin >> T[i] >> S[i];
  c = S[n - 1][0] - 'a';n--;
  int low = 1, high = n, ans = -1;
  while(low <= high){
    int mid = (low + high) >> 1;
    if(ok(mid)){
      ans = mid;
      high = mid - 1;
    }
    else low = mid + 1;
  }
  if(ans == -1){
    puts("0");
    return 0;
  }
  int cnt = 0;
  FOR(i, ans, n)if(T[i] == "!" || T[i] == "?")cnt++;
  dout(cnt);


	return 0;
}