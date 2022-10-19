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

const int K=24, N=(1<<K), INF=1e9+5, mod=1e9+7;
int A[N];
int main(){
	BOOST;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		str s;
		cin>>s;
		int a=1<<(s[0]-'a'), b=1<<(s[1]-'a'), c=1<<(s[2]-'a');
		if(a==b)swap(b, c);
		A[a]++;
		if(a!=b){
			A[b]++;
			A[a^b]--;
		}
		if(a!=b && a!=c && b!=c){
			A[c]++;
			A[b^c]--;
			A[c^a]--;
			A[a^b^c]++;
		}
	}
	for(int i=0; i<K; i++)for(int j=0; j<N;j++)if(j&(1<<i))A[j]+=A[j^(1<<i)];
	ll ans=0;
	for(int i=0; i<N; i++){
		ans^=A[i]*1ll*A[i];
	}
	cout<<ans;
}