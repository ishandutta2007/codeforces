#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef float f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
// suffix automation in O(|S| log(Sigma))
struct SuffixAutomaton {
	vector<map<char, int>> next; // edges[i]  : the labeled edges from node i
	vector<int> link;            // link[i]   : the parent of i
	vector<int> len;          // length[i] : the length of the longest string in the ith class
	vector<int> occur;
	vector<int> fpos;
	vector<vi> gra;
	int last;                    // the index of the equivalence class of the whole string
	SuffixAutomaton(string const &s) {
		next.push_back(map<char, int>());
		link.push_back(-1);
		len.push_back(0);
		fpos.push_back(0);
		last=0;
		for(int i=0;i<s.size();i++) {
			next.push_back(map<char, int>());
			len.push_back(i+1);
			link.push_back(0);
			fpos.push_back(len.back());
			int r=next.size()-1;
			int p=last;
			while(p>=0&&next[p].find(s[i])==next[p].end()) {
				next[p][s[i]]=r;
				p=link[p];
			}
			if(p!=-1) {
				int q=next[p][s[i]];
				if(len[p]+1==len[q]) {
					link[r]=q;
				} else {
					next.push_back(next[q]);
					len.push_back(len[p]+1);
					link.push_back(link[q]);
					fpos.push_back(fpos[q]);
					int qq=next.size()-1;
					link[q]=qq;
					link[r]=qq;
					while(p>=0&&next[p][s[i]]==q) {
						next[p][s[i]]=qq;
						p=link[p];
					}
				}
			}
			last=r;
		}
	}
	void computelinkgraph() {
		gra.resize(sz(next),vi());
		occur.resize(sz(next),0);
		for(int i=1; i<next.size(); i++)
			gra[link[i]].pb(i);
	}
};
string s;
int o[200005],bo[200005];
void dfs(int at, SuffixAutomaton &sa) {
	for(int i:sa.gra[at]) {
		sa.occur[i]+=sa.occur[at];
		dfs(i,sa);
	}
};
void solve() {
	string t;
	int n;
	cin>>t>>n;
	SuffixAutomaton sa(t);
	reverse(all(t));
	SuffixAutomaton sb(t);
	sa.computelinkgraph();
	sb.computelinkgraph();
	for(int i=1; i<=n; i++) {
		cin>>s;
		for(int j=0; j<2; j++) {
			int at=0;
			bool occur=1;
			for(int j=0; j<s.size(); j++) {
				if(sa.next[at].find(s[j])==sa.next[at].end()) {
					occur=0;
					break;
				}
				at=sa.next[at][s[j]];
			}
			if(occur)
				sa.occur[at]++;
			reverse(all(s));
			swap(sa,sb);
		}
	}
	dfs(0,sa);
	dfs(0,sb);
	for(int i=0; i<sa.occur.size(); i++)
		if(sa.len[i]==sa.fpos[i])
			o[sa.fpos[i]]+=sa.occur[i];
	for(int i=0; i<sb.occur.size(); i++)
		if(sb.len[i]==sb.fpos[i])
			bo[t.size()-sb.fpos[i]+1]+=sb.occur[i];
	int ans=0;
	for(int i=0; i<t.size(); i++) {
		ans+=o[i]*bo[i+1];
	}
	cout<<ans<<endl;

}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}