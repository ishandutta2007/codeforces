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
const int LOGMX = log(1e12)+1;
const LL MX = LL(1e12)+10;
LL dp[N],ST[N*LOGMX],A[N];
int L[N*LOGMX],R[N*LOGMX],blen=2;

void up(int x)
{
	ST[x]=max(ST[L[x]],ST[R[x]]);
}
void update(LL pos,LL val,LL l=0,LL r=MX,int x=1)
{
	if(pos<l || pos>=r)return;
	if(l==r-1)return void(ST[x]=val);
	LL m = (l+r)/2;
	if(pos>=m && !R[x])R[x]=blen++;
	if(pos<m && !L[x])L[x]=blen++;
	update(pos,val,l,m,L[x]);
	update(pos,val,m,r,R[x]);
	up(x);
}
LL query(LL L,LL R,LL l=0,LL r=MX,int x=1)
{
	if(l>=L && r<=R)return ST[x];
	if(r<=L || l>=R || !x)return 0;
	LL m = (l+r)/2;
	return max(query(L,R,l,m,::L[x]),query(L,R,m,r,::R[x]));
}
int main()
{
	int n;si(n);
	for(int i=1;i<=n;i++)
	{
		LL r,h;
		sll(r);sll(h);
		A[i]=(r*r*h);
	}
	for(int i=n;i>=1;i--)
	{
		dp[i]=A[i]+query(A[i]+1,MX);
		update(A[i],dp[i]);
	}
	printf("%.7lf\n",acos(-1)*query(0,MX));
	return 0;
}