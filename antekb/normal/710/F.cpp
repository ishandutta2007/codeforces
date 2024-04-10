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

const int N=3e5+5, K=19, INF=1e9+5, mod=1e9+7, A=26;
int tab[K][N][A], fail[K][N], kon[K][N];
vi term[K][N];
int wsk[K];
vector<str> Vs;
vi czy;
int add2(str &s, int t, int v, int id){
	while(id<sz(s)){
		tab[t][v][s[id]-'a']=wsk[t];
		v=wsk[t]++;
		id++;
	}
	return v;
}
void add(str &s, int t, int nr){
	int v=0;
	for(int i=0; i<sz(s); i++){
		if(tab[t][v][s[i]-'a']!=0)v=tab[t][v][s[i]-'a'];
		else{
			v=add2(s, t, v, i);
			break;
		}
	}
	kon[t][v]=nr;
	term[t][v].pb(nr);
}
void calc_fail(int t){
	vi V;
	V.pb(0);
	for(int i=0; i<sz(V); i++){
		int v=V[i];
		for(int j=0; j<A; j++){
			int u=tab[t][v][j];
			if(u){
				fail[t][u]=fail[t][v];
				V.pb(u);
				if(v){
					while(fail[t][u] && !tab[t][fail[t][u]][j]){
						fail[t][u]=fail[t][fail[t][u]];
					}
					if(tab[t][fail[t][u]][j])fail[t][u]=tab[t][fail[t][u]][j];
				}
				for(int k:term[t][fail[t][u]])term[t][u].pb(k);
				//cout<<v<<" "<<u<<" "<<(char)(j+'a')<<" "<<fail[t][u]<<"\n";
			}
		}
	}
}
void clear(int t, int v){
	fail[t][v]=0;
	kon[t][v]=0;
	term[t][v].clear();
	for(int i=0; i<A; i++){
		if(tab[t][v][i])clear(t, tab[t][v][i]);
		tab[t][v][i]=0;
	}
}
vi sta[K];
//unordered_set<int> S;
void create(int t){
	assert(sz(sta[t])==(1<<t));
	//cout<<t<<"a\n";
	wsk[t]=1;
	for(int i=0; i<sta[t].size(); i++){
		if(czy[sta[t][i]])add(Vs[sta[t][i]], t, sta[t][i]);
	}
	calc_fail(t);
}
void del(int t){
	if(t!=-1){
		clear(t, 0);
		for(auto i:sta[t])sta[t+1].pb(i);
		sta[t].clear();
	}
	if(sz(sta[t+1])>(1<<(t+1)))del(t+1);
	else create(t+1);
}
int traverse(int t, str &s){
	//cout<<t<<" "<<s<<"\n";
	int ans=0;
	int v=0;
	for(int i=0; i<sz(s); i++){
		//cout<<"a";
		while(v && !tab[t][v][s[i]-'a']){
			v=fail[t][v];
		}
		v=tab[t][v][s[i]-'a'];
		for(int k:term[t][v])if(czy[k])ans++;
	}
	return ans;
}
int traverse2(int t, str &s){
	int v=0;
	for(int i=0; i<sz(s); i++){
		if(!tab[t][v][s[i]-'a']){
			return 0;
		}
		v=tab[t][v][s[i]-'a'];
	}
	return v;
}
int main(){
	BOOST;
	int q;
	cin>>q;
	Vs.pb({});
	czy.rsz(q+1);
	for(int i=1; i<=q; i++){
		int t;
		cin>>t;
		if(t==1){
			str s;
			cin>>s;
			Vs.pb(s);
			czy[i]=1;
			sta[0].pb(i);
			del(-1);
		}
		else if(t==2){
			str s;
			cin>>s;
			Vs.pb({});
			for(int i=0; i<K; i++){
				int a=traverse2(i, s);
				if(a && kon[i][a]){
					czy[kon[i][a]]=0;
					kon[i][a]=0;
					break;
				}
			}
		}
		else{
			//cout<<"a";
			str s;
			cin>>s;
			Vs.pb({});
			int ans=0;
			for(int i=0; i<K; i++){
				ans+=traverse(i, s);
			}
			cout<<ans<<endl;
		}
	}
}