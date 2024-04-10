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
const int N = int(2e6)+10;
LL ans[N],P[2],pos[2];
const int o = 0, e = 1;
int main()
{
	int n,q;
	si(n);si(q);
	P[o]=0;P[e]=1;
	for(int i=0;i<q;i++){
		int t;si(t);
		if(t==1){
			int x;si(x);
			pos[o]+=x;pos[e]+=x;
			if(x&1)P[o]^=1,P[e]^=1;
		}
		else
		{
			if(P[o])pos[o]--;
			else pos[o]++;
			if(P[e])pos[e]--;
			else pos[e]++;
			P[o]^=1;P[e]^=1;
		}
	}
	for(int i=1;i<=n;i+=2){
		int x = 1 + (i-1 + pos[o] + n*1ll*N)%n;
		ans[x]=i;
	}
	for(int i=2;i<=n;i+=2){
		int x = 1 + (i-1 + pos[e] + n*1ll*N)%n;
		ans[x]=i;
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}