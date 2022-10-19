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

const int N=1<<17, mod=1e9+7, INF=1e9+5;
int tab[N+N], lazy[N+N];
void prop(int v){
	if(v>=N || !lazy[v])return;
	int l=v+v, r=l+1;
	tab[r]+=lazy[v];
	tab[l]+=lazy[v];
	lazy[l]+=lazy[v];
	lazy[r]+=lazy[v];
	lazy[v]=0;
}
void add(int v, int L, int R, int l,int r, int c){
	if(l==L && r==R){
		tab[v]+=c;
		lazy[v]+=c;
		return;
	}
	prop(v);
	int M=(L+R)>>1;
	if(l<=M)add(2*v, L, M, l, min(r, M), c);
	if(r>M)add(2*v+1, M+1, R, max(l, M+1), r, c);
	tab[v]=min(tab[2*v], tab[2*v+1]);
	return;
}
int main(){
	BOOST;
	int tt=1;
	cin>>tt;
	while(tt--){
		int n, m;
		cin>>n>>m;
		vi V(n);
		for(int i=0; i<n; i++)cin>>V[i];
		vector<ld> sr(m);
		vector<vi> V2(m);
		for(int i=0; i<m; i++){
			int k;
			cin>>k;
			for(int j=0; j<k; j++){
				int x;
				cin>>x;
				V2[i].pb(x);
				sr[i]+=x;
			}
			sr[i]/=k;
		}
		sor(V);
		V.pb(INF);
		for(int i=0; i<n; i++){
			add(1, 0, N-1, 0, i, 1);
		}
		for(int i=0; i<m; i++){
			add(1, 0, N-1, 0, lower_bound(all(V), int(ceil(sr[i])+1e-6))-V.begin(), -1);
		}
		for(int i=0; i<m; i++){
			for(int j:V2[i]){
				add(1, 0, N-1, 0, lower_bound(all(V), int(ceil(sr[i])+1e-6))-V.begin(), 1);
				sr[i]*=V2[i].size();
				sr[i]-=j;
				sr[i]=round(sr[i]);
				sr[i]/=(V2[i].size()-1);
				add(1, 0, N-1, 0, lower_bound(all(V), int(ceil(sr[i])+1e-6))-V.begin(), -1);
				if(tab[1]>=0)cout<<"1";
				else cout<<"0";
				add(1, 0, N-1, 0, lower_bound(all(V), int(ceil(sr[i])+1e-6))-V.begin(), 1);
				sr[i]*=V2[i].size()-1;
				sr[i]+=j;
				sr[i]=round(sr[i]);
				sr[i]/=(V2[i].size());
				add(1, 0, N-1, 0, lower_bound(all(V), int(ceil(sr[i])+1e-6))-V.begin(), -1);		
			}
		}
		cout<<"\n";
		for(int i=0; i<n; i++){
			add(1, 0, N-1, 0, i, -1);
		}
		for(int i=0; i<m; i++){
			add(1, 0, N-1, 0, lower_bound(all(V), int(ceil(sr[i])+1e-6))-V.begin(), 1);
		}
	}
}