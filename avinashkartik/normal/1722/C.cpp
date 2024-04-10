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

int n;
string a[N], b[N], c[N];

void solve() {
	cin >> n;
	map <string, int> m;
	for (int i = 0; i < n; i++) cin >> a[i], m[a[i]]++;
	for (int i = 0; i < n; i++) cin >> b[i], m[b[i]]++;
	for (int i = 0; i < n; i++) cin >> c[i], m[c[i]]++;
	int A = 0, B = 0, C = 0;
	for (int i = 0; i < n; i++) {
		if (m[a[i]] == 1) A += 3;
		else if (m[a[i]] == 2) A += 1;
	}
	for (int i = 0; i < n; i++) {
		if (m[b[i]] == 1) B += 3;
		else if (m[b[i]] == 2) B += 1;
	}
	for (int i = 0; i < n; i++) {
		if (m[c[i]] == 1) C += 3;
		else if (m[c[i]] == 2) C += 1;
	}
	deb3(A, B, C)
	
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}