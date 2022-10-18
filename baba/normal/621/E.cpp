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
const int MOD = int(1e9)+7;
int A[10];
int n,b,k,x;
vector<LL> F(100,0),T(100,0);
LL power2(LL a,LL p,LL mod)
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
vector<LL> get(vector<LL> A,LL alen,vector<LL> B,LL blen)
{
	vector<LL> ret(100,0);
//	trace(alen,blen);
	for(int i=0;i<SZ(A);i++)
		for(int j=0;j<SZ(B);j++)
		{
			if(i>=x || j>=x)
				continue;
			int idx = ((i * power2(10,blen,x))%x + j )%x;
//			if(A[i]&&B[j])trace(i,j,idx,A[i],B[j]);
			ret[idx] += A[i]*B[j];
			ret[idx] %= MOD;
		}
	return ret;
}
vector<LL> power(vector<LL> a,LL p)
{
	vector<LL> ret(100,0);
	ret[0]=1;LL rlen=0,alen=1;
//	trace(p,bitset<5>(p));
	while(p)
	{
		if(p&1){ret = get(ret,rlen,a,alen);rlen+=alen;}
//		trace("alen","alen");
		a = get(a,alen,a,alen);
		alen+=alen;
		p/=2;
	}
	return ret;
}
int main()
{
	si(n);si(b);si(k);si(x);
	for(int i=0;i<n;i++)
	{
		int x;si(x);
		A[x]++;
	}
	for(int i=1;i<10;i++)
		F[i%x]+=A[i];
	lldout(power(F,b)[k]);
	return 0;
}