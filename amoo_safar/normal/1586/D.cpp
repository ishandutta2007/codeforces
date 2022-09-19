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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int mk[N], T = 1;
// int ans[N];
int n;
int Ask(int u){
	cout << "? ";
	if(u > 0){
		for(int i = 0; i < n - 1; i++) cout << "1 ";
		cout << u + 1 << endl;
	} else {
		int d = abs(u) + 1;
		for(int i = 0; i < n - 1; i++) cout << d << ' ';
		cout << 1 << endl;
	}
	int res;
	cin >> res;
	return res;
}
int ans[N];
int Main(){
	cin >> n;
	int q;
	for(int i = 1; i < n; i++){
		q = Ask(i);
		if(q)
			ans[q] = i;
		q = Ask(-i);
		if(q)
			ans[q] = -i;
	}
	int mn = *min_element(ans + 1, ans + n + 1);
	cout << "! ";
	for(int i = 1; i <= n; i++) cout << (ans[i] - mn + 1) << ' ';
	cout << endl;

	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();
	return 0;
}