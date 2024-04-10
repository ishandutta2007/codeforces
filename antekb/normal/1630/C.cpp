#include<bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("trapv")
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

const int N=3e5+5, INF=1e9+5;
//const int mod=998244353;
const int mod=1e9+7;

int main(){
	BOOST;
	int tt=1;
	//cin>>tt;
	while(tt--){
		int n;
		cin>>n;
		vi V(n), lst(n);
		for(int &i:V)cin>>i, i--;
		for(int i=0; i<n; i++)lst[V[i]]=i;
		int R=0, R2=0;
		int L=0;
		int ans=0;
		int czy=0;
		for(int i=0; i<n; i++){
			//if(R>i && lst[V[i]]>R)czy=1;
			R2=max(R2, lst[V[i]]);
			if(R==i)czy++, R=max(R, R2);
			if(R==i){
				if(R>L+1){
					ans+=R-L-czy+1;
					//cout<<L<<" "<<R<<"\n";
				}
				czy=0;
				L=i+1;
				R=i+1;
			}
		}
		cout<<ans<<"\n";
	}
}