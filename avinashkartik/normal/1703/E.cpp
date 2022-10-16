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
string s[N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	vector <vector <int>> vis(n, vector <int>(n, 0));
	int ans = 0;
	/*
	i, j
	j, n - i - 1
	n - i - 1, n - j - 1
	n - j - 1, i
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 1) continue;
			int ct = 0;
			vis[i][j] = 1;
			vis[j][n - i - 1] = 1;
			vis[n - i - 1][n - j - 1] = 1;
			vis[n - j - 1][i] = 1;
			ct += s[i][j] == '1';
			ct += s[j][n - i - 1] == '1';
			ct += s[n - i - 1][n - j - 1] == '1';
			ct += s[n - j - 1][i] == '1';
			if (i == n - i - 1 && j == n - j - 1) {
				continue;
			} else {
				ans += min(ct, 4 - ct);
			}
		}
	}
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