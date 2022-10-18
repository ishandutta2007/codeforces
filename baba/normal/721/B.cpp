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
const int N = 101;
string s[N];
bool cmp(string a,string b){
  return SZ(a) < SZ(b);
}
int main()
{
  int n,k;
  si(n);si(k);
  for(int i=1;i<=n;i++)
    cin>>s[i];
  sort(s+1,s+1+n,cmp);
  string ans;cin>>ans;
  int cnt1 = 0,cnt2 = 0;
  for(int i=1;i<=n;i++)
    if(SZ(s[i]) < SZ(ans))
      cnt1++;
    else if(SZ(s[i]) == SZ(ans))
      cnt2++;
  int best = cnt1 + (cnt1/k)*5 + 1;
  int worst = (cnt1 + cnt2) + ((cnt1+cnt2-1)/k)*5;
  printf("%d %d\n",best,worst);
	return 0;
}