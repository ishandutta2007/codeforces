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

int A[51][51],ans[51];
int main()
{
	int n;si(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			si(A[i][j]);
	for(int num=1;num<n;num++)
	{
		int r=0;
		for(int i=1;i<=n;i++)
		{
			bool ok=true;
			for(int j=1;j<=n;j++)
				if(i==j)continue;
				else if(A[i][j]!=num)ok=false;
			if(ok)
			{
				r=i;
				break;
			}
		}
		ans[r]=num;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i==j)continue;
				else if(A[i][j]==num && i!=r)A[i][j]++;
	}
	for(int i=1;i<=n;i++)if(!ans[i])ans[i]=n;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}