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
    cout.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--) {
    	ll n,l,r;
    	cin>>n>>l>>r;
    	int st=1;
    	ll curl=1,nxl;
    	bool need=0;
    	if(r==n*(n-1)+1) {
    		--r;
    		need=1;
    	}
    	vi ans;
    	ll u,v;
    	for(int i=1;i<=n-1;++i) {
    		if(l>r) break;
    		nxl=curl + 2*(n-i);
    		//if(i<5) db(i);
    		//db(curl);
    		//db3(i,nxl,r);
    		if(nxl>r) {
    			// print the last part
    			u=l-curl;
    			v=r-curl;
    			//db3(u,v,nxl);
    			for(int j=u;j<=v;++j) {
    				if(j&1) {
    					ans.pb(i+1+j/2);
    				} else ans.pb(i);
    			}
    			break;
    		}
    		if(nxl>l) {
    			u=l-curl;
    			v=nxl-curl-1;
    			//db2(u,v);
    			for(int j=u;j<=v;++j) {
    				if(j&1) {
    					ans.pb(i+1+j/2);
    				} else ans.pb(i);
    			}
    			l=nxl;
    		}
    		curl=nxl;
    	}
    	if(need) ans.pb(1);
    	for(int i=0;i<ans.size();++i) cout<<ans[i]<<" \n"[i==(ans.size()-1)];
    }


}