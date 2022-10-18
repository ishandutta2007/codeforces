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

//#define TRACE

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
const int N = int(2e5)+10;
vector<int> A;
int S[N],V[N],c,L[N];
LL PS[N];
LL sum(int l,int r){
  return PS[r]-PS[l-1];
}
bool check(int k,int i){
  trace("in check");
  trace(k,i);
  if(k < 0)return false;
  int l = 1,h = i,j = i+1;
  while(l <= h){
    int m = (l+h)/2;
    if(sum(m,i) <= k){j = m; h = m-1;}
    else l = m + 1;
  }
  trace(j,i,sum(j,i));
  k -= sum(j,i);
  trace("out check");
  if(k == 0)return false;
  if(j == 1)return true;
  if(S[j-1] == 0)return false;
  return binary_search(A.begin(),A.begin() + S[j-1],k);
}
int main()
{
  si(c);int n;si(n);
  for(int i=1;i<=n;i++){
    si(V[i]);
  }
  sort(V+1,V+1+n);
  for(int i=1;i<=n;i++)
    PS[i] = PS[i-1] + V[i];
  int val = 1;
  while(val < V[1])A.PB(val++);
  S[1] = SZ(A);
  trace(1,S[1]);
  for(int i=2;i<=n;i++){
    while(val < V[i]){
      if(check(val,i-1))A.PB(val);
      val++;
    }
    S[i] = SZ(A);
    trace(i,S[i]);
  }
  for(int i=0;i<SZ(A);i++)
    trace(i,A[i]);
  int left = c;
  for(int i=n;i>=1;i--){
    trace(i,V[i],left);
    L[i] = left;
    if(V[i] <= left){
      left = left - V[i];
    }
  }
  int i = 0;L[n+1] = c;
  for(int k=1;k<=c;k++){
    i = lower_bound(V+1,V+1+n,k)-V;
    trace(k,i,L[i]);
    i--;if(i<1)continue;
    if(check(L[i]-k,i)){
      dout(k);
      return 0;
    }
  }
  puts("Greed is good");
	return 0;
}