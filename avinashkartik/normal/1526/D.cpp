#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(12);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  6e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, mx = 0;
string s, ans;

ll tree[N] = {};

void init() {
	for (int i = 0; i <= n + 5; i++) tree[i] = 0;
}
 
void update(int idx, int val){ 
    idx++;
    while(idx <= n + 5){ 
        tree[idx] += val;
        idx += idx & (-idx); 
    } 
} 
 
ll query(int idx){
    idx++;
    ll sum = 0;
    while(idx > 0){ 
        sum += tree[idx];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

void calc(string s, string t) {
	init();
	vector <int> v[26];
	for (int i = 0; i < n; i++) v[s[i] - 'A'].pb(i);
	ll res = 0;
	for (int i = n - 1; i >= 0; i--) {
		int ind = v[t[i] - 'A'].back() - query(v[t[i] - 'A'].back() + 1);
		res += abs(ind - i);
		update(v[t[i] - 'A'].back() + 1, 1);
		v[t[i] - 'A'].pop_back();
	}
	if (res > mx) {
		mx = res;
		ans = t;
	}
}

void solve() {
	cin >> s;
	n = s.size();
	vector <int> v = {0, 'N' - 'A', 'O' - 'A', 'T' - 'A'};
	mx = 0;
	ans = s;
	do {
		string t = "";
		for (auto it : v) {
			int ct = count(all(s), it + 'A');
			for (int j = 0; j < ct; j++) t += it + 'A';
		}
		calc(s, t);
	} while(next_permutation(all(v)));
	// calc(s, "NNOTA");
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}