# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 1e3 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}


ll n, C[xn][xn], invi[xn], dp[xn][xn], ans = 1LL;
pii A[xn];
set <ll> st;
vector <ll> Vec;
vector <pii> Seg;
bool flag;

void Solve(int ind, ll t){
	C[ind][0] = 1LL;
	for (ll i = 1LL; i <= n; i ++){
		C[ind][i] = zarb(C[ind][i - 1], zarb(t + i, invi[i]));
	}
}

int main(){
	fast_io;
	
	cin >> n;
	for (int i = n; i >= 1; i --) cin >> A[i].F >> A[i].S;
	for (int i = 1; i <= n; i ++){
		ans = zarb(ans, (A[i].S - A[i].F + 1LL));
		st.insert(A[i].F);
		st.insert(A[i].S);
	}
	for (ll x : st) Vec.push_back(x);
	for (int i = 0; i < Vec.size(); i ++){
		if (i && Vec[i - 1] + 1 <= Vec[i] - 1) Seg.emplace_back(Vec[i - 1] + 1, Vec[i] - 1);
		Seg.emplace_back(Vec[i], Vec[i]);
	}
	for (ll i = 1; i <= n; i ++) invi[i] = power(i, md - 2);
	for (int i = 0; i < Seg.size(); i ++)
		Solve(i, Seg[i].S - Seg[i].F);
	ans = power(ans, md - 2);
	for (ll i = 0; i <= n; i ++){
		for (ll j = 0; j < Seg.size(); j ++){
			if (i == 0){
				dp[i][j] = 1LL;
				continue;
			}
			if (j == 0){
				flag = true;
				for (int k = 1; k <= i; k ++) if (A[k].F > Seg[0].F || A[k].S < Seg[0].S) flag = false;
				if (flag) dp[i][j] = C[j][i];
				continue;
			}
			for (ll k = 0; k <= i; k ++){
				if (k && (A[i - k + 1].F > Seg[j].F || A[i - k + 1].S < Seg[j].F)) break;
				dp[i][j] = jaam(dp[i][j], zarb(C[j][k], dp[i - k][j - 1]));
			}
		}
	}
	cout << zarb(dp[n][Seg.size() - 1], ans) << endl;
	
	return 0;
}

/*
50
4 66
6 49
8 32
0 73
0 46
10 58
0 58
9 46
0 33
1 24
5 76
6 19
7 92
0 56
5 27
7 31
3 56
11 66
3 51
6 53
4 29
9 27
10 94
7 66
5 32
9 51
6 97
3 33
8 44
10 73
4 96
8 52
10 100
3 81
9 94
2 76
11 83
10 72
6 56
3 81
0 96
8 32
9 88
6 26
0 99
6 53
10 24
11 56
10 72
9 51
*/