#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, gmx = 0;

int q(int i, int j, int k) {
	deb4('?', i, j, k)
	int x; cin >> x;
	gmx = max(gmx, x);
	return x;
}

int calc(int x, int y) {
	int mx = 0, ind = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x || i == y) continue;
		int no = q(x, y, i);
		if (no >= mx) {
			mx = no;
			ind = i;
		}
	}
	return ind;
}

void solve() {
	cin >> n;
	gmx = 0;
	int i = calc(1, 2), j = calc(1, i), k;
	for (int x = 2; x <= n; x++) {
		if (x == i || x == j) continue;
		k = x;
	}
	int x = q(1, i, k), y = q(1, j, k);
	if (x == gmx) deb3('!', 1, i)
	else if (y == gmx) deb3('!', 1, j)
	else deb3('!', i, j)
}

int main() {
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}