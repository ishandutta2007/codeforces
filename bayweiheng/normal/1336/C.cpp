#include<bits/stdc++.h>

using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int,int,int> iii;

#define pb push_back
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);++i)

string s,t;
int n,m;
const int maxn=3005;
const ll mod=998244353;
ll dp[maxn][maxn]; // use 

ll f(int i,int l) {
	if(i==-1) {
		return 1;
	}
	if(dp[i][l]!=-1) return dp[i][l];
	ll ans=0;
	if(i+l>=m || s[i]==t[i+l]) ans+=f(i-1,l); // put R
	if(l>=m || s[i]==t[l]) ans+=f(i-1,l+1); // put L
	//db3(i,l,ans);
	return dp[i][l]=ans%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>t;
    n=s.size();
    m=t.size();
    memset(dp,-1,sizeof(dp));
    ll ans=0;
    for(int i=m-1;i<n;++i) {
    	ans+=f(i,0);
    	ans%=mod;
    	//db2(i,f(i,0));
    }
    cout<<ans<<endl;

}