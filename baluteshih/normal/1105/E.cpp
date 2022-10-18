#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct MaxClique{//0-base
	ll nb[100],n,ans,one=1;
	ll lowbit(ll x){
		if(x&((one<<60)-1)) return __builtin_ffsll(x&((one<<60)-1))-1;
		return __builtin_ffsll(x>>60)+59;
	}
	ll count_bit(ll x){
		return __builtin_popcountll(x>>60)+__builtin_popcountll(x&((one<<60)-1));
	}
	void B(ll r,ll p,ll x,ll cnt,ll res){
		if(cnt+res<ans) return;
		if(p==0&&x==0){
			if(cnt>ans) ans=cnt;
			return;
		}
		ll q=p&(~nb[lowbit(p|x)]);
		while(q){
			ll i=lowbit(q),j=q&-q;
			B(r|j,p&nb[i],x&nb[i],cnt+one,count_bit(p&nb[i]));
			q&=~j,p&=~j,x|=j;
		}
	}
	int solve(){
		ll _set=0;
		ans=0,_set=(one<<n)-1;
		B(0,_set,0,0,n);
		return ans;
	}
	void add_edge(ll _u,ll _v){
		nb[_u]|=(one<<_v),nb[_v]|=(one<<_u);
	}
	void init(ll _n){n=_n;
		for(int i=0;i<n;++i) nb[i]=0;
	}
}mc;

map<string,int> mp;
int t,edge[45][45];

int get_num(string s)
{
	auto p=mp.find(s);
	if(p==mp.end())
	{
		mp[s]=++t;
		return t;
	}
	else
		return p->S; 
}

vector<int> st;

int main()
{jizz
	int n,m,k;
	string s;
	cin >> n >> m;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=m;++j)
			edge[i][j]=1;
	for(int i=1;i<=m;++i)
		edge[i][i]=0;
	for(int i=1;i<=n;++i)
	{
		cin >> k;
		if(k==1)
		{
			for(int i=0;i<st.size();++i)
				for(int j=i+1;j<st.size();++j)
					edge[st[i]][st[j]]=edge[st[j]][st[i]]=0;
			st.clear();
		}
		else
			cin >> s,st.pb(get_num(s));
	}
	for(int i=0;i<st.size();++i)
		for(int j=i+1;j<st.size();++j)
			edge[st[i]][st[j]]=edge[st[j]][st[i]]=0;
	mc.init(m);
	for(int i=1;i<=m;++i)
		for(int j=i+1;j<=m;++j)
			if(edge[i][j])
				mc.add_edge(i-1,j-1);
	cout << mc.solve() << "\n";
}