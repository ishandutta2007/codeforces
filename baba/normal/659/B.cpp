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
vector<pair<int,string>> A[N];
int main()
{
	int n,m;
	fast_io;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string s;int x,y;
		cin>>s>>x>>y;
		A[x].PB({y,s});
	}
	for(int i=1;i<=m;i++)
		A[i].PB({-1,""});
	for(int i=1;i<=m;i++)
		sort(ALL(A[i])),reverse(ALL(A[i]));
	for(int i=1;i<=m;i++)
	{
		if(A[i][1].F == A[i][2].F)cout<<"?\n";
		else cout<<A[i][0].S<<" "<<A[i][1].S<<"\n";
	}

	return 0;
}