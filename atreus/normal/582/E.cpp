/**
 *    author:  Atreus
 *    created: 29.01.2019 15:59
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 500 + 10;
const int mod = 1e9 + 7;
int lchild[maxn], rchild[maxn], par[maxn];
char ex[maxn];

void ssum(int &fi, int &se){
	fi = fi + se;
	if (fi >= mod)
		fi -= mod;
}
void sminus(int &fi, int &se){
	fi = fi - se;
	if (fi < 0)
		fi += mod;
}

int dp[maxn][(1 << 16) + 10];

void cal_leaf(int v){
	int base = (1 << 16) - 1;
	bool n = 0;
	if (ex[v] >= 'a' and ex[v] <= 'd'){
		n = 1;
		ex[v] = char(int(ex[v] - 'a') + 'A');
	}
	int mask = 0;
	for (int i = 0; i < 16; i++)
		if (i & (1 << int(ex[v] - 'A')))
			mask += (1 << i);
	if (n == 0)
		dp[v][mask] ++;
	else
		dp[v][mask ^ base] ++;
}

const int maxm = (1 << 16) + 10;
int suml[maxm], sumr[maxm], sum[maxm];

void cal_nonleaf(int v){
	int l = lchild[v], r = rchild[v];
	int base = (1 << 16) - 1;
	if (ex[v] == '&'){
		for (int mask = 0; mask < (1 << 15); mask++){
			swap(dp[l][mask], dp[l][mask ^ base]);
			swap(dp[r][mask], dp[r][mask ^ base]);
		}
	}
	for (int mask = 0; mask < (1 << 16); mask++)
		suml[mask] = dp[l][mask];
	for (int i = 0; i < 16; i++)
		for (int mask = 0; mask < (1 << 16); mask++)
			if (!(mask & (1 << i)))
				ssum(suml[mask ^ (1 << i)], suml[mask]);

	for (int mask = 0; mask < (1 << 16); mask++)
		sumr[mask] = dp[r][mask];
	for (int i = 0; i < 16; i++)
		for (int mask = 0; mask < (1 << 16); mask++)
			if (!(mask & (1 << i)))
				ssum(sumr[mask ^ (1 << i)], sumr[mask]);

	for (int mask = 0; mask < (1 << 16); mask++)
		sum[mask] = 1ll * suml[mask] * sumr[mask] % mod;
	for (int i = 0; i < 16; i++)
		for (int mask = 0; mask < (1 << 16); mask++)
			if (!(mask & (1 << i)))
				sminus(sum[mask ^ (1 << i)], sum[mask]);
	if (ex[v] == '&')
		for (int mask = 0; mask < (1 << 15); mask++)
			swap(sum[mask], sum[mask ^ base]);
}

void dfs(int v){
	if (lchild[v] == -1){
		if (ex[v] == '?'){
			for (int i = 0; i < 4; i++){
				ex[v] = char(int('A') + i);
				cal_leaf(v);
				ex[v] = char(int('a') + i);
				cal_leaf(v);
			}
		}
		else{
			cal_leaf(v);
		}
		return;
	}
	dfs(lchild[v]);
	dfs(rchild[v]);
	if (ex[v] == '?'){
		ex[v] = '|';
		cal_nonleaf(v);
		for (int mask = 0; mask < (1 << 16); mask++)
			ssum(dp[v][mask], sum[mask]);
		ex[v] = '&';
		cal_nonleaf(v);
		for (int mask = 0; mask < (1 << 16); mask++)
			ssum(dp[v][mask], sum[mask]);
	}
	else{
		cal_nonleaf(v);
		for (int mask = 0; mask < (1 << 16); mask++)
			ssum(dp[v][mask], sum[mask]);
	}
}

int req[20];

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	// create binary tree
	int cur = 1, newint = 2;
	lchild[cur] = -1, rchild[cur] = -1;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			if (lchild[cur] == -1){
				lchild[cur] = newint;
				lchild[newint] = rchild[newint] = -1;
				par[newint ++] = cur;
				cur = lchild[cur];
			}
			else{
				rchild[cur] = newint;
				lchild[newint] = rchild[newint] = -1;
				par[newint ++] = cur;
				cur = rchild[cur];
			}
		}
		else if (s[i] == ')'){
			cur = par[cur];
		}
		else{
			ex[cur] = s[i];
		}
	}
	dfs(1);
	int n;
	cin >> n;
	memset(req, -1, sizeof req);
	for (int i = 0; i < n; i++){
		int m = 0;
		for (int j = 0; j < 4; j++){
			int x;
			cin >> x;
			m += (x << j);
		}
		int x;
		cin >> x;
		req[m] = x;
	}
	int mys = 0, myb = 0;
	for (int i = 0; i < 16; i++){
		if (req[i] == -1)
			myb += (1 << i);
		else{
			myb += (req[i] << i);
			mys += (req[i] << i);
		}
	}
	int answer = 0;
	for (int mask = 0; mask < (1 << 16); mask++){
		if ((mask & myb) == mask and (mask & mys) == mys){
			ssum(answer, dp[1][mask]);
		}
	}
	cout << answer << endl;
}