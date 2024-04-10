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

const int N=3e5+5, K=18, mod=1e9+7, INF=1e9+5;
vector<pair<int, int> > E[N], E2[N], E3[N];
vii edg;
int ori[2*N], used[2*N];
int d[N], d2[N];
int vis[N];
int wei[N], dob[N];
vector<int> dep[2*N];
void go(int v){
    /*while(sz(E[v])){
            pii x=E[v].back();
            E[v].pop_back();
            if(used[x.nd/2]) continue;
            used[x.nd/2]=1;
            if(edg[x.nd/2].st==v)ori[x.nd/2]=1;
            go(x.st);
        }
    }*/
    //cout<<v<<endl;
    vector<int> V, e;
    while(true){
    	V.pb(v);
    	vis[v]=1;
    	while(sz(E[v]) && used[E[v].back().nd]){
    		E[v].pp();
    	}
    	if(!sz(E[v]))break;
    	pii ed=E[v].back();
    	e.pb(ed.nd);
    	if(edg[ed.nd].st==v)ori[ed.nd]=1;
    	used[ed.nd]=1;
    	E[v].pp();
    	v=ed.st;
    	if(vis[v]){
    		while(V.back()!=v){
    			vis[V.back()]=0;
    			e.pp();
    			V.pp();
    		}
    		vis[v]=1;
    		V.pp();
    		e.pp();
    	}
    }
    	for(int i:V)vis[i]=0;
    if(V.size()>1){
    	/*cout<<"a ";
    	for(int i:V)cout<<i<<" ";
    		cout<<"\n";*/
    	d[V[0]]^=1;
    	d[V.back()]^=1;
    	dep[edg.size()]=e;
    	E3[V[0]].pb(mp(V.back(), edg.size()));
    	E3[V.back()].pb(mp(V[0], edg.size()));
    	edg.pb(mp(V[0], V.back()));
    }
}
void go2(int v){
	//cout<<v<<"2"<<endl;
    vector<int> V, e;
    while(true){
    	V.pb(v);
    	vis[v]=1;
    	while(sz(E2[v]) && used[E2[v].back().nd]){
    		E2[v].pp();
    	}
    	if(!sz(E2[v]))break;
    	pii ed=E2[v].back();
    	e.pb(ed.nd);
    	if(edg[ed.nd].st==v)ori[ed.nd]=1;
    	used[ed.nd]=1;
    	E2[v].pp();
    	v=ed.st;
    	if(vis[v]){
    		while(V.back()!=v){
    			vis[V.back()]=0;
    			e.pp();
    			V.pp();
    		}
    		vis[v]=1;
    		V.pp();
    		e.pp();
    	}
    }
    for(int i:V)vis[i]=0;
    if(V.size()>1){
    	/*cout<<"b ";
    	for(int i:V)cout<<i<<" ";
    		cout<<"\n";*/
    	d2[V[0]]^=1;
    	d2[V.back()]^=1;
    	dep[edg.size()]=e;
    	E3[V[0]].pb(mp(V.back(), edg.size()));
    	E3[V.back()].pb(mp(V[0], edg.size()));
    	edg.pb(mp(V[0], V.back()));
    }
}
void go3(int v){
	while(sz(E3[v])){
            pii x=E3[v].back();
            E3[v].pop_back();
            if(used[x.nd]) continue;
            used[x.nd]=1;
            if(edg[x.nd].st==v)ori[x.nd]=1;
            //cout<<v<<" -> "<<x.st<<"\n";
            go3(x.st);
    }
}
void solve(){
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		if(w==1){
			E[u].pb(mp(v, edg.size()));
			E[v].pb(mp(u, edg.size()));
		}
		else{
			E2[u].pb(mp(v, edg.size()));
			E2[v].pb(mp(u, edg.size()));
		}
		edg.pb(mp(u, v));
		wei[i]=w;
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		if(E[i].size()&1)ans++, dob[i]=1;
		d[i]=(E[i].size()&1);
		d2[i]=(E2[i].size()&1);
	}
	for(int i=1; i<=n; i++){
		if(d[i])go(i);
		if(d2[i])go2(i);
	}
	//cout<<"q";
	for(int i=1; i<=n; i++){
		while(E[i].size())go(i);
		while(E2[i].size())go2(i);
	}
	cout<<ans<<"\n";
	int a=0;
	for(int i=1; i<=n; i++){
		if(E3[i].size()==1){
			if(!a)a=i;
			else{
				E3[a].pb(mp(i, edg.size()));
				E3[i].pb(mp(a, edg.size()));
				edg.pb(mp(a, i));
				a=0;
			}
		}
	}
	for(int i=1; i<=n; i++){
		if(E3[i].size())go3(i);
	}
	/*for(int i=0; i<m; i++){
		cout<<ori[i]+1;
	}
	cout<<"\n";*/
	for(int i=m; i<edg.size();	i++){
		if(ori[i]){
			for(int j:dep[i])ori[j]^=1;
		}
	}
	for(int i=0; i<m; i++){
		cout<<ori[i]+1;
	}
	cout<<"\n";
	vi dp(n+1);
	for(int i=0; i<m; i++){
			dp[edg[i].st]+=wei[i]*(2*ori[i]-1);
			dp[edg[i].nd]-=wei[i]*(2*ori[i]-1);
	}
	for(int i=1; i<=n; i++){
		if(dob[i]){
			//if(1!=abs(dp[i]))cout<<i;
		}
	}
}
int main(){
	BOOST;
	int t=1;
	//cin>>t;
	while(t--)solve();
}