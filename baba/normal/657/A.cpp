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
int U[N],V[N];
int main()
{
	int n,d,h;
	si(n);si(d);si(h);
	if(h < max(d/2,d-d/2))return (puts("-1"),0);
	int cnode = 2,len = 0;
	if(h==d)
	{
		if(d==1 && n!=2)return (puts("-1"),0);
		for(int i=0;i<h;i++)
		{
			U[len]=cnode;
			V[len]=cnode-1;
			len++;cnode++;
		}
		while(cnode<=n)
		{
			U[len]=cnode;V[len]=2;
			len++;cnode++;
		}
	}
	else
	{
		for(int i=0;i<h;i++)
		{
			U[len]=cnode;
			V[len]=cnode-1;
			len++;cnode++;
		}
		for(int i=0;i<d-h;i++)
		{
			U[len]=cnode;
			V[len]=(i?cnode-1:1);
			len++;cnode++;
		}
		while(cnode<=n)
		{
			U[len]=cnode;V[len]=1;
			len++;cnode++;
		}
	}
	for(int i=0;i<len;i++)
		printf("%d %d\n",U[i],V[i]);
	return 0;
}