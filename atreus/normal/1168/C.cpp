// n log ^ 2 ishalla time nemishe
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 3e5 + 3;

int last[22][22];
int a[maxn], dp[20][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 19;
	memset(last, 63, sizeof last);
	memset(dp, 63, sizeof dp);
	for (int i = n; i >= 1; i--){
		for (int fb = 0; fb < l; fb++)
			for (int sb = 0; sb < l; sb++)
				if (a[i] & (1 << fb) and a[i] & (1 << sb))
					last[fb][sb] = i;
		for (int fb = 0; fb < l; fb++)
			for (int sb = 0; sb < l; sb++)
				if (a[i] & (1 << sb))
					dp[fb][i] = min(dp[fb][i], last[fb][sb]);
		for (int fb = 0; fb < l; fb++)
			for (int sb = 0; sb < l; sb++)
				if (dp[sb][i] <= n)
					dp[fb][i] = min(dp[fb][i], dp[fb][dp[sb][i]]);
	}
	while (q --){
		int x, y;
		cin >> x >> y;
		bool ret = 0;
		for (int i = 0; i < l; i++)
			if (a[y] & (1 << i) and dp[i][x] <= y)
				ret |= 1;
		if (ret == 1)
			cout << "Shi\n";
		else
			cout << "Fou\n";
	}
}