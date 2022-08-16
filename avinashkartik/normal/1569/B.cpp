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

const int   N     =  5e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n;
char ans[55][55];
string s;

void solve() {
	cin >> n >> s;
	int ct = count(all(s), '2');
	if (ct == 1 || ct == 2) {
		deb1("NO")
		return;
	}
	deb1("YES")
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = '=';
			if (i == j) ans[i][j] = 'X';
		}
	}
	int f = -1, l = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') continue;
		if (f == -1) f = i;
		l = i;
		for (int j = i + 1; j < n; j++) {
			if (s[j] == '1') continue;
			ans[i][j] = '+';
			ans[j][i] = '-';
		}
	}
	if (f != -1) ans[f][l] = '-', ans[l][f] = '+';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j];
		}
		newl;
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