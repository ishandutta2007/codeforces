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
const int N = 4e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int a[N], b[N];

int mk[N];
vector<int> G[N];
int d[N];

int n;
set<pll> E;
void Ask(int u){
	cout << "? " << u << endl;
	for(int i = 1; i <= n; i++){
		cin >> d[i];
		if(d[i] == 1)
			E.insert({min(u, i), max(u, i)});
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	Ask(1);
	vector<int> c(2, 0), d2(n+3, 0);
	
	for(int i = 2; i <= n; i++){
		c[d[i] % 2] ++;
		d2[i] = d[i];
	}
	int gd = (c[0] < c[1] ? 0 : 1);
	for(int i = 2; i <= n; i++)
		if(d2[i] % 2 == gd)
			Ask(i);
	cout << "!" << endl;
	for(auto [x, y] : E)
		cout << x << ' ' << y << endl;
	return 0;
}