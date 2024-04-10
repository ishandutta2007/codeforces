#include<bits/stdc++.h>
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

//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N=4e6+5, INF=1e9+5, mod=1e9+7;

int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi V(n), V2;
		for(int &i:V)cin>>i;
		V2=V;
		bool b=0;
		for(int i=0; i<n; i++){
			if(1^ (i&1) ^ (V[i]&1))b=1;
		}
		if(b){
			cout<<"-1\n";
			continue;
		}
		vector<int> ans;
		while(n>1){
			for(int i=0; i<n; i++){
				if(V[i]==n){
					ans.push_back(i+1);
					for(int j=0; j<=i/2; j++){
						swap(V[j], V[i-j]);
					}
				}
			}
			for(int i=0; i<n; i++){
				if(V[i]==n-1){
					ans.push_back(i);
					for(int j=0; j<=i/2; j++){
						swap(V[j], V[i-1-j]);
					}
					//assert(V[1]==n-1);
					ans.push_back(n);
					for(int j=0; j<n/2; j++){
						swap(V[j], V[n-1-j]);
					}
					break;
				}
			}
			
			for(int i=0; i<n; i++){
				if(V[i]==n){
					ans.push_back(i+1);
					for(int j=0; j<=i/2; j++){
						swap(V[j], V[i-j]);
					}
					ans.push_back(n);
					for(int j=0; j<n/2; j++){
						swap(V[j], V[n-1-j]);
					}
					break;
				}
			}
			assert(V[n-1]==n);
			assert(V[n-2]==n-1);
			n-=2;
		}
		vi ans2;
		for(int i:ans){
			if(i>1)ans2.push_back(i);
			if(ans2.size()>=2 && ans2.back()==ans2[ans2.size()-2])ans2.pp(), ans2.pp();
		}
		cout<<ans2.size()<<"\n";
		for(int i:ans2){
			cout<<i<<" ";
		}
		cout<<"\n";
		/*for(int i:ans2){
			for(int j=0; j<=i/2; j++){
				swap(V2[j], V2[i-j-1]);
			}
		}
		for(int i=0; i<V.size(); i++){
			//cout<<V2[i]<<endl;
			assert(V2[i]==i+1);
		}*/
	}
}