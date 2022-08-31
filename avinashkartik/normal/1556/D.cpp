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

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  4e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, k, a[N];

int A(int i, int j) {
	deb3("and", i, j)
	int x; cin >> x;
	return x;
}

int O(int i, int j) {
	deb3("or", i, j)
	int x; cin >> x;
	return x;
}

void solve() {
	cin >> n >> k;
	int a12 = A(1, 2);
	int a13 = A(1, 3);
	int a23 = A(2, 3);
	int o12 = O(1, 2);
	int o13 = O(1, 3);
	int o123 = o12 & o13;
	int a123 = a12 & a13;
	int x123 = o123 - a123;
	a[1] = x123 ^ a23;
	a[2] = a[1] ^ (o12 - a12);
	a[3] = a[1] ^ (o13 - a13);
	for (int i = 4; i <= n; i++) {
		a[i] = a[1] ^ (O(1, i) - A(1, i));
	}
	sort(a + 1, a + n + 1);
	deb2("finish", a[k])
}

int main() {
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}