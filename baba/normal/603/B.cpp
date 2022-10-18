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
const LL MOD = LL(1e9)+7;
LL power(LL a,LL p,LL mod)
{
	LL ret=1;
	while(p)
	{
		if(p&1)ret=ret*a%mod;
		a=a*a%mod;
		p/=2;
	}
	return ret;
}
int main()
{
	int p,k;
	si(p);si(k);
	if(k==0)return (lldout(power(p,p-1,MOD)),0);
	else if(k==1)return (lldout(power(p,p,MOD)),0);
	LL m=1;
	while(power(k,m,p)!=1)
		m++;
	lldout(power(p,(p-1)/m,MOD));
	return 0;
}