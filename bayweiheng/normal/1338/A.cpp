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
    	cin>>n;
    	int a[n];
    	rep(i,n) cin>>a[i];
    	if(n==1) cout<<0<<endl;
    	else {
    		int ans=0;
    		int mindiff=0;
    		int m=a[0];
    		for(int i=1;i<n;++i) {
    			mindiff=min(mindiff,a[i]-m);
    			m=max(a[i],m);
    		}
    		mindiff=-mindiff;
    		ll cur=0;
    		while(cur<mindiff) {
    			cur+=(1LL<<ans);
    			++ans;
    		}
    		cout<<ans<<endl;
    	}
    }


}