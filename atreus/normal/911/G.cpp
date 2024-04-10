#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 2e5 + 10;
int a[maxn], fr[maxn], to[maxn];

struct node{
	int dp[110];
	node(){
		for (int i = 0; i < 110; i++)
			dp[i] = i;
	}
};

node seg[4 * maxn];

void change(int id, int L, int R, int idx, int s, int t){
	if (L + 1 == R){
		seg[id].dp[s] = t;
		return;
	}
	int mid = (L + R) >> 1;
	if (idx < mid)
		change(2 * id + 0, L, mid, idx, s, t);
	else
		change(2 * id + 1, mid, R, idx, s, t);
	for (int i = 1; i <= 100; i++)
		seg[id].dp[i] = seg[2 * id + 1].dp[seg[2 * id + 0].dp[i]];
}

vector<int> vec[2][maxn];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int l, r;
		scanf("%d%d%d%d", &l, &r, &fr[i], &to[i]);
		l --;
		r --;
		vec[0][l].push_back(i);
		vec[1][r].push_back(i);
	}
	for (int i = 0; i < n; i++){
		for (auto idx : vec[0][i])
			change(1, 0, q, idx, fr[idx], to[idx]);
		printf("%d ", seg[1].dp[a[i]]);
		for (auto idx : vec[1][i])
			change(1, 0, q, idx, fr[idx], fr[idx]);
	}
}