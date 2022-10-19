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

int main(){
	BOOST;
	int tt=1;
	cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		int L, R, c1=INF, c2=INF, C;
		cin>>L>>R>>C;
		c1=c2=C;
		cout<<C<<"\n";
		for(int i=1; i<n; i++){
			int l, r, c;
			cin>>l>>r>>c;
			if(l<L){
				L=l;
				C=2*INF;
				c1=INF;
			}
			if(r>R){
				R=r;
				C=2*INF;
				c2=INF;
			}
			if(l==L)c1=min(c1, c);
			if(r==R)c2=min(c2, c);
			if(l==L && r==R)C=min(C, c);
			cout<<min(c1+c2, C)<<"\n";
		}

	}
}