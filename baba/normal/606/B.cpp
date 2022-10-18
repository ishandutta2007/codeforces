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
int ans[N];
int dx[] = {+1,-1,0,0};
int dy[] = {0,0,+1,-1};
#define y0 sdfkjnsdkjfn
int x,y,x0,y0;
bool ok(int i,int j)
{
	return (i>0 && i<=x && j>0 && j<=y);
}
int dir(char x)
{
	if(x=='R')return 2;
	else if(x=='L')return 3;
	else if(x=='U')return 1;
	else return 0;
}
int vis[600][600];
int main()
{
	si(x);si(y);si(x0);si(y0);
	string s;
	cin>>s;
	ans[0]=1;int sum=1;
	int last=0;vis[x0][y0]=1;
	for(int i=1;i<=SZ(s);i++)
	{
		int j = i-1;
		int idx = dir(s[j]);
		if(ok(x0+dx[idx],y0+dy[idx]))
		{
			x0 = x0+dx[idx];
			y0 = y0+dy[idx];
			if(vis[x0][y0])continue;
			vis[x0][y0]=1;
			ans[i]=1;
			sum++;
			last = i;
		}
	}
	last=SZ(s);
	ans[last]+=(x*y - sum);
	for(int i=0;i<=SZ(s);i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}