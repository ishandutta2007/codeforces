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

const int N=2e5+5, mod=998244353;//1e9+7, INF=1e9+5;
ll tab[N];
ll solve(int x, int p, vector<int> A, vector<int> B){
	//cout<<x<<" | "<<p<<"\n";
	//for(int i:A)cout<<i<<" ";
	//	cout<<"\n";
	//for(int i:B)cout<<i<<" ";
	//	cout<<"\n";
	if(!(A.size()+B.size()))return 0;
	if(p==1){
		return tab[sz(A)+sz(B)];
	}
	p/=2;
	vi A1, A2, B1, B2;
	for(int i:A){
		if(i&p)A1.pb(i);
		else A2.pb(i);
	}
	for(int i:B){
		if(i&p)B1.pb(i);
		else B2.pb(i);
	}
	if(x&p){ 
		return ((1+solve(x, p, A1, B2))*(1+solve(x, p, A2, B1))-1)%mod;
	}
	else{
		return (solve(x, p, A1, B1)+solve(x, p, A2, B2)+tab[sz(A1)]*1ll*tab[sz(A2)]+tab[sz(B1)]*1ll*tab[sz(B2)])%mod;	
	}
}
ll solve2(int x, int p, vi V){
	//cout<<x<<" || "<<p<<"\n";
	//for(int i:V)cout<<i<<" ";
	//	cout<<"\n";
	if(V.empty())return 0;
	if(p==0)return tab[sz(V)];
	if(x&p){
		vector<int> A, B;
		for(int i:V){
			if(i&p)A.pb(i);
			else B.pb(i);
		}
		return solve(x, p, A, B);
	}
	else{
		vector<int> A, B;
		for(int i:V){
			if(i&p)A.pb(i);
			else B.pb(i);
		}
		return (solve2(x, p/2, A)+solve2(x, p/2, B))%mod;
	}
}
int main(){
	tab[0]=0;
	for(int i=1; i<N; i++){
		tab[i]=(2*tab[i-1]+1)%mod;
	}
	BOOST;
	int n, x;
	cin>>n>>x;
	vi V(n);
	for(int &i:V)cin>>i;
	cout<<solve2(x, 1<<30, V);
}