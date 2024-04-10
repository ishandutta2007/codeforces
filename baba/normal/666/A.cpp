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
const int N = int(1e4)+10;
set<string> S;
bool dp[2][N];
int main()
{
	fast_io;cout.tie(NULL);S.clear();
	string s;cin>>s;
	int n = SZ(s);s = s + "   ";
	dp[0][n]=dp[1][n]=true;
	for(int i=n-2;i>4;i--){
		dp[0][i] |= dp[1][i+2];
		dp[1][i] |= dp[0][i+3];
		if(!dp[0][i] && (i+2==n || i+4 <= n)){
			dp[0][i] |= (dp[0][i+2] && s.substr(i,2)!=s.substr(i+2,2));	
		}
		if(!dp[1][i] && (i+3 == n || i+6 <=n)){
			dp[1][i] |= (dp[1][i+3] && s.substr(i,3)!=s.substr(i+3,3));
		}
		if(dp[0][i])S.insert(s.substr(i,2));
		if(dp[1][i])S.insert(s.substr(i,3));
		//trace(i,dp[0][i],dp[1][i],s.substr(i,2),s.substr(i,3));
	}
	cout<<SZ(S)<<"\n";
	for(auto s:S)
		cout<<s<<"\n";
	return 0;
}