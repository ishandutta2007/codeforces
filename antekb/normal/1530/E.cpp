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
void zet(str s, int k){
	for(int i=0; i<s.size(); i++){
		for(int j=0; j<i; j++){
			bool b=1;
			for(int k=0; k<j; k++){
				if(s[k]!=s[i-j+k]){
					b=0;
				}
			}
			if(b && j>k){
				assert(false);
				cout<<s<<"\n";
				return;
			}
		}
	}
}
int main(){
	BOOST;
	int t;
	cin>>t;
	while(t--){
		int n;
		str s;
		cin>>s;
		n=sz(s);
		sor(s);
		if(n==1 || s[0]!=s[1] || s[0]==s.back()){
			cout<<s<<"\n";
			continue;
		}
		bool c=0;
		for(int i=0; i<n; i++){
			if((i==0 || s[i]!=s[i-1]) && (i==n-1 || s[i]!=s[i+1])){
				swap(s[i], s[0]);
				c=1;
				break;
			}
		}
		if(c){
			sort(s.begin()+1, s.end());
			cout<<s<<"\n";
			continue;
		}
		assert(n>2);
		if(s[0]==s[(n+2)/2]){
			for(int i=0; i<n; i++){
				if(s[i]!=s[0]){
					swap(s[i], s[1]);
					bool b=0;
					for(int j=i+1; j<n; j++){
						if(s[j]!=s[1]){
							swap(s[j], s[i+1]);
							b=1;
							break;
						}
					}
					if(!b){
						for(int k=2; k<=i && k+i<=n; k++){
							swap(s[k], s[i+k-1]);
						}
					}
					break;
				}
			}
			//zet(s, 2);
			cout<<s<<"\n";
		}
		else{
			int wsk=2;
			for(int i=1; i<n; i++){
				if(s[i]!=s[0] && wsk<n && s[wsk]==s[0]){
					swap(s[i], s[wsk]);
					wsk+=2;
				}
			}
			//zet(s, 1);
			cout<<s<<"\n";
		}
	}
}