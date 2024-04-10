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

#define pb push_back
#define ctz __builtin_ctz
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl

struct fw {
	vll a;
	int n;
	fw(int n):a(n+1,0),n(n) {}
	void update(int i,int val) {
		while(i<=n) {
			a[i]+=val;
			i+=i&(-i);
		}
	}
	ll query(int i) {
		ll ans=0;
		while(i) {
			ans+=a[i];
			i-=i&(-i);
		}
		return ans;
	}
	ll query(int i,int j) {
		return query(j)-query(i-1);
	}
};

typedef pair<ll,int> lli;
typedef vector<lli> vlli;
const int mod = 1e9+7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  ll cur;
  cin>>n;
  vlli v;
  v.reserve(n);
  for(int i=1;i<=n;++i) {
  	cin>>cur;
  	v.pb(lli(cur,i));
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  fw sol(n), sol2(n);
  for(int i=0;i<n;++i) {
  	int pos = v[i].second;
  	ll val = v[i].first;
  	ll left = pos, right = n-pos+1;
  	ll cnt = (left*right) % mod;
  	cnt += (sol.query(1, pos) * right) % mod;
  	cnt += (sol2.query(pos, n) * left) % mod;
  	//db3(pos, val, cnt);
  	cnt %= mod;
  	ans += cnt * val;
  	ans %= mod;
  	sol.update(pos,pos);
  	sol2.update(pos,n-pos+1);
  }
  cout<<ans<<endl;

}