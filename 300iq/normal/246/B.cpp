#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define INF (int) 1e9 + 7;
#define left left_fenwick
#define right right_fenwick
#define fc first
#define sc second
#define endl '\n'

const int MAXW = 10000 + 7;
const int MAXN = 100 + 7;

int dp[MAXN][MAXW], w[MAXN];


int main() {
	ios_base::sync_with_stdio(0);
	//ifstream cin("sum.in");
	//ofstream cout("sum.out");
	//ifstream cin("period.in");
	//ofstream cout("period.out");
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	int n, x;
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s += x;
	}
	cout << n - (s % n != 0) << endl;
}