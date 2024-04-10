
// Problem : D. Palindrome XOR
// Contest : Forethought Future Cup - Final Round (Onsite Finalists Only)
// URL : https://codeforces.com/contest/1147/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, C, T;
string s;
int val[2005];
int vis[2005];
int done[2005];
long long MOD = 998244353;

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

bool dfs(int n, int l){
	vis[n] = C;
	done[n] = T;
	bool ret = 1;
	if(n > N){
		if(n == N+l && val[n] == 0){
			//cout << n << "\n";
			ret = 0;
		}
		if(vis[N+l-(n-N)+1] != C){
			val[N+l-(n-N)+1] = val[n];
			ret &= dfs(N+l-(n-N)+1, l);
		}
		if(s[N-(n-N)] != '?' && vis[2*N-n+1] != C){
			val[2*N-n+1] = val[n] ^ (s[N-(n-N)] - '0');
			ret &= dfs(2*N-n+1, l);			
		}
	}
	else{
		if(n <= N-l){
			if(s[n-1] != '?' && s[n-1] - '0' != val[n]){
				//cout << n << "\n";
				ret = 0;
			}
		}
		else if(s[n-1] != '?' && vis[2*N-n+1] != C){
			val[2*N-n+1] = val[n] ^ (s[n-1] - '0');
			ret &= dfs(2*N-n+1, l);
		}
		if(vis[N-n+1] != C){
			val[N-n+1] = val[n];
			ret &= dfs(N-n+1, l);
		}
	}
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	N = s.size();
	long long ans = 0;
	for(int i = 1; i<N; i++){
		long long tot = 1;
		T++;
		for(int j = 1; j<=N+i; j++){
			if(done[j] != T){
				C++;
				int cnt = 0;
				val[j] = 0;
				cnt += dfs(j, i);
				++C;
				//cout << "split\n";
				val[j] = 1;
				cnt += dfs(j, i);
				tot = mult(tot, cnt);
				//cout << j << " " << cnt << "\n";
			} 
		}
		//cout << "take: " << i << " " << tot << "\n";
		ans = add(ans, tot);
	}
	cout << ans << "\n";
}