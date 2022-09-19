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
const int N = 3e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int p[N];
int mk[N];
int n, m;

bool Check(int k){
	fill(mk, mk + n + 2, 0);
	int res = n;
	for(int i = 1; i <= n; i++){
		if(mk[i]) continue;
		res --;
		int nw = i;
		while(mk[nw] == 0){
			mk[nw] = 1;
			nw = p[nw] + k;
			if(nw > n) nw -= n;
		}
	}
	if(res <= m) return true;
	return false;
}

int Main(){
	cin >> n >> m;
	map<int, int> mp;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		mp[( i - p[i] + n ) % n] ++;
	}
	vector<int> A;
	for(auto x : mp)
		if(x.S >= n - 2 * m)
			if(Check(x.F))
				A.pb(x.F);

	cout << A.size();
	for(int x : A) cout << ' ' << x;
	cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}