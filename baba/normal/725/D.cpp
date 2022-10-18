//Mobius_Treap
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
const int N = int(3e5)+10;
LL B[N],W[N];
int A[N];
bool cmp(int a,int b){
  if(B[a] != B[b])
   return B[a] > B[b];
  else return a < b;
}
int main()
{
  int n;si(n);
  for(int i=1;i<=n;i++){
    A[i]=i;
    sll(B[i]);sll(W[i]);
  }
  sort(A+1,A+1+n,cmp);
  int ans = -1, j = -1;
  multiset<LL> S;
  LL t = 0;
  for(int i=1;i<=n;i++){
    if(A[i] == 1){
      ans = i;j = i+1;
      t = B[A[i]];
      break;
    }
    S.insert(W[A[i]]-B[A[i]] + 1);
  }
  while(!S.empty() && t >= *S.begin()){
    auto it = *S.begin();
    S.erase(S.begin());
    t -= it;
    while(j <= n && B[A[j]] > t){
      S.insert(W[A[j]]-B[A[j]] + 1);
      j++;
    }
    ans = min(ans,SZ(S)+1);
  }
  dout(ans);
	return 0;
}