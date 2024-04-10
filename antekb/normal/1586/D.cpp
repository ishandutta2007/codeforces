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

const int N=2e5+5, mod=1e9+7, INF=1e9+5;

int main(){
	BOOST;
	int n;
	cin>>n;
	vi ile(n);
	for(int i=1-n; i<=n-1; i++){
		cout<<"? ";
		if(i<=0){
			for(int j=1; j<n; j++)cout<<n<<" ";
			cout<<n+i<<endl;
		}
		else{
			for(int j=1; j<n; j++)cout<<1<<" ";
			cout<<1+i<<endl;	
		}
		int a;
		cin>>a;
		if(a!=0)ile[a-1]=i;
	}
	int t=0;
	for(int i=0; i<n; i++)t=min(t, ile[i]);
	for(int i=0; i<n; i++)ile[i]-=t-1;
	cout<<"! ";
	for(int i=0; i<n; i++)cout<<ile[i]<<" ";
	cout<<endl;
}