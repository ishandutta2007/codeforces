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

const int K=17, N=(1<<K), mod=1e9+7, INF=1e9+5;
int la[N+N], lc[N+N], mina[N+N], minc[N+N], ans[N+N];
void calc(int v){
	if(v>=N)return;
	int l=v+v, r=l+1;
	ans[v]=min(ans[l], ans[r]);
	ans[v]=min(ans[v], mina[l]+minc[r]);
	mina[v]=min(mina[l], mina[r]);
	minc[v]=min(minc[l], minc[r]);
}
void prop(int v){
	if(v>=N)return;
	int l=v+v, r=l+1;
	la[l]+=la[v];
	la[r]+=la[v];
	mina[l]+=la[v];
	mina[r]+=la[v];
	lc[l]+=lc[v];
	lc[r]+=lc[v];
	minc[l]+=lc[v];
	minc[r]+=lc[v];
	ans[l]+=la[v]+lc[v];
	ans[r]+=la[v]+lc[v];
	la[v]=0;
	lc[v]=0;
}
str s;
int n;
void adda(int v, int L, int R, int l, int r, int c){
	if(L==l && r==R){
		la[v]+=c;
		mina[v]+=c;
		ans[v]+=c;
		/*if(v>=N){
		if(s[v-N]=='a'){
			mina[v]=la[v];
		}
		else{
			mina[v]=INF;
		}
		}*/
		//ans[v]=min(INF, mina[v]+minc[v]);
		return;
	}
	prop(v);
	int M=(L+R)>>1;
	if(M>=l)adda(2*v, L, M, l, min(M, r), c);
	if(M<r)adda(2*v+1, M+1, R, max(M+1, l), r, c);
	calc(v);
	return;
}
void addc(int v, int L, int R, int l, int r, int c){
	if(L==l && r==R){
		lc[v]+=c;
		minc[v]+=c;
		ans[v]+=c;
		/*if(v>=N){
		if(s[v-N-2]=='c'){
			minc[v]=lc[v];
		}
		else{
			minc[v]=INF;
		}
		}*/
		//ans[v]=min(INF, mina[v]+minc[v]);
		return;
	}
	prop(v);
	int M=(L+R)>>1;
	if(M>=l)addc(2*v, L, M, l, min(M, r), c);
	if(M<r)addc(2*v+1, M+1, R, max(M+1, l), r, c);
	calc(v);
	return;
}
int na=0, B=0, nc=0;
void upd(char C, int i, int c){
	if(C=='a'){
		adda(1, 0, N-1, i, n, c);
		na+=c;
	}
	else if(C=='c'){
		addc(1, 0, N-1, 1, i, c);
		nc+=c;
	}
	else{
		B+=c;
		addc(1, 0, N-1, 1, i, -c);
		adda(1, 0, N-1, i, n, -c);
	}
}
void solve(){
	for(int i=0; i<N+N; i++){
		ans[i]=INF;
	}
	int q;
	cin>>n>>q;
	cin>>s;
	//n=s.size();
	s='a'+s;
	s=s+'c';
	for(int i=N+n+1; i<N+N; i++){
		mina[i]=INF;
	}
	for(int i=N+n+2; i<N+N; i++){
		minc[i]=INF;
	}
	minc[N]=INF;
	for(int i=N-1; i>0; --i){
		calc(i);
	}
	
	for(int i=1; i<=n; i++){
		upd(s[i], i, 1);
		//adda(1, 0, N-1, i, i, 0);
		//addc(1, 0, N-1, i, i, 0);	
	}
	//cout<<ans[1]+B<<"\n";
	//return;
	while(q--){
		int t;
		char c;
		cin>>t>>c;
		upd(s[t], t, -1);
		s[t]=c;
		upd(s[t], t, 1);
		//adda(1, 0, N-1, t, t, 0);
		//addc(1, 0, N-1, t, t, 0);
		//cout<<ans[1]+B<<"\n";
		cout<<min({ans[1]+B, na, nc})<<"\n";
		/*for(int i=1; i<N+N; i++){
			deb(i, s[i], ans[i], la[i], mina[i], lc[i], minc[i]);
		}*/
	}
}
int main(){
	BOOST;
	int t=1;
	//cin>>t;
	while(t--)solve();
}