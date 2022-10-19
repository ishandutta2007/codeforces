#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define pp(x) pop_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define sz(x) (int)(x).size()
#define rsz(x) resize(x)

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii > vii;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef string str;

#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int INF=1e9+5, mod=1e9+7;

const int A=26, N=1e6+5, M=1005;
int edg[N][A];//ew. zamienic na mape, gdy problemy z pamiecia
int fail[N];
pii par[N];
vi term[N];//najwiekszy konczacy sie tutaj
int SIZ=1;
void add2(str &s, int k, int *node){
	while(k<sz(s)){
		par[SIZ]=mp(*node, s[k]-'a');
		edg[*node][s[k]-'a']=SIZ;
		*node=SIZ;
		SIZ++;
		k++;
	}
}
void add(str &s, int num){
	int node=0;
	for(int i=0; i<sz(s); i++){
		if(edg[node][s[i]-'a'])node=edg[node][s[i]-'a'];
		else{
			add2(s, i, &node);
			break;
		}
	}
	term[node].pb(num);
}
void calc_fail(){
	vi V(1);
	for(int j=0; j<sz(V) ;j++){
		int v=V[j];
		if(par[v].st){
			fail[v]=fail[par[v].st];
			while(fail[v] && !edg[fail[v]][par[v].nd])fail[v]=fail[fail[v]];
			fail[v]=edg[fail[v]][par[v].nd];
			for(int i:term[fail[v]]){
				term[v].pb(i);
			}
		}
		//deb(v, par[v].st, (char)(par[v].nd+'a'), fail[v], sz(term[v]));
		for(int i=0; i<A; i++)if(edg[v][i])V.pb(edg[v][i]);
	}
}
int Q[N], siz[N];
vi ans[N];
void travel(str &s){
	int node=0;
	for(int i=0; i<sz(s); i++){
		while(node && !edg[node][s[i]-'a'])node=fail[node];
		node=edg[node][s[i]-'a'];
		for(int j:term[node]){
			ans[j].pb(i);
		}
	}
}
int main(){
	BOOST;
	str s;
	cin>>s;
	int q;
	cin>>q;
	for(int i=0; i<q; i++){
		str t;
		cin>>Q[i]>>t;
		add(t, i);
		siz[i]=sz(t);
	}
	calc_fail();
	travel(s);
	for(int i=0; i<q; ++i){
		int res=INF;
		for(int j=0; j<=sz(ans[i])-Q[i]; j++){
			res=min(res, ans[i][j+Q[i]-1]-ans[i][j]);
		}
		if(res!=INF)cout<<res+siz[i]<<"\n";
		else cout<<-1<<"\n";
	}
}