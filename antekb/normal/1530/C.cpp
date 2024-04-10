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
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vi A(n), B(n);
		for(int &i:A)cin>>i;
		for(int &i:B)cin>>i;
		sor(A);
		sor(B);
		rev(B);
		A.resize(n*2, 100);
		B.resize(n*2, 0);
		vl p1(2*n+1), p2(2*n+1);
		for(int i=1; i<p1.size(); i++){
			p1[i]=p1[i-1]+A[i-1];
			p2[i]=p2[i-1]+B[i-1];
			//cout<<p1[i]<<" "<<p2[i]<<"\n";
		}
		for(int i=n; i<=2*n; i++){
			if(p1[i]-p1[i/4]>=p2[i-i/4]){
				cout<<i-n<<"\n";break;
			}
		}
	}
}