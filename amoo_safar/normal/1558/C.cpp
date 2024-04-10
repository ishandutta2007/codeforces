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

// const ll Mod = 1000000007LL;
const int N = 4e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int n;
int a[N], p[N];

void Set(){
	for(int i = 1; i <= n; i++) p[a[i]] = i;
}
vector<int> mv;
void Do(int u){
	if(u == 1) return ;
	mv.pb(u);
	reverse(a + 1, a + 1 + u);
}
int Main(){
	mv.clear();
	cin >> n;
	int fl = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if((a[i] + i) % 2 == 1) fl = 1;
	}
	if(fl == 1) return cout << "-1\n", 0;

	Set();
	for(int i = 2; i <= n; i += 2){
		int idx = p[i + 1];
		Do(idx); Set();
		Do(p[i] - 1); Set();
	}
	Do(p[1]); Set();

	for(int i = 2; i <= n; i+=2){
		assert(p[i + 1] - 1 == p[i]);
		Do(p[i] - 1);
		Do(p[i] + 1);
		Set();
	}
	Do(n);
	cout << mv.size() << '\n';
	for(auto x : mv) cout << x << ' ';
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	while(tc --) Main();
	return 0;
}