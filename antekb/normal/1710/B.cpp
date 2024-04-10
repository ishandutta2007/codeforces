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

template <typename H, typename T> 
ostream& operator<<(ostream& os, pair<H, T> m){
	return os <<"("<< m.st<<", "<<m.nd<<")";
}
template <typename H> 
ostream& operator<<(ostream& os, vector<H> V){
	os<<"{";
	for(int i=0; i<V.size(); i++){
		if(i)os<<" ";
		os<<V[i];
	}
	os<<"}";
	return os;
}

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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;
int main(){
	BOOST;
	int tt;
	cin>>tt;
	while(tt--){
		int n, m;
		cin>>n>>m;
		vector<pair<pii, int>> V(n);
		vector<int> plus, minus;
		for(int i=0; i<n; i++){
			cin>>V[i].st.st>>V[i].st.nd;
			plus.pb(V[i].st.st-V[i].st.nd);
			minus.pb(V[i].st.st);
			plus.pb(V[i].st.st+V[i].st.nd);
			V[i].nd=i;
		}
		sor(V);
		sor(plus);
		sor(minus);
		rev(plus);
		rev(minus);
		ll A=0, B=0;
		vector<ll> val(n);
		for(int i=0; i<n; i++){
			while(plus.size() && plus.back()<=V[i].st.st){
				A++;
				B-=plus.back();
				plus.pp();
			}
			while(minus.size() && minus.back()<=V[i].st.st){
				A-=2;
				B+=2*minus.back();
				minus.pp();
			}
			val[i]=V[i].st.st*A+B-m;
		}
		//for(ll i:val)cout<<i<<" ";cout<<"\n";
		vl pocz(n), kon(n);
		for(int i=0; i<n; i++){
			if(val[i]>0)pocz[i]=V[i].st.st-val[i];
			else pocz[i]=1e18;
			if(val[i]>0)kon[i]=V[i].st.st+val[i];
			else kon[i]=-1e18;
		}
		vl pref(n+1), suf(n+1);
		pref[0]=1e18;
		suf[n]=-1e18;
		for(int i=1; i<=n; i++)pref[i]=min(pref[i-1], pocz[i-1]);
		for(int j=n-1; j>=0; j--)suf[j]=max(suf[j+1], kon[j]);
		vi ans(n);
		for(int i=0; i<n; i++){
			//deb(pref[i], suf[i], V[i].nd);
			if(pref[i+1]>=V[i].st.st-V[i].st.nd && suf[i]<=V[i].st.st+V[i].st.nd)ans[V[i].nd]=1;
		}
		for(int i:ans)cout<<i;
			cout<<"\n";
	}
}