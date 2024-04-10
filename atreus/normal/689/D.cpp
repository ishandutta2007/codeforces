#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;
const int maxl = 18 + 1;

int RMinQ[maxl][maxn], RMaxQ[maxl][maxn], LMinQ[maxl][maxn], LMaxQ[maxl][maxn];
int a[maxn], b[maxn];

int getB(int L, int R){
	int len = R - L + 1;
	len = log2(len);
	return min(RMinQ[len][L], LMinQ[len][R]);
}

int getA(int L, int R){
	int len = R - L + 1;
	len = log2(len);
	return max(RMaxQ[len][L], LMaxQ[len][R]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++){
		RMaxQ[0][i] = a[i];
		RMinQ[0][i] = b[i];
		LMaxQ[0][i] = a[i];
		LMinQ[0][i] = b[i];
	}
	for (int i = 0; i <= 17; i++){
		for (int j = 1; j + (1 << i) <= n; j++){
			RMaxQ[i + 1][j] = max(RMaxQ[i][j], RMaxQ[i][j + (1 << i)]);
			RMinQ[i + 1][j] = min(RMinQ[i][j], RMinQ[i][j + (1 << i)]);
		}
		for (int j = (1 << i) + 1; j <= n; j++){
			LMaxQ[i + 1][j] = max(LMaxQ[i][j], LMaxQ[i][j - (1 << i)]);
			LMinQ[i + 1][j] = min(LMinQ[i][j], LMinQ[i][j - (1 << i)]);
		}
	}
	ll answer = 0;
	for (int i = 1; i <= n; i++){
		int lef = -1, rig = -1;
		int lo = i - 1, hi = n + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (getA(i, mid) - getB(i, mid) < 0)
				lo = mid;
			else
				hi = mid;
		}
		lef = hi;
		lo = i - 1, hi = n + 1;
		while (hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if (getA(i, mid) - getB(i, mid) <= 0)
				lo = mid;
			else
				hi = mid;
		}
		rig = lo;
		answer += rig - lef + 1;
	}
	cout << answer << endl;
}