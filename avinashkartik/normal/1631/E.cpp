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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N], s[N], e[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!s[a[i]]) s[a[i]] = i;
		e[a[i]] = i;
	}
	
	for (int i = 1; i <= n; i++) {
		if (s[i] == e[i]) s[i] = e[i] = 0;
	}
	
	vector <int> mark(n + 1, 0);
	set <int> cur;
	for (int i = 1, j = 0; i <= n; i++) {
		cur.erase(i);
		if (i != s[a[i]]) {
			if (i < j) mark[i] = 1;
		} else {
			if (e[a[i]] > j) {
				if (cur.size() > 1) {
					mark[s[a[j]]] = 1;
					cur.erase(j);
				}
				cur.insert(e[a[i]]);
				j = e[a[i]];
			} else {
				mark[i] = 1;
			}
		}
	}
	deb1(accumulate(all(mark), 0))
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}