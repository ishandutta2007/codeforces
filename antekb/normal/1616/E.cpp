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

const int N=3e5+5, mod=1e9+7, INF=1e9+5;
int tab[N+N];
void add(int l, int r, int c){
	for(l+=N, r+=N; l<r; l>>=1, r>>=1){
		if(l&1)tab[l++]+=c;
		if(r&1)tab[--r]+=c;
	}
}
int quer(int i){
	int ans=0;
	for(i+=N; i; i>>=1){
		ans+=tab[i];
	}
	return ans;
}
int main(){
	BOOST;
	int tt=1;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		str s, t;
		cin>>s>>t;
		vector<vi> V(26);
		for(int i=n-1; i>=0; i--){
			V[s[i]-'a'].pb(i);
		}
		ll ans=1e18;
		ll p=0;
		vi Q;
		for(int i=0; i<n; i++){
			for(int j='a'; j<t[i]; j++)
				if(V[j-'a'].size())
					ans=min(ans, p+V[j-'a'].back()+quer(V[j-'a'].back())-i);
			if(!V[t[i]-'a'].size())break;
			int k=V[t[i]-'a'].back();
			V[t[i]-'a'].pp();
			p+=k+quer(k)-i;
			Q.pb(k);
			add(0, k, 1);
		}
		for(int i:Q)add(0, i, -1);
		if(ans==1e18)cout<<-1<<"\n";
		else cout<<ans<<"\n";
	}
}