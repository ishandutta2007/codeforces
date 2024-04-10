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

//#define TRACE

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
const int N=int(2e5)+10;
int A[N];
int B[200][N];
#define div divv
VI div;
VI cnt;
vector<LL> ps;
VI go[200];
int main()
{
	fast_io;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	div.clear();
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			div.PB(i);
		}
	}
	for(int i=1;i<n;i++)
	{
		int x=__gcd(i,n);
		int ii=lower_bound(ALL(div),x)-div.begin();
		go[ii].PB(i);
	}
	LL ans=0;
	for(int i=0;i<SZ(div);i++)
	{
		int x=div[i];
		for(int j=0;j<x;j++)
		{
			int mx=-1;
			for(int k=j;k<n;k+=x)
			{
				mx=max(mx,A[k]);
			}
			for(int k=j;k<n;k+=x)
			{
				if(mx==A[k])
					B[i][k]=1;
			}
		}
		int ct=0;
		for(int j=0;j<n;j++)
		{
			if(B[i][j]==1)
				ct++;
			else
			{
				if(ct>0)
					cnt.PB(ct);
				ct=0;
			}
		}
		if(ct && B[i][0]==1 && SZ(cnt))
				cnt[0]+=ct;
		else if(ct)
			cnt.PB(ct);
		sort(ALL(cnt));
		ps.PB(cnt.back());
		for(int j=SZ(cnt)-2;j>=0;j--)
		{
			ps.PB(ps.back()+cnt[j]);
		}
		reverse(ALL(ps));
		for(int j=0;j<SZ(go[i]);j++)
		{
			int ne=lower_bound(ALL(cnt),go[i][j])-cnt.begin();
			int nen=lower_bound(ALL(cnt),n)-cnt.begin();
			if(ne==SZ(ps))continue;
			LL temp=ps[ne];
			temp-=(SZ(cnt)-ne)*(go[i][j]-1);
			temp+=(SZ(cnt)-nen)*(go[i][j]-1);
			ans+=temp;		
		}
		cnt.clear();
		ps.clear();
	}
	cout<<ans<<"\n";
	return 0;
}