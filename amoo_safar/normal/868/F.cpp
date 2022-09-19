// har ki ro didi goft mikhad beshe meslemon !
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
const int K = 22;

ll dp[K][N];
int a[N];

int cnt[N];
int pl, pr;
ll val;
void Add(int x){
	val += cnt[x];
	cnt[x] ++;
}
void Rem(int x){
	cnt[x] --;
	val -= cnt[x];
}
void Go(int L, int R){
	while(L < pl) Add(a[-- pl]);
	while(pr < R) Add(a[pr ++]);
	while(pl < L) Rem(a[pl ++]);
	while(R < pr) Rem(a[-- pr]);
}

void Solve(int k, int L, int R, int Lo, int Ro){
	if(L > R) return ;
	int mid = (L + R) / 2;

	Go(Lo, mid);
	int mo = Lo;
	ll mn = dp[k - 1][Lo] + val;
	for(int op = Lo + 1; op < min(mid, Ro + 1); op ++){
		Go(op, mid);
		if(dp[k - 1][op] + val < mn){
			mn = dp[k - 1][op] + val;
			mo = op;
		}
	}
	// cerr << "! " << k << ' ' << mid << mn << '\n';
	dp[k][mid] = mn;
	Solve(k, L, mid - 1, Lo, mo);
	Solve(k, mid + 1, R, mo, Ro);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(dp, 31, sizeof dp);
	for(int i = 0; i <= k; i++) dp[i][0] = 0;
	for(int i = 1; i <= k; i++)
		Solve(i, 1, n, 0, n);

	cout << dp[k][n] << '\n';
	return 0;
}