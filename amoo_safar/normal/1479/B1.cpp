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

pll m1[N], m2[N];

void Ins(int i, pll X){
	if(X.S == m1[i].S){
		m1[i] = max(m1[i], X);
	} else if(X.S == m2[i].S) {
		m2[i] = max(m2[i], X);
	} else {
		if(X > m1[i]){
			m2[i] = m1[i];
			m1[i] = X;
		} else m2[i] = max(m2[i], X);
	}
	if(m1[i] < m2[i]) swap(m1[i], m2[i]);
}
int a[N];
int Main(){
	int n;
	cin >> n;
	fill(m1, m1 + N, pll(-Inf, -1));
	fill(m2, m2 + N, pll(-Inf, -2));
	m1[1] = pll(1, 0);

	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 2; i <= n; i++){
		int d = (a[i] != a[i - 1]);
		Ins(i, pll(m1[i - 1].F + d, m1[i - 1].S));
		Ins(i, pll(m2[i - 1].F + d, m2[i - 1].S));
		
		Ins(i, pll(m1[i - 1].F + (m1[i - 1].S != a[i]), a[i - 1]));
		Ins(i, pll(m2[i - 1].F + (m2[i - 1].S != a[i]), a[i - 1]));
	}
	cout << max(m1[n].F, m2[n].F) << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();
	return 0;
}