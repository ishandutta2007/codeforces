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

const ll   N     =  505;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int r, p, s, f;
ld dp[102][102][102];

ld mem(int i, int j, int k) {
	if (i + j == 0 || i + k == 0 || j + k == 0) {
		if (f == 0) return (j + k == 0);
		if (f == 1) return (i + k == 0);
		return (i + j == 0);
	}
	if (dp[i][j][k] != -1) return dp[i][j][k];
	dp[i][j][k] = 0;
	if (i && j) {
		ld res = (ld) 2.0 * i * j / ((i + j + k) * (i + j + k - 1));
		dp[i][j][k] += res * mem(i, j - 1, k);
	}
	if (i && k) {
		ld res = (ld) 2.0 * i * k / ((i + j + k) * (i + j + k - 1));
		dp[i][j][k] += res * mem(i - 1, j, k);
	}
	if (j && k) {
		ld res = (ld) 2.0 * j * k / ((i + j + k) * (i + j + k - 1));
		dp[i][j][k] += res * mem(i, j, k - 1);
	}
	ld res = (ld) (i * (i - 1) + j * (j - 1) + k * (k - 1)) / ((i + j + k) * (i + j + k - 1));
	dp[i][j][k] /= (1 - res);
	return dp[i][j][k];
}

void solve() {
	cin >> r >> s >> p;
	for (int rot = 0; rot < 3; rot++) {
		for (int i = 0; i <= r; i++) {
			for (int j = 0; j <= s; j++) {
				for (int k = 0; k <= p; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		f = rot;
		cout << mem(r, s, p) << " ";
	}
	
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}