#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;

const int maxn = 250 + 10;
const int inf = 1e8;

int n, dp[maxn][maxn][maxn], nex[30][100000 + 10];
string reg[4];

void update(int fi, int se, int th){
	dp[fi][se][th] = inf;
	if (fi > 0 and dp[fi - 1][se][th] <= n){
		int idx = dp[fi - 1][se][th];
		int k = (int)(reg[1][fi - 1] - 'a');
		int badi = nex[k][idx + 1];
		if (badi != -1)
			dp[fi][se][th] = min(dp[fi][se][th], badi);
	}

	if (se > 0 and dp[fi][se - 1][th] <= n){
		int idx = dp[fi][se - 1][th];
		int k = (int)(reg[2][se - 1] - 'a');
		int badi = nex[k][idx + 1];
		if (badi != -1)
			dp[fi][se][th] = min(dp[fi][se][th], badi);
	}
	if (th > 0 and dp[fi][se][th - 1] <= n){
		int idx = dp[fi][se][th - 1];
		int k = (int)(reg[3][th - 1] - 'a');
		int badi = nex[k][idx + 1];
		if (badi != -1)
			dp[fi][se][th] = min(dp[fi][se][th], badi);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int q;
	cin >> n >> q;
	string s;
	cin >> s;
	memset(nex, -1, sizeof nex);
	for (int i = 0; i < 26; i++){
		int last = -1;
		for (int j = n; j >= 1; j--){
			if ((int)(s[j - 1] - 'a') == i)
				last = j;
			nex[i][j] = last;
		}
	}
	memset(dp, 63, sizeof dp);
	dp[0][0][0] = 0;
	while (q --){
		char type;
		cin >> type;
		if (type == '+'){
			int t;
			char x;
			cin >> t >> x;
			reg[t] += x;
			int k = (int)(x - 'a');
			if (t == 1)
				for (int i = 0; i <= reg[2].size(); i++)
					for (int j = 0; j <= reg[3].size(); j++)
						update(reg[1].size(), i, j);
			if (t == 2)
				for (int i = 0; i <= reg[1].size(); i++)
					for (int j = 0; j <= reg[3].size(); j++)
						update(i, reg[2].size(), j);
			if (t == 3)
				for (int i = 0; i <= reg[1].size(); i++)
					for (int j = 0; j <= reg[2].size(); j++)
						update(i, j, reg[3].size());
		}
		else{
			int t;
			cin >> t;
			reg[t].pop_back();
		}
		if (dp[reg[1].size()][reg[2].size()][reg[3].size()] > s.size())
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}