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
int cnt[26];
int main()
{
	int n;si(n);
	int odd=0,g=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d ",cnt+i);
		odd+=cnt[i]&1;
		g=__gcd(g,cnt[i]);
	}
	if(odd>1)
	{
		dout(0);
		for(int i=0;i<n;i++)
			for(int j=0;j<cnt[i];j++)
				printf("%c",'a'+i);
		printf("\n");
	}
	else if(odd==1)
	{
		dout(g);
		string s;
		for(int i=0;i<n;i++)
			for(int j=0;j<cnt[i]/(2*g);j++)
				s+=char('a'+i);
		for(int i=0;i<n;i++)
			if(cnt[i]&1)
			{
				string t = s;reverse(ALL(t));
				s+=char('a'+i) + t;
			}
		for(int i=0;i<g;i++)
			cout<<s;
		cout<<"\n";
	}
	else 
	{
		dout(g);
		string s;
		for(int i=0;i<n;i++)
			for(int j=0;j<cnt[i]/g;j++)
				s+=char('a'+i);
		string t=s;reverse(ALL(t));
		for(int i=0;i<g;i++)
			if(i&1)cout<<t;
			else cout<<s;
		cout<<"\n";
	}
	return 0;
}