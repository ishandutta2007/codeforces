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
const int N = int(2e5)+10;
const int MX = int(8e5)+10;
struct node{
	node* nxt[26];
	VI cnt[2];
	node(){SET(nxt,0);cnt[0].clear();cnt[1].clear();}
};
node BUFF[MX];
int blen;
node* head;
void add(string& s,int id,int t)
{
	node* p = head;
	for(int i=0;i<SZ(s);i++)
	{
		if(!p->nxt[s[i]-'a'])
			p->nxt[s[i]-'a'] = BUFF + blen++;
		p = p->nxt[s[i]-'a'];
	}
	p->cnt[t].PB(id);
}
int ans=0;
int matching[N];
pair<int,VI> dfs(node* p,int lvl)
{
	VI match[2];
	match[0] = p->cnt[0];
	match[1] = p->cnt[1];
	for(int i=0;i<26;i++)
		if(p->nxt[i])
		{
			pair<int,VI> x = dfs(p->nxt[i],lvl+1);
			match[x.F].insert(match[x.F].end(),ALL(x.S));
		}
	pair<int,VI> ret;ret.F = SZ(match[0])<SZ(match[1])?1:0;
	while(!match[0].empty() && !match[1].empty())
	{
		matching[match[0].back()]=match[1].back();
		match[0].pop_back();
		match[1].pop_back();
		ans += lvl;
	}
	ret.S = match[ret.F];
	return ret;
}
int main()
{
	fast_io;
	int n;cin>>n;
	string s;
	head = BUFF+blen++;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		add(s,i,0);
	}
	for(int i=0;i<n;i++)
	{
		cin>>s;
		add(s,i,1);
	}
	dfs(head,0);
	dout(ans);
	for(int i=0;i<n;i++)
		printf("%d %d\n",i+1,matching[i]+1);
	return 0;
}