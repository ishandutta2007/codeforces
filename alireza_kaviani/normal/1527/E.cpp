#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 4e4 + 10;
const ll MAXK = 110;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , res , curl = 0 , curr = -1 , A[MAXN] , dp[2][MAXN];
deque<int> dq[MAXN];

void addR(int i){
	int x = A[i];
	if(SZ(dq[x]))	res += i - dq[x].back();
	dq[x].push_back(i);
}

void addL(int i){
	int x = A[i];
	if(SZ(dq[x]))	res += dq[x].front() - i;
	dq[x].push_front(i);
}

void remR(int i){
	int x = A[i];
	dq[x].pop_back();
	if(SZ(dq[x]))	res -= i - dq[x].back();
}

void remL(int i){
	int x = A[i];
	dq[x].pop_front();
	if(SZ(dq[x]))	res -= dq[x].front() - i;
}

void Move(int l , int r){
	while(curr < r)	addR(++curr);
	while(l < curl)	addL(--curl);
	while(curr > r)	remR(curr--);
	while(curl < l)	remL(curl++);
}

void solve(int l , int r , int optl , int optr){
	if(r < l)	return;
	int mid = l + r >> 1 , ans = MOD , opt = -1;
	for(int i = min(optr , mid) ; i >= optl ; i--){
		Move(i + 1 , mid);
		//cout << i << sep << mid << sep << res + dp[0][i] << endl;
		if(res + dp[0][i] < ans){
			ans = res + dp[0][i]; opt = i;
		}
	}
	dp[1][mid] = ans;
	solve(l , mid - 1 , optl , opt);
	solve(mid + 1 , r , opt , optr);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//fill(prv , prv + MAXN , -1);

	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
	}
	fill(dp[1] + 1 , dp[1] + MAXN , MOD);
	//cout << res << endl;
	for(int i = 1 ; i <= k ; i++){
		for(int j = 0 ; j < MAXN ; j++)	dp[0][j] = dp[1][j];
		solve(0 , n , 0 , n);
		//for(int j = 0 ; j <= n ; j++){
		//	cout << dp[1][j] << sep;
		//}
		//cout << endl;
	}
	cout << dp[1][n] << endl;
		
    return 0;
}
/*

*/