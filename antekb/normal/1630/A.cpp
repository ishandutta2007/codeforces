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
		if(k+1==n){
			if(n==4)cout<<"-1\n";
			else{
				cout<<n-1<<" "<<n/2-1<<"\n";
				cout<<n-2<<" "<<n/2<<"\n";
				cout<<0<<" "<<1<<"\n";
				for(int i=2; i<n/2-1; i++){
					cout<<i<<" "<<n-i-1<<"\n";
				}
			}
		}
		else{
			cout<<0<<" "<<n-1-k<<"\n";
			if(k!=0)cout<<k<<" "<<n-1<<"\n";
			for(int i=1; i<n/2; i++){
				if(i!=k && i+k!=n-1){
					cout<<i<<" "<<n-i-1<<"\n";
				}
			}
		}
	}
}