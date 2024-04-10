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

const int N=1<<17, mod=1e9+7, INF=1e9+5;

int main(){
	BOOST;
	int tt=1;
	cin>>tt;
	while(tt--){
		int n, a, b, c;
		cin>>n>>a>>b>>c;
		str s;
		cin>>s;
		int p=0, q=0;
		vi V;
		V.pb(0);
		int zap=0;
		for(int i=0; i<n; i++){
			if(s[i]=='0')V.back()++;
			else if(V.back()!=0)V.pb(0);
		}
		zap+=!!V.back();
		V.pp();
		rev(V);
		if(s[0]=='0' && V.size())zap+=!!V.back(), V.pp();
		for(int &i:V)i--;
		sor(V);
		rev(V);
		for(int i=1; i<n; i++){
			if(s[i]==s[i-1]){
				if(s[i]=='1')p++;
				else q++;
			}
			
		}
		//deb(p, q);
		int r=min(p, q);
		p-=r;
		q-=r;
		ll ans=r*1ll*(a+b);
		int cnt=0;
		//for(int i:V)cout<<i<<" ";
		while(V.size() && V.back()<=r){
			r-=V.back();
			cnt++;
			V.pp();
		}
		//cout<<ans<<"\n";
		if(q)ans+=a, q--;
		if(p)ans+=b, p--;
		//cout<<zap<<" "<<
		if(b>c){
			b-=c;
			ans+=(cnt+min(p, zap))*1ll*b;
		}
		cout<<ans<<"\n";
	}
}