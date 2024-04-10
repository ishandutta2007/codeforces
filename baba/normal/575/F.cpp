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

const int N = 5001;
const int K = 10002;
const LL INF = LL(2e18);
LL dp[2][K];
LL pos[K];
LL lmin[K],rmin[K];
int len;
pair<LL,LL> bulb[N];
LL cost(int i,int j)
{
	LL add;
	if(pos[j] >= bulb[i].F && pos[j]<=bulb[i].S) add=0;
	else if(pos[j]<bulb[i].F) add = bulb[i].F - pos[j];
	else add = pos[j]-bulb[i].S;
	return add;
}
int main()
{
	set<LL> p;
	int n;si(n);
	LL x;sll(x);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %lld",&bulb[i].F,&bulb[i].S);
		p.insert(bulb[i].F);
		p.insert(bulb[i].S);
	}
	pos[len++]=x;
	while(!p.empty())
	{
		pos[len++]=*p.begin();
		p.erase(p.begin());
	}
	sort(pos,pos+len);
	for(int i=0;i<len;i++)
		if(pos[i]==x)
		{
			lmin[i]=-x;
			rmin[i]=+x;
		}
		else
			lmin[i]=rmin[i]=INF;
	/*	for(int i=1;i<len;i++)
		lmin[i]=min(lmin[i-1],lmin[i]);
		for(int i=len-2;i>=0;i--)
		rmin[i]=min(rmin[i+1],rmin[i]);*/
	int curr=0,nxt=1;
	for(int i=0;i<len;i++)
	{
		dp[curr][i] = abs(pos[i]-x) + cost(1,i); 
	}
	for(int i=2;i<=n;i++)
	{
		lmin[0]=dp[curr][0]-pos[0];
		for(int j=1;j<len;j++)
			lmin[j]=min(lmin[j-1],dp[curr][j]-pos[j]);
		rmin[len-1]=dp[curr][len-1]+pos[len-1];
		for(int j=len-2;j>=0;j--)
			rmin[j]=min(rmin[j+1],dp[curr][j]+pos[j]);
		for(int j=0;j<len;j++)
		{
			LL add = cost(i,j);
			dp[nxt][j] = min(lmin[j]+pos[j],rmin[j]-pos[j]) + add;
		}
		swap(nxt,curr);
	}
	LL ans = dp[curr][0];
	for(int i=1;i<len;i++)
		ans = min(ans,dp[curr][i]);
	lldout(ans);
	return 0;
}