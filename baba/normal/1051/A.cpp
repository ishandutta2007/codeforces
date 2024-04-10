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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

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
char s[1000];
int l[1000], u[1000], d[1000];
int ll, lu, ld;
void change(int A[], int &len, char c){
  s[A[--len]] = c;
}
int main()
{
  int t;
  si(t);
  while(t--){
    scanf("%s", s);
    ll = lu = ld = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++){
      if(isdigit(s[i])){
        d[ld++] = i;
      }
      if(islower(s[i])){
        l[ll++] = i;
      }
      if(isupper(s[i])){
        u[lu++] = i;
      }
    }
    if(ld == 0){
      if(ll > lu){
        change(l, ll, '0');
      }
      else {
        change(u, lu, '0');
      }
    }
    if(ll == 0){
      if(ld > lu){
        change(d, ld, 'a');
      }
      else {
        change(u, lu, 'a');
      }
    }
    if(lu == 0){
      if(ll > ld){
        change(l, ll, 'A');
      }
      else {
        change(d, ld, 'A');
      }
    }
    printf("%s\n", s);
  }
	return 0;
}