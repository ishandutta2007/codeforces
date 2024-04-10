#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
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

int n;

int process(vector <int> &a, vector <int> &b) {
	sort(all(a));
	sort(all(b));
	vector <int> na, nb;
	int ct = 0;
	for (int i = 0, j = 0; i < a.size() || j < b.size();) {
		if (j == b.size()) {
			if (a[i] > 9) na.pb(log10(a[i]) + 1), ct++;
			else na.pb(a[i]);
			i++;
		} else if (i == a.size()) {
			if (b[j] > 9) nb.pb(log10(b[j]) + 1), ct++;
			else nb.pb(b[j]);
			j++;
		} else if (a[i] < b[j]) {
			if (a[i] > 9) na.pb(log10(a[i]) + 1), ct++;
			else na.pb(a[i]);
			i++;
		} else if (a[i] > b[j]) {
			if (b[j] > 9) nb.pb(log10(b[j]) + 1), ct++;
			else nb.pb(b[j]);
			j++;
		} else i++, j++;
	}
	a = na;
	b = nb;
	return ct;
}

void solve() {
	cin >> n;
	vector <int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;
	deb1(process(a, b) + process(a, b) + a.size() + b.size() - count(all(a), 1) - count(all(b), 1))
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}