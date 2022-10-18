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
#define right rightt
const int N = int(1e6)+10;
II A[N],null={-1,-1};
int B[N],dsu[N],sz[N],n,m,C[N],vis[N],want,ans;
int idx(II x)
{
	if(x==null)return n*m;
	return x.F*m+x.S;
}
II get(int i)
{
	return {i/m,i%m};
}
II up(II x)
{
	if(x.F==0)return null;
	return {x.F-1,x.S};
}
II down(II x)
{
	if(x.F==n-1)return null;
	return {x.F+1,x.S};
}
II left(II x)
{
	if(x.S==0)return null;
	return {x.F,x.S-1};
}
II right(II x)
{
	if(x.S==m-1)return null;
	return {x.F,x.S+1};
}
int Find(int x)
{
	if(x==dsu[x])return x;
	return dsu[x]=Find(dsu[x]);
}
void dfs(int i,int j)
{
	if(i<0 || i>=n)return;
	if(j<0 || j>=m)return;
	int x = idx({i,j});
	if(!want || B[x] < B[ans] || Find(x)!=Find(ans))return;
	if(vis[x])return;
	vis[x]=1;
	B[x]=B[ans],want--;
	dfs(i+1,j);dfs(i-1,j);dfs(i,j-1);dfs(i,j+1);
}
int main()
{
	LL k;
	si(n);si(m);sll(k);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			si(B[idx({i,j})]);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int x = idx({i,j});
			A[x]={B[x],x};
		}
	sort(A,A+n*m);
	reverse(A,A+n*m);
	for(int i=0;i<=n*m;i++)
		dsu[i]=-1,sz[i]=0;
	for(int i=0,j=0;i<n*m;)
	{
		set<int> done;
		do{
			int pos = A[i].S;
			dsu[pos]=pos;sz[pos]=1;
			//check the four cases
			//up
			VI X,good;
			int x = idx(up(get(pos)));
			if(dsu[x]!=-1)
			{
				x = Find(x);
				X.PB(x);
				if(!done.count(x))
				{
					sz[pos]+=sz[x];
					done.insert(x);
					good.PB(1);
				}
				else
					good.PB(0);
			}
			//down
			x = idx(down(get(pos)));	
			if(dsu[x]!=-1)
			{
				x = Find(x);
				X.PB(x);
				if(!done.count(x))
				{
					sz[pos]+=sz[x];
					done.insert(x);
					good.PB(1);
				}
				else
					good.PB(0);
			}
			//left
			x = idx(left(get(pos)));	
			if(dsu[x]!=-1)
			{
				x = Find(x);
				X.PB(x);
				if(!done.count(x))
				{
					sz[pos]+=sz[x];
					done.insert(x);
					good.PB(1);
				}
				else
					good.PB(0);
			}
			//right
			x = idx(right(get(pos)));	
			if(dsu[x]!=-1)
			{
				x = Find(x);
				X.PB(x);
				if(!done.count(x))
				{
					sz[pos]+=sz[x];
					done.insert(x);
					good.PB(1);
				}
				else
					good.PB(0);
			}
			//done :)
			for(int i=0;i<SZ(X);i++)
				if(good[i])
					dsu[X[i]]=pos;
			i++;
			done.clear();good.clear();X.clear();
		}while(i<n*m && A[i].F == A[i-1].F);
		while(j<i)
		{
			int pos = A[j].S;
			C[pos]=sz[Find(pos)];
			j++;
		}
	}
	bool ok = false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x = idx({i,j});
			if(k%B[x]==0 && C[x] >= k/B[x])
			{
				want = k/B[x];ans=x;
				dfs(i,j);
				ok = true;
				break;
			}
		}
		if(ok)break;
	}
	puts(ok?"YES":"NO");
	if(ok)
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				printf("%d%s",vis[idx({i,j})]?B[idx({i,j})]:0,j==m-1?"\n":" ");

	return 0;
}