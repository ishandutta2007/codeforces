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

int a[N];

int Main(){
	int n;
	cin >> n;
	int m = n + n + 5;
	vector<int> cnt(m, 0);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	int ans = 0;
	int fl = 0;
	for(int i = 0; i < m; i++){
		ans += ((cnt[i] > 0) || fl);
		if(fl)
			fl = cnt[i] > 0;
		else
			fl = cnt[i] > 1;
	}
	cout << ans << '\n';

}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while(T --) Main();
	return 0;
}