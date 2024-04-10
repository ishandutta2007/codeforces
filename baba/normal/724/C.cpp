//mobius_treap
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

const int N=100005;
int X[N],Y[N];
int curx=0,cury=0;
int dirx=1,diry=1;
vector<int> mp1[2*N];
vector<int> mp2[2*N];
int visf[2*N];
int vis1[2*N];
int vis2[2*N];
int n,m,k;
LL ans=0;
LL fans[N];
int func()
{
	if(dirx*diry==1)
	{
		int tp=curx-cury+N;
		if(vis1[tp]==1)
			return 1;
		vis1[tp]=1;
		for(int i=0;i<SZ(mp1[tp]);i++)
		{
			int id=mp1[tp][i];
			if(visf[id]==0)
			{
				visf[id]=1;
				fans[id]=ans+abs(X[id]-curx);
			}
		}
	}
	else 
	{
		int tp=curx+cury;
		if(vis2[tp]==1)
			return 1;
		vis2[tp]=1;
		for(int i=0;i<SZ(mp2[tp]);i++)
		{
			int id=mp2[tp][i];
			if(visf[id]==0)
			{
				visf[id]=1;
				fans[id]=ans+abs(X[id]-curx);
			}
		}
	}
	int ret=0;
	int x,y;
	if(dirx==1)x=n-curx;
	else x=curx;
	if(diry==1)y=m-cury;
	else y=cury;

	int mn=min(x,y);
	curx=curx+dirx*mn;
	cury=cury+diry*mn;

	if(x==y)
		ret=1;
	else if(x<y)
		dirx=-dirx;
	else
		diry=-diry;
	ans+=mn;
	return ret;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>X[i]>>Y[i];
		mp1[X[i]-Y[i]+N].PB(i);
		mp2[X[i]+Y[i]].PB(i);
	}
	int tp=func();
	while(!tp)
	{
		tp=func();
	}
	for(int i=1;i<=k;i++)
	{
		if(fans[i]==0)
			cout<<"-1\n";
		else
			cout<<fans[i]<<"\n";
	}
	return 0;
}