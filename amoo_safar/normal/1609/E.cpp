// Dennis - Toney
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
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

struct node {
	int dp[3][3];
	node (){
		memset(dp, 31, sizeof dp);
	}
};

node Merge(node A, node B){
	node res;
	for(int j = 0; j < 3; j++)
		for(int i = 1; i >= 0; i--)
			B.dp[i][j] = min(B.dp[i][j], B.dp[i + 1][j]);
	for(int i = 0; i < 3; i++)
		for(int j = i; j < 3; j++)
			for(int k = i; k <= j; k++)
				res.dp[i][j] = min(res.dp[i][j], A.dp[i][k]+B.dp[k][j]);
	return res;
}
node seg[N << 2];
void Set(int id, int idx, int x, int L, int R){
	if(L + 1 == R){
		seg[id].dp[0][0] = 0;
		seg[id].dp[1][1] = 0;
		seg[id].dp[2][2] = 0;
		seg[id].dp[x][x] = 1;
		return ;
	}
	int mid = (L + R) >> 1;
	if(idx < mid)
		Set(id << 1 ,idx, x, L, mid);
	else
		Set(id << 1|1, idx, x, mid, R);
	seg[id] = Merge(seg[id << 1], seg[id << 1 | 1]);
}
int Main(){
	int n, q;
	cin >> n >> q;
	str s;
	 cin >> s;
	for(int  i =0 ;i < n; i++){
		Set(1, i, s[i] - 'a', 0, n);
	}
	for(int i = 0; i < q; i++){
		int d; char c;
		cin >> d >> c;
		d --;
		Set(1, d, c - 'a', 0, n);
		int ans = n;
		for(int a = 0; a < 9; a++)
			ans = min(ans, seg[1].dp[a/3][a%3]);
		cout << ans << '\n';
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// for(int i = 2; i < N; i++)
	// 	if(pr[i] == 0)
	// 		for(int j = i + i; j < N; j += i)
				// pr[j] = 1;
	int tc = 1;
	// cin >> tc;
	while(tc --) Main();
	return 0;
}
/*
1
7 3
10 2 1 3 1 19 3

*/