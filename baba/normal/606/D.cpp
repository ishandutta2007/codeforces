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
pair<II,int> e[N];
II ans[N];
bool cmp(pair<II,int> a,pair<II,int> b)
{
	if(a.F.F!=b.F.F)return a.F.F<b.F.F;
	return a.F.S>b.F.S;
}

int main()
{
	int n,m;
	si(n);si(m);
	for(int i=0;i<m;i++)
		si(e[i].F.F),si(e[i].F.S),e[i].S=i;
	sort(e,e+m,cmp);
	int u=2;
	int uu=2,vv=3;
	for(int i=0;i<m;i++)
	{
		if(e[i].F.S==1)ans[e[i].S] = (MP(1,u++));
		else
		{
			if(uu>=vv)
			{
				vv++;
				uu=2;
			}
			if(vv>=u)
			{
				dout(-1);
				return 0;
			}
			ans[e[i].S] = (MP(uu,vv));
			uu++;
		}
	}
	for(int i=0;i<m;i++)
		printf("%d %d\n",ans[i].F,ans[i].S);
	return 0;
}