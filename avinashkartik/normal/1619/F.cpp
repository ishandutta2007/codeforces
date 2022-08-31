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

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, m, k;

void solve() {
	cin >> n >> m >> k;
	vector <int> ct(n, 0);
	int c = n % m, f = m - n % m;
	for (int round = 1; round <= k; round++) {
		int st = min_element(all(ct)) - ct.begin();
		for (int game = 1; game <= c; game++) {
			cout << n / m + 1 << " ";
			for (int i = 0; i < n / m + 1; i++) {
				cout << st + 1 << " ";
				ct[st]++;
				st = (st + 1) % n;
			}
			newl;
		}
		for (int game = 1; game <= f; game++) {
			cout << n / m << " ";
			for (int i = 0; i < n / m; i++) {
				cout << st + 1 << " ";
				st = (st + 1) % n;
			}
			newl;
		}
	}
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}