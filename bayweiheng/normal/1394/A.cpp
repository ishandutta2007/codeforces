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

int n,d;

int lef(int big) {
	if(big == 0) return n;
	return n-1-(big-1)*(d+1);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m;
    cin>>n>>d>>m;
    ll a[n];
    vll big,small;
    rep(i,n) {
    	cin>>a[i];
    	if(a[i]>m) {
    		big.pb(a[i]);
    	} else small.pb(a[i]);
    }
    sort(all(big), greater<ll>());
    sort(all(small), greater<ll>());
    vll pre(small.size()+1, 0);
    rep(i, small.size()) {
    	pre[i+1] = pre[i] + small[i];
    }
    ll ans=0;
    vll prebig(big.size()+1, 0);
    rep(i, big.size()) {
    	prebig[i+1] = prebig[i] + big[i];
    }
    rep(i, big.size()+1) {
    	int can = lef(i);
    	//db2(i, can);
    	if(can < 0) break;
    	if(can > small.size()) can = small.size();
    	//db2(prebig[i], pre[can]);
    	ans = max(ans, prebig[i] + pre[can]);
    }
    cout<<ans<<endl;
}