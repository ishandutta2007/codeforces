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
    	int nr,ng,nb;
    	cin>>nr>>ng>>nb;
    	vll v,w,x;
    	ll cur;
    	rep(i,nr) {
    		cin>>cur;
    		v.pb(cur);
    	}
    	rep(i,ng) {
    		cin>>cur;
    		w.pb(cur);
    	}
    	rep(i,nb) {
    		cin>>cur;
    		x.pb(cur);
    	}
    	sort(all(v));
    	sort(all(w));
    	sort(all(x));
    	ll ans=3e18+5,a,b,c;
    	rep(i,nr) {
    		c=v[i];
    		auto it=lower_bound(all(w),c); // first g >= me
    		if(it!=w.end()) {
    			a=*it;
    			ll mid=(c+a)/2;
    			auto it2=lower_bound(all(x),mid);
    			if(it2!=x.end()) {
    				b=*it2;
    				ans=min(ans,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
    			}
    			if(it2!=x.begin()) {
    				--it2;
    				b=*it2;
    				ans=min(ans,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
    			}
    		}
    		if(it!=w.begin()) {
    			--it;
    			a=*it;
    			ll mid=(c+a)/2;
    			auto it2=lower_bound(all(x),mid);
    			if(it2!=x.end()) {
    				b=*it2;
    				ans=min(ans,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
    			}
    			if(it2!=x.begin()) {
    				--it2;
    				b=*it2;
    				ans=min(ans,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
    			}
    		}
    		it=lower_bound(all(x),c);
    		if(it!=x.end()) {
    			a=*it;
    			ll mid=(c+a)/2;
    			auto it2=lower_bound(all(w),mid);
    			if(it2!=w.end()) {
    				b=*it2;
    				ans=min(ans,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
    			}
    			if(it2!=w.begin()) {
    				--it2;
    				b=*it2;
    				ans=min(ans,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
    			}
    		}
    		if(it!=x.begin()) {
    			--it;
    			a=*it;
    			ll mid=(c+a)/2;
    			auto it2=lower_bound(all(w),mid);
    			if(it2!=w.end()) {
    				b=*it2;
    				ans=min(ans,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
    			}
    			if(it2!=w.begin()) {
    				--it2;
    				b=*it2;
    				ans=min(ans,(a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c));
    			}
    		}

    	}
    	cout<<ans<<endl;
    }

}