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

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--) {
    	int n;
    	ll x;
    	cin>>n>>x;
    	ll a[n];
    	ll bank=0;
    	rep(i,n) {
    		cin>>a[i];
    		a[i]-=x;
    	}
    	int ans=0;
    	sort(a,a+n,greater<ll>());
    	rep(i,n) {
    		if(a[i]>=0) {
    			++ans;
    			bank+=a[i];
    		} else {
    			bank+=a[i];
    			if(bank<0) break;
    			++ans;
    		}
    	}
    	cout<<ans<<endl;
    }


}