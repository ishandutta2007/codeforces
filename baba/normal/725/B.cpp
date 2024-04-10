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

int ar[6];
int main()
{
  ar[0]=3;
  ar[1]=4;
  ar[2]=5;
  ar[3]=2;
  ar[4]=1;
  ar[5]=0;
  string s;
  cin>>s;
  int n=SZ(s);
  char c= s[n-1];
  LL val=0;
  for(int i=0;i<n-1;i++)
  {
    val=val*10;
    val+=(s[i]-'0');
  }
  val--;
  LL nn=val/4;
  LL nm=val%4;
  if(nm>=2)
  {
    nm-=2;
    val-=2;
  }
  LL ans=nn*12;
  ans=ans+val;
  ans+=(nm*6);
  ans+=ar[c-'a'];
  cout<<1+ans<<"\n";
	return 0;
}