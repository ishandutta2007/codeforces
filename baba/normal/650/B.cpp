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
const int N = 2*int(5e5)+10;
LL a,b,T,P[N];
int n;
string s;
int solve(string s)
{
	s += s;
	int ans = 0;
	LL prv = 0;
	P[n]=0;
	for(int i=n-1;i>=0;i--)
		P[i] = P[i+1] + a + (s[i]=='w'?b:0) + 1;
	for(int i=n;i<2*n;i++)
	{
		LL curr = prv + (i==n?0:a) + (s[i]=='w'?b:0) + 1;
		if(curr>T)
		{
			prv = curr;
			continue;
		}
		LL left = T - curr;
		int l = i-n+1, r = n-1, L = n;
		LL add = (i - n)*a;
		while(l<=r)
		{
			int m = (l+r)/2;
			if(P[m] + add <= left)
				L = m, r = m-1;
			else
				l = m + 1;
		}
		ans = max(ans,i-L+1);
		prv = curr;
	}
	return ans;
}
int main()
{
	fast_io;
	cin>>n>>a>>b>>T;
	cin>>s;
	int ans = solve(s);
	reverse(++s.begin(),s.end());
	ans = max(ans,solve(s));
	dout(ans);
	return 0;
}