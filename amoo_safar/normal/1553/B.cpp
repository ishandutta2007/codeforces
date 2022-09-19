// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int Main(){
	str s;
	str t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for(int st = 0; st < n; st++){
		if(t[0] != s[st]) continue;
		for(int r = 0; r <= m - 1; r++){
			if(st + r >= n) continue;
			int lf = m - (r + 1);
			if(st + r - lf < 0) continue;
			int p = 1;
			int p2 = st;
			int fl = 0;
			for(int i = 0; i < r; i++){
				p2 ++;
				if(t[p] != s[p2]) fl = 1;
				p ++;
			}
			for(int i = 0; i < lf; i++){
				p2 --;
				if(t[p] != s[p2]) fl = 1;
				p ++;
			}
			if(fl == 0) return cout << "YES\n", 0;
		}
	}
	cout << "NO\n";
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}