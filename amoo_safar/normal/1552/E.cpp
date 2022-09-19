// Doooop !
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
const int N = 1e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int l[N], r[N], mk[N];
int la[N];
int a[N * N];

int Main(){
	int n, k;
	cin >> n >> k;
	int m = n * k;
	for(int i = 0; i < m; i++) cin >> a[i];
	for(int i = 1; i <= n; i += k - 1){
		int lv = i;
		int rv = min(n, i + k - 2);
		cerr << "!! " << lv << ' ' << rv << '\n';
		memset(la, -1, sizeof la);
		for(int j = 0; j < m; j++){
			if(a[j] < lv || a[j] > rv) continue;
			if(mk[a[j]]) continue;
			if(la[a[j]] != -1){
				mk[a[j]] = 1;
				r[a[j]] = j + 1;
				l[a[j]] = la[a[j]] + 1;
				memset(la, -1, sizeof la);
			} else {
				la[a[j]] = j;
			}
		}
	}

	for(int i = 1; i <= n; i++) cout << l[i] << ' ' << r[i] << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}