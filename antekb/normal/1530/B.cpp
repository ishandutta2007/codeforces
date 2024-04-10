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

const int N=2e5+5, INF=1e9+5, mod=1e9+7;

int main(){
	//BOOST;
	int t;
	cin>>t;
	while(t--){
		int w, h;
		cin>>h>>w;
		vector<vector<int>> V(h, vi(w));
		for(int i=0; i<h; i+=2)V[i][0]=1;
		for(int j=0; j<w; j+=2)V[0][j]=1;
		for(int j=w-1; j>1; j-=2)V[h-1][j]=1;
		for(int i=h-1; i>1; i-=2)V[i][w-1]=1;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cout<<V[i][j];
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}