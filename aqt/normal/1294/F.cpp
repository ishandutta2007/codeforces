#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> graph[200005];
int ans, a, b, c;
int dp[3][200005], nd[3][200005];
int lft[200005], rht[200005], t;

void solve1(int n, int p){
	lft[n] = ++t;
	nd[0][n] = n;
	for(int e : graph[n]){
		if(e != p){
			solve1(e, n);
			if(dp[0][n] <= dp[0][e] + 1){
				dp[2][n] = dp[1][n];
				dp[1][n] = dp[0][n];
				dp[0][n] = dp[0][e] + 1;
				nd[2][n] = nd[1][n];
				nd[1][n] = nd[0][n];
				nd[0][n] = nd[0][e];
			}
			else if(dp[1][n] <= dp[0][e] + 1){
				dp[2][n] = dp[1][n];
				dp[1][n] = dp[0][e] + 1;
				nd[2][n] = nd[1][n];				
				nd[1][n] = nd[0][e];
			}
			else if(dp[2][n] <= dp[0][e] + 1){
				dp[2][n] = dp[0][e] + 1;
				nd[2][n] = nd[0][e];
			}
		}
	}
	if(ans <= dp[0][n] + dp[1][n] + dp[2][n]){
		ans = dp[0][n] + dp[1][n] + dp[2][n];
		a = nd[0][n], b = nd[1][n], c = nd[2][n];
	}
	rht[n] = ++t;
}

void solve2(int n, int l, int k, int p){
	if(ans <= l+dp[0][n]+dp[1][n] && k){
		ans = l+dp[0][n]+dp[1][n];
		c = k, a = nd[0][n], b = nd[1][n];
	}
	for(int e : graph[n]){
		if(e != p){
			if(lft[nd[0][n]] >= lft[e] && rht[nd[0][n]] <= rht[e]){
				if(k && l+1 >= dp[1][n] + 1){
					solve2(e, l+1, k, n);
				}
				else{
					solve2(e, dp[1][n]+1, nd[1][n], n);
				}
			}
			else{
				if(k && l+1 >= dp[0][n] + 1){
					solve2(e, l+1, k, n);
				}
				else{
					solve2(e, dp[0][n]+1, nd[0][n], n);
				}
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int rt = (rand()+rand())%N+1;
	solve1(rt, 0);
	solve2(rt, 0, 0, 0);
	if(!a){
		for(int i = 1; i<=N; i++){
			if(i != b && i != c){
				a = i;
				break;
			}
		}
	}
	if(!b){
		for(int i = 1; i<=N; i++){
			if(i != a && i != c){
				b = i;
				break;
			}
		}
	}
	if(!c){
		for(int i = 1; i<=N; i++){
			if(i != a && i != b){
				c = i;
				break;
			}
		}
	}
	//cout << a << " " << b << " " << c << endl;
	assert(a && b && c && a != b && b != c && a != c);
	cout << ans << "\n" << a << " " << b << " " << c << "\n";
}