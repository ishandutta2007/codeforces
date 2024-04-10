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
		vi p(n+1);
		for(int i=1; i<=n; i++){
			if(p[i])continue;
			vi V;
			while(V.size()<=1 || V.back()!=V[0]){
				cout<<"? "<<i<<endl;
				int x;
				cin>>x;
				V.pb(x);
			}
			for(int j=1; j<V.size(); j++){
				p[V[j-1]]=V[j];
			}
		}
		cout<<"! ";
		for(int i=1; i<=n; i++){
			cout<<p[i]<<" ";
		}
		cout<<endl;
	}
}