#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<long long,long long> > vpll;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pair<ll,ll> > > vvpll;

#define PI 3.141592653589793
#define MOD 1000000007

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, ll m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

int trie[2000000][26];
int canwin[2000001];
int canlose[2000001];
int next1=1;

void insert(string s)
{
	ll sz=s.size();
	int v=0;
	for(ll i=0;i<sz;i++)
	{
		ll cur=s[i]-'a';
		if(trie[v][cur]==-1)
		{
			trie[v][cur]=next1++;
		}
		v=trie[v][cur];
	}
}

ll dfs(ll v)
{
	ll store=0;
	for(ll i=0;i<26;i++)
	{
		if(trie[v][i]!=-1)
		{
			if(dfs(trie[v][i])==0)
				store=1;
		}
	}
	canwin[v]=store;
	return store;
}

ll dfs2(ll v)
{
	ll store=0;
	bool check=false;
	for(ll i=0;i<26;i++)
	{
		if(trie[v][i]!=-1)
		{
			check=true;
			if(dfs2(trie[v][i])==0)
				store=1;
		}
	}
	if(!check)
		store=1;
	canlose[v]=store;
	return store;
}

int main()
{
	IOS;
	memset(trie,-1,sizeof(trie));
	ll n,k;
	cin>>n>>k;
	for(ll i=0;i<n;i++)
	{
		string s;
		cin>>s;
		insert(s);
	}
	ll st1=dfs(0);
	ll st2=dfs2(0);
	if(st1&&st2)
	{
		cout<<"First";
	}
	else if(st1)
	{
		if(k%2)
		{
			cout<<"First";
		}
		else
		{
			cout<<"Second";
		}
	}
	else 
	{
		cout<<"Second";
	}
	return 0;
}