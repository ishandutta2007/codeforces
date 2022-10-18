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

VI A[2];
int main()
{
	int curr=0;
	int nxt=1;
	int n;si(n);
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		int x;si(x);
		A[curr].PB(x);
	}
	int p = -1;
	int have=0;
	while(SZ(A[curr])>0)
	{
		ans++;
		p++;
		A[nxt].clear();
		if(p&1)
		{
			for(int i=SZ(A[curr])-1;i>=0;i--)
			{
				if(have < A[curr][i])
				{
					A[nxt].PB(A[curr][i]);
				}
				else
					have++;
			}
			reverse(ALL(A[nxt]));
		}
		else
		{

			for(int i=0;i<SZ(A[curr]);i++)
			{
				if(have < A[curr][i])
				{
					A[nxt].PB(A[curr][i]);
				}
				else
					have++;
			}
		}
		swap(curr,nxt);
	}
	dout(ans);
	return 0;
}