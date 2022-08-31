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

const ll   N     =  1e5 + 1;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, m, k;
string s[N];

void solve() {
	cin >> n >> m >> k;
	int free = 0;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = '#' + s[i] + '#';
		free += count(all(s[i]), '.');
	}
	s[0] = s[n + 1] = string(m + 2, '#');

	queue <pair<int, int>> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] != '.') continue;
			q.push({i, j});
			break;
		}
		if (q.size()) break;
	}

	vector <int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};

	for (int i = 0; i < free - k; i++) {
		auto &[x, y] = q.front();
		q.pop();
		if (s[x][y] == '.') {
			s[x][y] = 'X';
		} else {
			i--;
			continue;
		}
		for (int no = 0; no < 4; no++) {
			if (s[x + dx[no]][y + dy[no]] != '.') continue;
			q.push({x + dx[no], y + dy[no]});
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'X') s[i][j] = '.';
			else if (s[i][j] == '.') s[i][j] = 'X';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << s[i][j];
		}
		newl;
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