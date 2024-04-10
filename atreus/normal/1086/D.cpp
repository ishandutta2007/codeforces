/**
 *    author:  Atrues
 *    created: 28.01.2019 00:57
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 5;
map<char, int> mp;
int n, a[maxn];
int fen[3][maxn];

void add_fen(int idx, int x, int val){
	for (; idx <= n; idx += idx & -idx)
		fen[x][idx] += val;
}

int get_fen(int idx, int x){
	int ret = 0;
	for (; idx; idx -= idx & -idx)
		ret += fen[x][idx];
	return ret;
}

void add(int idx, int x){add_fen(idx, x, +1);}
void del(int idx, int x){add_fen(idx, x, -1);}
int get_sum(int L, int R, int x){return L <= R ? get_fen(R, x) - get_fen(L - 1, x) : 0;}

int first_occ(int x){
	int cur = 0;
	for (int i = 18; i >= 0; i--){
		if (cur + (1 << i) > n)
			continue;
		if (fen[x][cur + (1 << i)] == 0)
			cur += (1 << i);
	}
	return cur + 1;
}

int last_occ(int x){
	int sum = get_sum(1, n, x);
	int cur = 0;
	for (int i = 18; i >= 0; i--){
		if (cur + (1 << i) > n)
			continue;
		if (fen[x][cur + (1 << i)] < sum){
			sum -= fen[x][cur + (1 << i)];
			cur += (1 << i);
		}
	}
	return cur + 1;
}

int solve(int S){
	int P = (S + 1) % 3;
	int R = (S + 2) % 3;
	int numR = get_sum(1, n, R);
	if (numR == 0)
		return get_sum(1, n, S);
	int numP = get_sum(1, n, P);
	if (numP == 0)
		return 0;
	int loR = first_occ(R), hiR = last_occ(R);
	int loP = first_occ(P), hiP = last_occ(P);
	return get_sum(1, n, S) - get_sum(loR, loP, S) - get_sum(hiP, hiR, S);
}

int main(){
	ios_base::sync_with_stdio(false);
	mp['S'] = 0;
	mp['P'] = 1;
	mp['R'] = 2;
	int m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++){
		a[i] = mp[s[i - 1]];
		add(i, a[i]);
	}
	cout << solve(0) + solve(1) + solve(2) << '\n';
	for (int i = 1; i <= m; i++){
		int idx;
		char to;
		cin >> idx >> to;
		int t = mp[to];
		del(idx, a[idx]);
		a[idx] = t;
		add(idx, a[idx]);
		int answer = solve(0) + solve(1) + solve(2);
		cout << answer << '\n';
	}
}