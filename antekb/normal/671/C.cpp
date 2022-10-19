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

const int N=(1<<18), INF=1e9+5, mod=1e9+7;
int mi[2*N], se[2*N], lazy[2*N];
ll sum[2*N];
int ile[2*N], siz[2*N];
void push(int v){
	if(se[v]>lazy[v] && lazy[v]>mi[v]){
		sum[v]+=ile[v]*1ll*(lazy[v]-mi[v]);
		mi[v]=lazy[v];
	}
}
void prop(int v){
	int l=2*v, r=l+1;
	lazy[l]=max(lazy[l], lazy[v]);
	lazy[r]=max(lazy[r], lazy[v]);
	push(l);
	push(r);
}
void upd(int v){
	int l=2*v, r=l+1;
	sum[v]=sum[l]+sum[r];
	if(mi[l]==mi[r]){
		ile[v]=ile[l]+ile[r];
		mi[v]=mi[l];
		se[v]=min(se[l], se[r]);
	}
	else{
		if(mi[l]>mi[r])swap(l, r);
		mi[v]=mi[l];
		ile[v]=ile[l];
		se[v]=min(se[l], mi[r]);
	}
}
void upd(int v, int L, int R, int l, int r, int val){
	if(r<L || l>R || mi[v]>=val)return;
	if(l==L && r==R && se[v]>val){
		lazy[v]=val;
		push(v);
		return;
	}
	prop(v);
	int M=(L+R)>>1;
	upd(2*v, L, M, l, min(M, r), max(val, lazy[2*v]));
	upd(2*v+1, M+1, R, max(M+1, l), r, max(val, lazy[2*v+1]));
	upd(v);
	return;
}
ll get(int v, int L, int R, int l, int r){
	if(l==L && r==R){
		return sum[v];
	}
	prop(v);
	int M=(L+R)>>1;
	ll ans=0;
	if(l<=M)ans+=get(2*v, L, M, l, min(M, r));
	if(r>M)ans+=get(2*v+1, M+1, R, max(l, M+1), r);
	return ans;
}
vi gdzie[N];
int main(){
	BOOST;
	for(int i=N; i<2*N; i++){
		se[i]=INF;
		ile[i]=1;
	}
	for(int i=N-1; i>0; i--){
		ile[i]=ile[2*i]*2;
		se[i]=INF;
	}
	int n;
	cin>>n;
	vi V(n);
	vector<vi> dziel(n);
	for(int &i:V)cin>>i;
	int t=0;
	for(int i=n-1; i>=0; i--){
		for(int j=1; j*j<=V[i]; j++){
			if(V[i]%j==0){
				dziel[i].pb(j);
				if(j*j!=V[i])dziel[i].pb(V[i]/j);
			}
		}
		for(int j:dziel[i]){
			if(gdzie[j].size())t=max(t, j);
			gdzie[j].pb(i);
		}
		upd(1, 0, N-1, i, i, t);
	}
	for(int i=0; i<N; i++){
		rev(gdzie[i]);
	}
	ll ans=0;
	for(int i=0; i<n; i++){
		ans+=get(1, 0, N-1, i+1, n);
		for(int j:dziel[i]){
			if(i!=gdzie[j][0]){
				upd(1, 0, N-1, i+1, n, j);
			}
			if(gdzie[j].back()>i){
				upd(1, 0, N-1, i+1, gdzie[j].back(), j);
			}
		}
	}
	cout<<ans;
}