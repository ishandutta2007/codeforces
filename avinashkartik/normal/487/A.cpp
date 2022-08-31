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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int a[3], b[3], c[3];

void solve() {
	for (int i = 0; i < 3; i++) cin >> a[i];
	for (int i = 0; i < 3; i++) cin >> b[i];
	for (int i = 0; i < 3; i++) cin >> c[i];
	int ans = INFi;
	for (int i = a[1]; i <= 1000; i++) {
		for (int j = a[2]; j <= 1000; j++) {
			int damage_rec = max(0, b[1] - j), damage_done = max(0, i - b[2]);
			if (damage_done == 0) continue;
			int moves = (b[0] + damage_done - 1) / damage_done;
			int hp = max(a[0], damage_rec * moves + 1);
			ans = min(ans, (hp - a[0]) * c[0] + (i - a[1]) * c[1] + (j - a[2]) * c[2]);
		}
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}