#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
#define MAXN 300000
int MOD = 1e9 + 7;

vector <vector <long long>> modpow_martix(vector <vector <long long>> a, long long b) {
	int n = a.size();
	vector <vector <long long>> ans(n), zero(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) ans[i].push_back(1);
			else ans[i].push_back(0);
			zero[i].push_back(0);
		}
	}
	for (; b; b >>= 1) {
		if (b & 1) {
			vector <vector <long long>> ans2 = zero;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < n; ++k) {
						ans2[i][j] += (ans[i][k] * a[k][j] % MOD);
						if (ans2[i][j] >= MOD) ans2[i][j] -= MOD;
					}
				}
			}
			swap(ans, ans2);
		}
		vector <vector <long long>> aa = zero;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					aa[i][j] += (a[i][k] * a[k][j] % MOD);
					if (aa[i][j] >= MOD) aa[i][j] -= MOD;
				}
			}
		}
		swap(aa, a);
	}
	return ans;
}

int main () {
	int n = 4;
	lli m;
	cin >> m;
	vector <vector <long long>> ma(n);
	fop (i,0,n) {
                ma[i].resize(n);
                fop (j,0,n) {
                        ma[i][j] = i == j ? 0 : 1;
                }
        }
	vector <vector <long long>> aa = modpow_martix(ma, m);
	cout << aa[0][0] << endl;
}