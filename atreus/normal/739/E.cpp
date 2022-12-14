#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int maxn = 5000 + 50;
const int maxm = 1e5 + 50;

int n, a, b;
ld p[maxn], q[maxn], pq[maxn];

struct result{
	ld score;
	int num_a;
	int num_b;
	int num_ab;
	result(ld score_ = 0, int num_a_ = 0, int num_b_ = 0, int num_ab_ = 0){
		score = score_;
		num_a = num_a_;
		num_b = num_b_;
		num_ab = num_ab_;
	}
	void smax(result now){
		if (score < now.score){
			score = now.score;
			num_a = now.num_a;
			num_b = now.num_b;
			num_ab = now.num_ab;
		}
	}
};

result dp[maxn];

result solve(ld x, ld y){
	for (int i = 1; i <= n; i++){
		result bef = dp[i - 1];
		if (p[i] - x == q[i] - y and p[i] - x >= pq[i] - x - y and p[i] - x > 0){
			dp[i] = result(bef.score + p[i] - x, bef.num_a, bef.num_b, bef.num_ab + 1);
			continue;
		}
		// no one
		dp[i] = dp[i - 1];
		// a
		dp[i].smax(result(bef.score + p[i] - x, bef.num_a + 1, bef.num_b + 0, bef.num_ab));
		// b
		dp[i].smax(result(bef.score + q[i] - y, bef.num_a + 0, bef.num_b + 1, bef.num_ab));
		// a & b
		dp[i].smax(result(bef.score + pq[i] - x - y, bef.num_a + 1, bef.num_b + 1, bef.num_ab));
	
		result me = dp[i];	
	}
	dp[n].score += x * a + y * b;
	return dp[n];
}

result solve_a(ld x){
	ld lo = 0, hi = 1;
	int bs = 80;
	while (bs --){
		ld mid = .5 * (lo + hi);
		result me = solve(x, mid);	
		if (me.num_b > b)
			lo = mid;
		else
			hi = mid;
	}
	return solve(x, hi);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	for (int i = 1; i <= n; i++)
		cin >> q[i];
	for (int i = 1; i <= n; i++)
		pq[i] = (1. - (1. - p[i]) * (1. - q[i]));
	ld lo = 0, hi = 1;
	int bs = 80; 
	while (bs --){
		ld mid = .5 * (lo + hi);
		result me = solve_a(mid);
		int tmp = max(0, me.num_ab - (b - me.num_b));
		if (me.num_a + tmp > a)
			lo = mid;
		else
			hi = mid;
	}
	cout << fixed << setprecision(6) << solve_a(hi).score << endl;
}