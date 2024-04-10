#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;

int dp[maxn], a[maxn], fen[maxn];
int n;

void add(int idx, int x){
	idx ++;
	for (; idx <= n+1; idx += idx & -idx)
		fen[idx] = max(fen[idx],x);
}

int get(int idx){
	idx ++;
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret = max(ret,fen[idx]);
	return ret;
}

void solve(){
	cin >> n;
	stack<int> Qu;
	Qu.push(0);
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = get(a[i])+1;
		add(a[i], dp[i]);
		while (!Qu.empty() and a[Qu.top()] <= a[i]){
			add(a[Qu.top()], dp[Qu.top()]+1);
			Qu.pop();
		}
		Qu.push(i);
	}
	cout << *max_element(dp+1,dp+n+1) << '\n';
	for (int i = 1; i <= n+1; i++)
		fen[i] = 0;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	while (tc --){
		solve();
	}
}