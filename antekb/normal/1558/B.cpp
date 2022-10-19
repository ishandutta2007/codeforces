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
int dp[N];
bool sito[N];
int main(){
	BOOST;
	int n, m;
	cin>>n>>m;
	/*dp[1]=1;
	int sum=1;
	for(int i=2; i<=n; i++){
		dp[i]=sum;
		int j=2;
		for(j=2; j*j<=i; j++){
			//if(j>=i/j)break;
			dp[i]=(dp[i]+dp[i/j])%m;
		}
		int k=j-1;
		for(j=k; j>0; j--){
			int t=i/j;
			int s=i/(j+1);
			//deb(i, j, k, s ,t );
			if(s<=k)s=k;
			if(s>=t)continue;
			dp[i]=(dp[i]+dp[j]*1ll*(t-s))%m;
		}
		sum+=dp[i];
		sum%=m;
		//cout<<dp[i]<<"\n";
	}*/
	dp[1]=1;
	vector<int> V;
	for(int i=2; i<=n; i++){
		if(sito[i]==0){
			V.push_back(i);
			for(int j=1; j*i<=n; j++){
				sito[j*i]=1;
			}
		}
	}
	ll sum=1;
	for(int i=2; i<=n; i++){
		/*for(int j:V[i]){
			sum+=dp[i/j]-dp[i/j-1];
		}*/
		vector<int> V2, V3;
		int k=i;
		for(int j:V){
			if(j*j>k)break;
			if(k%j==0)V2.push_back(j);
			while(k%j==0)k/=j;
		}
		if(k!=1)V2.push_back(k);
		V3.push_back(1);
		k=i;
		for(int j:V2){
			int t=0;
			while(k%j==0){
				k/=j;
				int u=V3.size();
				for(int l=t; l<u; l++)V3.push_back(V3[l]*j);
				t=u;
			}
		}
		/*for(int j=2; j*j<=i; j++){
			if(i%j==0){
				sum+=dp[i/j]-dp[i/j-1];
				if(j*j!=i)sum+=dp[j]-dp[j-1];
			}
		}
		sum+=dp[1];*/
		for(int j:V3){
			if(j!=1)sum+=dp[i/j]-dp[i/j-1];
		}
		sum%=m;
		dp[i]=sum;
		sum*=2;
	}
	cout<<(dp[n]+m)%m;
}