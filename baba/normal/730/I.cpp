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
const int N = int(3e3)+10;
int A[N],B[N],P[N],vis[N],ans[N],maxB[N],temp[N],cans[N];
bool cmp2(int i,int j){
  return B[i] > B[j];
}
bool cmp(int i,int j){
  if(A[i] == A[j])
    return B[i] < B[j];
  return A[i] > A[j];
}
bool cmp3(int i,int j){
  return B[i] - A[i] > B[j] - A[j];
}
int main()
{
  int n,p,s;
  si(n);si(p);si(s);
  for(int i=1;i<=n;i++)si(A[i]);
  for(int i=1;i<=n;i++)si(B[i]);
  for(int i=1;i<=n;i++)P[i] = i,maxB[i] = i;
  sort(P+1,P+1+n,cmp);
  sort(maxB+1,maxB+1+n,cmp2);
  int maxval = 0;
  for(int i=p;i<=p+s;i++){
    int cval = 0;
    int want = p + s - i;
    SET(vis,0);SET(cans,0);
    for(int j=1;j<=i;j++){
      temp[j] = P[j];
      cval += A[P[j]];
      vis[P[j]] = 1;
      cans[P[j]] = +1;
    }
    sort(temp+1,temp+1+i,cmp3);
    for(int j=1;j<=i-p;j++){
      cval += B[temp[j]] - A[temp[j]];
      cans[temp[j]] = -1;
    }
    for(int j=1;j<=n && want;j++)
      if(!vis[maxB[j]]){
        cval += B[maxB[j]];
        want--;
        cans[maxB[j]] = -1;
      }
    if(cval > maxval){
      maxval = cval;
      for(int i=1;i<=n;i++)
        ans[i] = cans[i];
    }
  }
  dout(maxval);
  VI a,b;
  for(int i=1;i<=n;i++)
    if(ans[i] == +1)
      a.PB(i);
    else if(ans[i] == -1)
      b.PB(i);
  assert(SZ(a) == p);
  assert(SZ(b) == s);
  for(auto x : a)
    printf("%d ",x);
  puts("");
  for(auto x : b)
    printf("%d ",x);
  puts("");

	return 0;
}