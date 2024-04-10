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
	cin>>tt;
	while(tt--){
		int n, k;
		cin>>n>>k;
		vi V(n);
		for(int &i:V)cin>>i;
		vi V2=V;
		sor(V2);
		int x=0, d=1e9;
		for(int i=0; i<n-(n-k+1)/2-k+1; i++){
			//cout<<".";
			if(V2[i+(n-k+1)/2+k-1]-V2[i]<d){
				x=V2[i];
				d=V2[i+(n-k+1)/2+k-1]-V2[i];
			}
		}
		int y=x+d;
		cout<<x<<" "<<y<<"\n";
		int wsk=0, s=0, prv=0;
		for(int i=0; i<n; i++){
			if(V[i]>=x && V[i]<=y)s++;
			else{
				s--;
			}
			if(s>wsk && s<k){
				cout<<prv+1<<" "<<i+1<<"\n";
				wsk++;
				prv=i+1;
			}
		}
		cout<<prv+1<<" "<<n<<"\n";
	}
}