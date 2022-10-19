#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("trapv")
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

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=(1<<16), K=18, mod=998244353;
const ll INF=1e18;
str s[K];
vi E[N];
int ans[N], opt[N];
void dfs(int v){
	ans[v]=1;
	//if(v==288)cout<<"e\n";
	for(int u:E[v]){
		//cout<<"q";
		if(!ans[u])dfs(u);
		if(ans[u]>=ans[v]){
			ans[v]=ans[u]+1;
			opt[v]=u;
		}
	}
	//if(ans[v]>1)cout<<v<<"q\n";
}
void solve(){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>s[i];
	}
	vector<int> gdzie(n);
	bool any=0;
	for(int c='A'; c<='z'; c++){
		for(int i=0; i<(1<<n); i++){
			vi gdzie(n), czy(n);
			int ii=i;
			bool is=1;
			for(int j=0; j<n; j++){
				for(int k=0; k<s[j].size(); k++){
					if(s[j][k]==c){
						if(ii&(1<<j))ii-=(1<<j);
						else{
							czy[j]=1;
							gdzie[j]=k;
							break;
						}
					}
				}
				is&=czy[j];
			}
			if(is){
				any=1;
				//cout<<"b";
				vi cnt('z'-'A'+1, 1-(1<<n)), czy2('z'-'A'+1);
				for(int j=0; j<n;j ++){
					for(int k=0;k<gdzie[j]; k++){
						cnt[s[j][k]-'A']+=(1<<j);
						czy2[s[j][k]-'A']|=(1<<j);
					}
				}
				for(int j=0; j<cnt.size(); j++){
					if(czy2[j]==((1<<n)-1)){
						//cout<<"a "<<cnt[j]<<"\n";
						//cout<<((c-'A')<<n)+i<<" "<<(j<<n)+cnt[j]<<"\n";
						E[((c-'A')<<n)+i].pb((j<<n)+cnt[j]);
					}
				}
			}
		}
	}
	for(int i=0; i<N; i++){
		if(!ans[i])dfs(i);
	}
	int res=0, naj=0;
	for(int i=0; i<N; i++){
		if(ans[i]>res){
			res=ans[i];
			naj=i;
		}
	}
	if(!any){
		cout<<0<<"\n\n";
	}
	else{
		cout<<res<<"\n";
		//return;
		str t;
		while(ans[naj]>1){
			t.pb('A'+(naj>>n));
			naj=opt[naj];
		}
		t.pb('A'+(naj>>n));
		rev(t);
		cout<<t<<"\n";
	}
	for(int i=0; i<N; i++){
		E[i].clear();
		ans[i]=0;
	}
}
int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--)solve();
}