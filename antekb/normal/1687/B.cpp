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

const int N=5e5+5, INF=1e9+5, mod=1e9+7;

int main(){
	//BOOST;
	int n, m;
	cin>>n>>m;
	string s(m, '0');
	vii V(m);
	int x;
	for(int i=0; i<m; i++){
		s[i]^=1;
		cout<<"? "<<s<<endl;
		s[i]^=1;
		cin>>x;
		V[i]={x, i};
	}
	sor(V);
	s.resize(0);
	s.resize(m, '1');
	cout<<"? "<<s<<endl;
	cin>>x;
	int akt=0;
	for(int i=m-1; i>0; i--){
		s[V[i].nd]^=1;
		cout<<"? "<<s<<endl;
		int y;
		cin>>y;
		if(y+V[i].st==x){
			akt+=V[i].st;
			s[V[i].nd]^=1;
		}
		else x=y;
	}
	cout<<"! "<<x<<endl;
}