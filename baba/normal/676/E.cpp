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
const int N = int(1e5)+10;
int A[N];
int main()
{
  int n;si(n);
  int k;si(k);
  while(getchar()!='\n');
  int cnt = 0;A[0]=int(1e9);
  for(int i=0;i<=n;i++){
    char s[10];
    scanf("%s\n",s);
    if(s[0]=='?')cnt++;
    else A[i] = atoi(s);
  }
  if(k==0){
      if(A[0]==0 || (A[0] == int(1e9) && (n+1 - cnt) % 2 == 1))puts("Yes");
      else puts("No");
      return 0;
    }
  if(cnt){
    puts((n+1-cnt)%2 + cnt%2 == 1 ? "No":"Yes");
    return 0;
  }
  bool ok = false;
  long double ans = 0;  
  for(int i=n;i>=0;i--){
      ans += A[i];
      ans = ans * k;
    }
  long double eps = 1e-5;
  if(fabs(ans) < eps)ok = true;
  if(ok)puts("Yes");
  else puts("No");
	return 0;
}