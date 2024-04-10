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
#define prev prevv
int W[301],prev[301],L[int(1e4)+10],A[101];
int dp[int(1e4)+10];
VI ans;
int n;
int get(int x)
{
	int ret = x%n;
	if(!ret)ret=n;
	return ret;
}
int main()
{
	si(n);
	int T;si(T);
	if(n==1 && T==1)
	{
		dout(1);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		si(A[i]);
		W[A[i]]++;
	}
	int left = max(0,T-100);
	int mx = 0;
	for(int i=0;i<min(T,100);i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x = A[j];
			int cpos = i*n + j;
			for(int k=x;k>=0;k--)
			{
				if(!prev[k])continue;
				int pos = prev[k];
				if(dp[cpos] < dp[pos] + 1)
				{
					dp[cpos] = dp[pos]+1;
					L[cpos] = pos;
				}
				else if(dp[cpos] == dp[pos]+1 && W[A[get(L[cpos])]] < W[A[get(pos)]])
					L[cpos] = pos;
			}
			if(dp[cpos]>dp[mx])
				mx = cpos;
			prev[x]=cpos;
		}
	}
	while(mx)
	{
		ans.PB(A[get(mx)]);
		mx = L[mx];
	}
	reverse(ALL(ans));
	if(!left)
	{
		dout(SZ(ans));
	}
	else
	{
		int add = SZ(ans);
		mx = 0;
		for(int i=1;i<SZ(ans);i++)
			if(W[ans[i]]>W[ans[mx]])
				mx = i;
		add += W[ans[mx]]*left;
		dout(add);
	}
	return 0;
}