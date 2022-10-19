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

const int N=2e5+5, mod=1e9+7;
const ll INF=1e14;
int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<int> pts(n);
		vector<pii> seg(m), seg2;
		for(int &i:pts)cin>>i;
		sor(pts);
		for(pii &i:seg)cin>>i.st>>i.nd, i.nd=-i.nd;
		sor(seg);
		int wsk=0;
		for(pii i:seg){
			i.nd=-i.nd;
			while(seg2.size() && seg2.back().nd>=i.nd)seg2.pp();
			while(wsk<n && pts[wsk]<i.st)wsk++;
			if(wsk==n || pts[wsk]>i.nd)seg2.push_back(i);
		}
		seg=seg2;
		seg2.clear();
		m=seg.size();
		vector<pair<ll, int> > V;
		for(int i:pts)V.pb(mp(i, 0));
		for(pii i:seg)V.pb(mp(i.st, -1)), V.pb(mp(i.nd, 1));
		vector<ll> pocz(m), kon(m);
		for(int i=0; i<m; i++)pocz[i]=seg[i].st, kon[i]=seg[i].nd;
		seg.clear();
		sor(V);
		vector<ll> dp(V.size(), 2*INF);
		ll A=2*INF, B=2*INF;//A-punkt koncem, B-Li koncem
		ll ans=2*INF;
		ll akt=0;
		ll lst=-2*INF, lstA=2*INF;
		vector<ll> co(m);
		ll upd=2*INF;
		for(int i=0; i<dp.size(); i++){
			if(V[i].nd==0){
				B=min(B, akt-V[i].st);
				B=min(B, upd+V[i].st);
				akt=min(akt, A+V[i].st);
				dp[i]=akt;
				lst=V[i].st;
				lstA=A;
			}
			if(V[i].nd==-1){
				dp[i]=min(B+V[i].st, lstA+2*V[i].st-lst);
				int s=lower_bound(all(pocz), V[i].st)-pocz.begin();
				assert(s<m);
				co[s]=akt;
				akt=dp[i];
			}
			if(V[i].nd==1){
				if(V[i].st<pts.back()){
					assert(lower_bound(all(kon), V[i].st)-kon.begin() < m);
					upd=min(upd, co[lower_bound(all(kon), V[i].st)-kon.begin()]-2*V[i].st);
					A=min(A, co[lower_bound(all(kon), V[i].st)-kon.begin()]-V[i].st);
				}
			}
			//if(V[i].st>=pocz.back())ans=min(ans, dp[i]);
		}
		cout<<akt<<"\n";
	}
}