#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 30 + 10;
const int maxN = 1e5 + 10;

int n, p[maxn];
string s[maxn];
int dp[150][10], pd[150][10];
int a[150][270];
int adj[10];
ll ans[maxN];

void solve1(int mask){
	vector<int> A;
	for (int i = 0; i < n; i++)
		if (mask & (1 << i))
			A.push_back(i);
	int m = A.size();
	for (int i = 0; i < m; i++)
		p[i] = i;
	memset(dp, 0, sizeof dp);
	do{
		int mask = 0;
		for (int i = 0; i < m-1; i++)
			if (s[A[p[i]]][A[p[i+1]]] == '1')
				mask |= (1 << i);
		dp[mask][p[m-1]] ++;
	}while(next_permutation(p, p + m));
}

void solve2(int mask){
	vector<int> A;
	for (int i = 0; i < n; i++)
		if (mask & (1 << i))
			A.push_back(i);
	int m = A.size();
	for (int i = 0; i < m; i++)
		p[i] = i;
	memset(pd, 0, sizeof dp);
	do{
		int mask = 0;
		for (int i = 0; i < m-1; i++)
			if (s[A[p[i]]][A[p[i+1]]] == '1')
				mask |= (1 << i);
		pd[mask][p[0]] ++;
	}while(next_permutation(p, p + m));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int m1 = n/2;
	int m2 = n-m1;
	vector<int> subsets;
	for (int mask = 0; mask < (1 << n); mask++)
		if (__builtin_popcount(mask) == m1)
			subsets.push_back(mask);
	int tot = (1<<n)-1;
	for (int tc = 0; tc < (int)subsets.size(); tc++){
		solve1(subsets[tc]);
		solve2(subsets[tc]^tot);
		vector<int> A, B;
		for (int j = 0; j < n; j++){
			if (subsets[tc] & (1 << j))
				A.push_back(j);
			else	
				B.push_back(j);
		}
		for (int i = 0; i < m1; i++){
			adj[i] = 0;
			for (int j = 0; j < m2; j++)
				if (s[A[i]][B[j]] == '1')
					adj[i] |= (1 << j);
		}

		for (int q = 0; q < (1 << (m2-1)); q++){
			for (int p = 0; p < (1 << m2); p++){
				a[q][p] = 0;
				for (int i = 0; i < m2; i++)
					if (p & (1 << i))
						a[q][p] += pd[q][i];
			}
		}
		
		for (int part1 = 0; part1 < (1 << (m1-1)); part1++){
			for (int part2 = 0; part2 < (1 << (m2-1)); part2++){
				int mask = part1 + (part2 << m1);
				for (int i = 0; i < m1; i++){
					ans[mask | (1 << (m1-1))] += 1ll * dp[part1][i] * a[part2][adj[i]];
					ans[mask] += 1ll * dp[part1][i] * a[part2][((1<<m2)-1)^adj[i]];
				}
			}
		}
	}
	for (int mask = 0; mask < (1 << (n-1)); mask++)
		cout << ans[mask] << " ";
	cout << '\n';
}