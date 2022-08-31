#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, k, a[N];

void solve() {
	cin >> n >> k;
	vector <int> ct(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ct[a[i]]++;
	}
	
	int tot = 0, X = 1, Y = n;
	for (int y = 1, x = 1; y <= n; y++) {
		tot += ct[y];
		while (2 * (tot - ct[x]) - n >= k) {
			tot -= ct[x];
			x++;
		}
		if (2 * tot - n >= k && Y - X > y - x) {
			Y = y, X = x;
		}
	}
	deb2(X, Y)
	for (int i = 1, cur = 1, sum = 0, prv = 0; i <= n; i++) {
		if (a[i] >= X && a[i] <= Y) sum++;
		else sum--;
		if (sum == cur) {
			if (cur == k) {
				deb2(prv + 1, n)
				break;
			}
			deb2(prv + 1, i)
			prv = i;
			cur++;
		}
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}