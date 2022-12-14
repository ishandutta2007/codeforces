#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;

const int maxn = (1 << 17) + 10;
const int inf = 1e9;

int a[maxn];

struct node{
	int dp[2][2];
	node(){
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				dp[i][j] = -inf;
	}
};

node f(int L, int R){
	node ret;
	if (L + 2 == R){
		ret.dp[0][0] = 0;
		if (a[L] + a[L+1] > 0)
			ret.dp[0][0] = ret.dp[0][1] = ret.dp[1][0] = 1;
		if (a[L] + a[L+1] > 1)
			ret.dp[1][1] = 1;
		return ret;
	}
	int mid = (L + R) >> 1;
	node A = f(L, mid);
	node B = f(mid, R);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int x = 0; x < 2; x++)
					ret.dp[0][0] = max(ret.dp[0][0], A.dp[i][j] + B.dp[k][x] + (i + k > 0) + (j + x > 0) + (i + k + j + x > 0));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int x = 0; x < 2; x++)
					if (i + k > 0)
						ret.dp[1][0] = max(ret.dp[1][0], A.dp[i][j] + B.dp[k][x] + (i + k > 0) + (j + x > 0) + (i + k + j + x > 1));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int x = 0; x < 2; x++)
					if (i + j + k + x > 0)
						ret.dp[0][1] = max(ret.dp[0][1], A.dp[i][j] + B.dp[k][x] + (i + k > 0) + (j + x > 0) + (i + k + j + x > 0));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int x = 0; x < 2; x++)
					if (i + k > 0 and i + j + k + x > 1)
						ret.dp[1][1] = max(ret.dp[1][1], A.dp[i][j] + B.dp[k][x] + (i + k > 0) + (j + x > 0) + (i + k + j + x > 0));
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++){
		int x;
		cin >> x;
		a[x - 1] = 1;
	}
	if (k == 0)
		return cout << 0 << endl, 0;
	node ans = f(0, (1 << n));
	int ret = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			ret = max(ret, ans.dp[i][j]);
	cout << ret + 1 << '\n';
}