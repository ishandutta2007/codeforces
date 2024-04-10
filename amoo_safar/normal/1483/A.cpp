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

int cnt[N];
int Main(){
	int n, m;
	cin >> n >> m;
	fill(cnt, cnt + n + 1, 0);
	vector<vector<int>> V;
	vector<int> A, ans;
	int sz, x;
	for(int i = 0; i < m; i++){
		cin >> sz;
		A.clear();
		for(int j = 0; j < sz; j++){
			cin >> x;
			A.pb(x);
		}
		V.pb(A);
		if(sz == 1) cnt[A[0]] ++;
	}
	for(auto &vec : V){
		// if(vec.size() == 1) continue;
		int mn = vec[0];
		for(auto x : vec) if(cnt[x] < cnt[mn]) mn = x;
		if((int) vec.size() != 1)
			cnt[mn] ++;
		ans.pb(mn);
	}
	int mx = *max_element(cnt + 1, cnt + n + 1);
	if(mx > (m + 1) / 2) cout << "NO\n";
	else {
		cout << "YES\n";
		for(auto y : ans) cout << y << ' ';
		cout << "\n";
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();

	return 0;
}