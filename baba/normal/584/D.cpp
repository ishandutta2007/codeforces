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

const int N = int(1e5);
VI prime;
int P[N];
bool isprime(int x)
{
	for(int i=0;i<SZ(prime) && prime[i]*prime[i]<=x;i++)
	{
		if(prime[i]==x)return true;
		else if(x%prime[i]==0)return false;
	}
	return true;
}
int main()
{
	for(int i=2;i*i<N;i++)
		if(!P[i])
			for(int j=i*i;j<N;j+=i)
				P[j]=1;
	for(int i=2;i<N;i++)
		if(!P[i])
			prime.PB(i);
	int n;si(n);
	VI ans;
	if(n<=7)
	{
		if(n==3)ans = {3};
		else if(n==4)ans={2,2};
		else if(n==5)ans={3,2};
		else if(n==6)ans={2,2};
		else if(n==7)ans={2,3,2};
	}
	else
	{
		ans.PB(3);
		n-=3;
		for(int i=n-2;i>=0;i--)
			if(isprime(i) && isprime(n-i))
			{
				ans.PB(i);
				ans.PB(n-i);
				break;
			}
	}
	dout(SZ(ans));
	for(int i=0;i<SZ(ans);i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}