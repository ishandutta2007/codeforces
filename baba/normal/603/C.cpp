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

const int N = int(1e5)+10;
int G[N],A[N];
map<int,int> F;
int n,k;
int get(int x)
{
	if(x==1)return 1;
	if(x==0)return 0;
	if(F.count(x))return F[x];
	int &ret = F[x];
	if(x&1)
	{
		if(k&1)ret = (x<=3?1:0);
		else ret = (get(x-1)==0?1:0);
	}
	else 
	{
		if(k&1)
		{
			int y1 = get(x-1),y2=get(x/2);
			ret = (y1!=y2?(3 - y1-y2):(1-y1));
		}
		else ret = (x==2?2:1);
	}
	return ret;
}
/*int get(int x)
{
	if(x==1)return 1;
	if(x==0)return 0;
	if(F.count(x))return F[x];
	int &ret = F[x];
	if(x&1)ret = (get(x-1)==0?1:0);
	else 
	{
		if(k&1)
		{
			int y1 = get(x-1),y2=get(x/2);
			ret = (y1!=y2?(3 - y1-y2):(1-y1));
		}
		else ret = 1;
	}
	return ret;
}*/
int main()
{
	si(n);si(k);
	for(int i=0;i<n;i++)
		si(A[i]);
	for(int i=0;i<n;i++)
		G[i]=get(A[i]);
	int ans=0;
	for(int i=0;i<n;i++)
		ans^=G[i];
	if(ans)puts("Kevin");
	else puts("Nicky");
	return 0;
}